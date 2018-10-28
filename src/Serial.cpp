/*
 * serial.cpp
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#include "Serial.h"

/**
constructor, setting hComm to INVALID_HANDLE_VALUE
*/
CSerial::CSerial() : hComm(INVALID_HANDLE_VALUE)
{
}

/**
destructor. closes connection.
*/
CSerial::~CSerial()
{
  close();
}

/**
sets mode. allows change of baud, bit number, stopp bits and parity at runtime.
\param[in] nBaud baudrate
\param[in] nBits number of bits
\param[in] nStopp number of stopp bits
\param[in] nParity parity bit
\retVal  TRUE if successful
\retVal FALSE if exception occurred
*/
BOOL CSerial::modeSet(int nBaud, int nBits, int nStopp, int nParity)
{
  DCB dcb; // create struct of type DCB

  // logging
  char *sLogMessage = new char[255];
  sprintf(sLogMessage,"Changing RS232 mode to Baud:%d, Bits:%d, StopBit:%d, Parity:%d\n", nBaud
          , nBits
          , nStopp
          , nParity);
  Log::getInstance()->debug(sLogMessage);
  delete sLogMessage;

  if (hComm == INVALID_HANDLE_VALUE)  // COM-Port open?
  {
    return FALSE;
  }

  ZeroMemory (&dcb, sizeof(dcb)); // important! zeroize memory in dcb

  // fetch parameters, otherwise program flow terminates here
  if (!GetCommState(hComm, &dcb))
  {
    close();
    // text should be put i18n style
    MessageBox(NULL
               , "Error changing COM-Port parameters\nGetCommState()"
               , NULL
               , MB_OK);
    return FALSE;
  }

  // neue Parameter in die Struktur kopieren (Baud: z.B. 9600)
  dcb.BaudRate = nBaud;
  // neue Parameter in die Struktur kopieren (Bits: z.B. 7 oder 8)
  dcb.ByteSize = (BYTE)nBits;
  // neue Parameter in die Struktur kopieren (Parit�t:(siehe MSDN))
  dcb.Parity   = (BYTE)nParity;
  // Anzahl Stoppbits (siehe MSDN)
  dcb.StopBits = (BYTE)nStopp;

  // neue Parameter setzen. Bei Fehler ist hier Schluss!
  if (!SetCommState(hComm, &dcb))
  {
    close();
    // text should be put i18n style
    MessageBox(NULL
               , "Error changing COM-Port parameters\nSetCommState()"
               , NULL
               , MB_OK);
    return FALSE;
  }

  return TRUE; // done
}

/**
opens serial connection.
\param[in] nBaud baudrate
\param[in] nBits number of bits
\param[in] nStopp number of stopp bits
\param[in] nParity parity bit
\retVal TRUE if successful
\retVal FALSE if exception occurred
*/
BOOL CSerial::open(int nPort, int nBaud, int nBits, int nStopp, int nParity)
{
  char *sLogMessage = new char[255];
  char szPort[15];
  COMMTIMEOUTS timeouts;
  DCB dcb;

  // logging
  sprintf(sLogMessage,"RS232 Port:%d, Baud:%d, Bits:%d, StopBit:%d, Parity:%d\n", nPort
          , nBaud
          , nBits
          , nStopp
          , nParity);
  Log::getInstance()->debug(sLogMessage);
  delete sLogMessage;
  sLogMessage = NULL;

  if (hComm != INVALID_HANDLE_VALUE) // COM-Port open?
  {
    return TRUE; // since port is already open, TRUE is returned
  }

  // create com port identifier to use as CreateFile parameter
  wsprintf (szPort, "\\\\.\\COM%d", nPort);

  hComm = CreateFile(  szPort, // open COM-Port
                      GENERIC_READ | GENERIC_WRITE, // read, write access
                      0,
                      0,
                      OPEN_EXISTING,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL); // not OVERLAPPED, port is used exclusively

  if (hComm == INVALID_HANDLE_VALUE) // got a handle ? terminate in case of error!
  {
    MessageBox(NULL, "Error opening COM-Ports!\nCreateFile()", NULL, MB_OK);
    return FALSE;
  }
  PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);

  // save old timeout values. terminate in case of error
  if (!GetCommTimeouts(hComm, &timeouts_alt))
  {
    close();
    MessageBox(NULL
               , "Error opening COM-Ports!\nGetCommTimeouts()"
               , NULL
               , MB_OK);
    return FALSE;
  }

  // create a struct of type COMMTIMEOUTS and set new timeouts
  timeouts.ReadIntervalTimeout         = 200;
  timeouts.ReadTotalTimeoutMultiplier  = 200;
  timeouts.ReadTotalTimeoutConstant    = 200;
  timeouts.WriteTotalTimeoutMultiplier = 200;
  timeouts.WriteTotalTimeoutConstant   = 200;

  if (!SetCommTimeouts(hComm, &timeouts))
  {
    close();
    MessageBox(NULL
               , "Error opening COM-Ports!\nSetCommTimeouts()"
               , NULL
               , MB_OK);
    return FALSE;
  }

  ZeroMemory (&dcb, sizeof(dcb)); // important! zeroize memory in dcb
  // read current values. terminate in case of error
  if (!GetCommState (hComm, &dcb))
  {
    close ();
    MessageBox(NULL
               , "Error opening COM-Ports!\nGetCommState()"
               , NULL
               , MB_OK);
    return FALSE;
  } else {
    printf("Old RS232 settings Port:%d, Baud:%d, Bits:%d, StopBit:%d, Parity:%d\n", nPort
              , dcb.BaudRate
              , dcb.ByteSize
              , dcb.StopBits
              , dcb.Parity);
  }

  dcb_alt = dcb; // save old values

  dcb.DCBlength         = sizeof(DCB);
  dcb.fBinary           = TRUE; // must always be "TRUE"!
  dcb.fParity           = TRUE;
  dcb.fOutxCtsFlow      = FALSE;
  dcb.fOutxDsrFlow      = FALSE;
  dcb.fDtrControl       = DTR_CONTROL_ENABLE;
  dcb.fDsrSensitivity   = FALSE;
  dcb.fTXContinueOnXoff = TRUE;
  dcb.fOutX             = FALSE;
  dcb.fInX              = FALSE;
  dcb.fErrorChar        = FALSE;
  dcb.fNull             = FALSE;
  dcb.fRtsControl       = RTS_CONTROL_ENABLE;
  dcb.fAbortOnError     = FALSE;
  dcb.wReserved         = 0; // must always be 0

  // copy new parameter into structure (Baud: e.g. 9600)
  dcb.BaudRate = nBaud;
  // copy new parameter into structure (Bits: e.g. 7 or 8)
  dcb.ByteSize = (BYTE)nBits;
  // copy new parameter into structure (Parity:(see MSDN))
  dcb.Parity   = (BYTE)nParity;
  dcb.fParity = (dcb.Parity != NOPARITY);

  // number of stoppbits (see MSDN)
 // dcb.StopBits = (BYTE)nStopp;

  // set new parameter. terminate in case of error!
  if (!SetCommState (hComm, &dcb))
  {
    close();
    MessageBox(NULL
               , "Error setting COM-Port parameters\nSetCommState()"
               , NULL
               , MB_OK);
    return FALSE;
  }
  Sleep(60); /* allow new values to settle */
  return TRUE;
}

