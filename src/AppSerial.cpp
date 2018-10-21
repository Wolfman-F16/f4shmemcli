/*
 * AppSerial.cpp
 *
 *  Created on: 28.11.2015
 *      Author: Engelhard
 */
#include <AppSerial.h>

CAppSerial::CAppSerial() {
  devUhfRadio = NULL;
}

CAppSerial::~CAppSerial() {
  usb_close(devUhfRadio);
}

int CAppSerial::setup() {
  int bResult = -1;
  char charBuffer[50];
  // init logging
  Log::getInstance()->setFilter(DEBUG_LEVEL);
  Log::getInstance()->setLogger("falcon4.log.txt");

  devUhfRadio = openUsbDevice(VENDOR_ID, PRODUCT_ID, PRODUCT_NAME);;


  if (!devUhfRadio) {
    Log::getInstance()->error("Failed to open USB device\n");
    return FALSE;
  } else {
    printf("Established connection to UHF-Radio\n");
  }

  return TRUE;
}

int CAppSerial::sendData(const uint32_t freq, uint32_t chan) {
  int iRetVal = -1;
  uint16_t value[2];

  if(devUhfRadio) {
    if(convert(value, freq, chan)) {
      Log::getInstance()->error("converting input data failed\n");
    } else {
      sendData(devUhfRadio,USB_DATA_TX, value);
    }
  }
  return iRetVal;
}
