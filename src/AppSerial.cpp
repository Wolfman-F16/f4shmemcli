/*
 * AppSerial.cpp
 *
 *  Created on: 28.11.2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#include "AppSerial.h"

CAppSerial::CAppSerial() {
  m_pSerialComm = NULL;
}

CAppSerial::~CAppSerial() {
  delete m_pSerialComm;
}

int CAppSerial::setup() {
  int bResult = -1;
  char charBuffer[50];
  // init logging
  Log::getInstance()->setFilter(DEBUG_LEVEL);
  Log::getInstance()->setLogger("falcon4.log.txt");

  // load config file
  CConfigData *pConfig = new CConfigData;

  // init communications
  m_pSerialComm = new CSerial;
  bResult = m_pSerialComm->open(pConfig->getComPort(), pConfig->getBaudRate(),
      pConfig->getBits(), pConfig->getStopBit(), pConfig->getParity());

  // calculate new refresh value, based on baud rate
  TIMEOUT_VALUE = (((FRAME_LENGTH + RWR_SIZE) * 9000) / pConfig->getBaudRate())
      + 2;
  //                bits incl. stop bit and in ms                        2ms extra
  // release resources
  delete pConfig;

  if (!bResult) {
    Log::getInstance()->error("Failed to open COM port\n");
    return FALSE;
  } else {
    printf("serial connection established with %d ms\n", TIMEOUT_VALUE);
  }

  if(m_pSerialComm->writeSingleByte('\0') != TRUE){
    return FALSE;
  }

  sprintf(charBuffer, "%c%c%cNo connection.", SOF1, SOF2, ID_PFL);
  m_pSerialComm->sendData((unsigned char*) charBuffer, 18);
  return TRUE;
}

int CAppSerial::sendData(const unsigned char* cData, unsigned int iLength) {
  int iRetVal = -1;
  if(m_pSerialComm) {
    iRetVal = m_pSerialComm->sendData(cData, iLength);
  }
  return iRetVal;
}
