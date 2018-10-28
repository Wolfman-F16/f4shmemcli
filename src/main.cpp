/*
 * main.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: wolfgang
 */

#include "ErrorCodes.h"
#include "Application.h"
#include "AppSerial.h"
#include "SwTimer.h"
#include <cstdlib>
#include <cstdio>

// global variables
CApplication m_pAppFalcon;
CAppSerial m_pAppSerial;
unsigned int Falcon4::TIMEOUT_VALUE = 20; // init refresh rate [ms]

/**
 writes data to serial data buffer (cData)
 */
int sendData() {
  int errorCode = ERROR_OK;
  int bytesSent;
  bool bShowRealtime = false;
  static int cClockToggle = 1; // init toggle value
  static int dbgCtr = 0;
  unsigned int iLength = 0;

  if (cClockToggle < 0) {
    bShowRealtime = true;
  }
  errorCode = m_pAppFalcon.prepareData(&(m_pAppFalcon.m_pFalconSMR->cData[0]), &iLength, bShowRealtime);
  if (errorCode != ERROR_OK) {
    return errorCode;
  }
  bytesSent = m_pAppSerial.sendData(&(m_pAppFalcon.m_pFalconSMR->cData[0]), iLength);

printf("%d\t%d\t0x%x 0x%x 0x%x 0x%x\t%d\r",iLength, bytesSent, m_pAppFalcon.m_pFalconSMR->cData[0], 
m_pAppFalcon.m_pFalconSMR->cData[1],
m_pAppFalcon.m_pFalconSMR->cData[2],
m_pAppFalcon.m_pFalconSMR->cData[3], dbgCtr++);
  cClockToggle *= -1;

  return ERROR_OK;
}

/*
 * main
 */
int main(int argc, char **argv) {
  int retVal;

  printf("Falcon 4.0 / BMS 4.33 Shared Memory Reader %s %s\n\r", __DATE__,
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
    Sleep(Falcon4::TIMEOUT_VALUE +3); /* sleep 100 ms */

    m_pAppFalcon.swTimer.updateTime();

    retVal = sendData();
    if (retVal) {
      printf("\rError: %d\r", retVal);
      /* don't want to quit just bc. data is invalid */
    } else {
      printf("           ");
    }
  }
}
