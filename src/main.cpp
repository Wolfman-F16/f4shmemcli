/*
 * main.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: wolfgang
 */

#include <cstdlib>
#include <cstdio>
#include <cstdint> /* should be inttypes */
#include "ErrorCodes.h"
#include "Application.h"
#include "AppSerial.h"
#include "SwTimer.h"


// global variables
CApplication m_pAppFalcon;
CAppSerial m_pAppSerial;
unsigned int Falcon4::TIMEOUT_VALUE = 25; // init refresh rate [ms]

/**
 writes data to serial data buffer (cData)
 */
int sendData() {
  uint32_t errorCode = ERROR_OK;
  uint32_t chan;
  uint32_t freq;

  chan = m_pAppFalcon.m_pFalconSMR->getBupUhfChan();
  freq = m_pAppFalcon.m_pFalconSMR->getBupUhfFreq();

  errorCode = m_pAppSerial.sendData(freq, chan);
  if (errorCode != ERROR_OK) {
    return errorCode;
  }

  return ERROR_OK;
}

/*
 * main
 */
int main(int argc, char **argv) {
  int retVal;

  printf("Falcon 4.0 / BMS 4.33 Shared Memory Reader\n\rARC-164 UHF Radio - %s %s\n\r", __DATE__,
      __TIME__);
  if(m_pAppSerial.setup() != TRUE) {
    Log::getInstance()->error("setup failed\n");
    return ERROR_CONFIG;
  }
  if (m_pAppFalcon.InitInstance() != TRUE) {
    Log::getInstance()->debug("could not initialize application\n");
    return ERROR_DATA;
  }

  printf("transmitting @%dms ...\n",Falcon4::TIMEOUT_VALUE);

  while (1) {
    Sleep(Falcon4::TIMEOUT_VALUE); /* sleep 100 ms */

    m_pAppFalcon.swTimer.updateTime();

    retVal = sendData();
    if (retVal) {
      printf("\rError: %d\r", retVal);
      /* don't want to quit just bc. data is invalid */
    } else {
      printf("\r           ");
    }
  }
}
