/*
 * AppSerial.h
 *
 *  Created on: 28.11.2015
 *      Author: Engelhard
 */

#ifndef APPSERIAL_H_
#define APPSERIAL_H_

#include "Application.h"
#include "uhfRadio.h"
#include "usb.h"

class CAppSerial {
public:
  CAppSerial();
  virtual ~CAppSerial();

  int setup();
  int sendData(uin32_t , uint32_t );

private:
  usb_dev_handle *devUhfRadio = 0;

};


#endif /* APPSERIAL_H_ */
