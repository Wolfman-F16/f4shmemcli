/*
 * serial.h
 *
 *  (c) 2003 www.winapi.net
 *
 */

#ifndef FALCON_SERIAL_H
#define FALCON_SERIAL_H

#include <windows.h>
#include "Log.h"

class CSerial
{

public:
  // -----------------------------------------------------------
  //  Constructors and destructors
  // -----------------------------------------------------------
  CSerial();
  ~CSerial();

  // -----------------------------------------------------------
  //  members
  // -----------------------------------------------------------

  // -----------------------------------------------------------
  //  methods
  // -----------------------------------------------------------
  BOOL open    (int, int, int, int, int);
  BOOL close   (void);
  BOOL modeSet (int, int, int, int);

  int readData (char*);
  int sendData (const unsigned char*, int);  // write string
  BOOL writeSingleByte (unsigned char);  // write single character


private:
  // -----------------------------------------------------------
  //  members
  // -----------------------------------------------------------
  HANDLE hComm; // Handle for access
  DCB dcb_alt; // stores old parameters
  COMMTIMEOUTS timeouts_alt; // stores old timeout parameters

};

#endif  // FALCON_SERIAL_H
