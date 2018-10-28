/*
 * AppSerial.h
 *
 *  Created on: 28.11.2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#ifndef APPSERIAL_H_
#define APPSERIAL_H_

#include "Application.h"
#include "Serial.h"
#include "ConfigData.h"

class CAppSerial {
public:
  CAppSerial();
  virtual ~CAppSerial();

  int setup();
  int sendData(const unsigned char*, unsigned int);
  int flush();

private:
  CSerial *m_pSerialComm;
};


#endif /* APPSERIAL_H_ */