/**
closes serial connection
\retVal TRUE if successful
\retVal FALSE if exception occurred
*/
BOOL CSerial::close(void)
{
  if (hComm != INVALID_HANDLE_VALUE) // COM-Port open?
  {
    return FALSE;
  }

  if (!SetCommTimeouts(hComm, &timeouts_alt))
  {
    MessageBox(NULL
               , "Error closing COM-Port\nSetCommTimeouts()"
               , NULL
               , MB_OK);
    return FALSE;
  }

  // write back old parameters. terminate in case of error!
  if (!SetCommState(hComm, &dcb_alt))
  {
    MessageBox(NULL
               , "Error closing COM-Port\nSetCommState()"
               , NULL
               , MB_OK);
    return FALSE;
  }

  CloseHandle(hComm); // close port
  hComm = INVALID_HANDLE_VALUE; // reset handle

  return TRUE;
}

/**
writes a byte
\param[in] ucByte single byte to transmit
\retVal TRUE if successful
\retVal FALSE if exception occurred
*/
BOOL CSerial::writeSingleByte(unsigned char ucByte) // Byte to transmit (ucByte)
{
  if (hComm != INVALID_HANDLE_VALUE) // COM-Port open?
  {
    // directly transmit char, in case of error terminate
    if (TransmitCommChar(hComm, ucByte) != 0)
    {
      return TRUE;
    }
    else
    {
      MessageBox(NULL
                 , "Error transmitting single byte on COM-Port!\nTransmitCommChar()"
                 , NULL
                 , MB_OK);
    }
  }
  return FALSE;
}

/**
writes a byte array
\param[in] sBuffer string to send
\param[in] iBytesToWrite
\return 0 if something went wrong, else number of bytes sent
*/
int CSerial::sendData(const unsigned char *sBuffer, int iBytesToWrite)
{
  DWORD dwBytesWritten = 0;
  if (hComm != INVALID_HANDLE_VALUE) // COM-Port open?
  {
    // write specified number of bytes to COM-Port
    WriteFile(hComm, sBuffer, iBytesToWrite, &dwBytesWritten, NULL);
  }

  return (int)dwBytesWritten; // return number of transmitted bytes
}

/**
reads a byte buffer
\param[in] sBuffer
\return number of received bytes
*/
int CSerial::readData(char *sBuffer)
{
  DWORD dwRead = 0;
  char chRead;
  int i = 0;

  if (hComm != INVALID_HANDLE_VALUE) // COM-Port open?
  {
    while (ReadFile(hComm, &chRead, 1, &dwRead, NULL)) // byte received ?
    {
      if (dwRead != 1) // no? then terminate
      {
        break;
      }
      // FIXME how is max buffer size checked?
      sBuffer[i++] = chRead; // yes? write byte to buffer
    }
  }

  return i;
}

