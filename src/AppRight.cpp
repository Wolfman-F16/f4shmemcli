#include "Application.h"

// ############################################################################
// ###                             RIGHT CONSOLE                            ###
// ############################################################################
/*
 fills send buffer with data for center console

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::prepareRightConsole(FalconSMR *m_pFalconSMR,
    unsigned int &iIndex, bool bShowRealtime, bool bPowerOff) {
  unsigned int initialIndexValue = iIndex;

  getFaultLights(m_pFalconSMR, iIndex); // 5
  getPfl(m_pFalconSMR, iIndex, bPowerOff); // 91
  getEpuFuel(m_pFalconSMR, iIndex); // 3
  getCompass(m_pFalconSMR, iIndex); // 3
  getFuel(m_pFalconSMR, iIndex); // 6
  getCabinPressure(m_pFalconSMR, iIndex); // 2
  getClock(m_pFalconSMR, iIndex, bShowRealtime); // 4

  if ((iIndex - initialIndexValue) != 114) // const 114 byte
  {
    return ((iIndex - initialIndexValue) * -1);
  }

  return ERROR_OK;
}

// ***********************    Fault Lights       ***********************
/* 
 gets Fault lights data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getFaultLights(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;

  m_pFalconSMR->cData[iIndex++] = ID_FAULT_LIGHTS; //message type FAULT_LIGHTS

  if (m_pFalconSMR->getNwsFail()) // first byte
  {
    ucTemp |= 0x01;
  }
  /* no support by AF */
  if (m_pFalconSMR->getEquipHot())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getSecOn())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getElectricFailure())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getSeatArmingFault())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getAvionicsFault())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getEngineFault()) // TODO check eyebrow correlation
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;

  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00; // reset ucTemp

  if (m_pFalconSMR->getFltCntrlSysFault()) // second byte
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getEcmFault())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getCabinPressureFault()) // check for correct source
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getOxygenLow())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getOverheat())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getConfigurationFault())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;

  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00; // reset ucTemp

  if (m_pFalconSMR->getIffFault())
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getHookFault())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getCadcFault())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getAntiSkidFault())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getRadarAltimeterFault())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getFuelOilHot())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getProbeHeatOn()) // third byte
  {
    if (getBlink(FlightDataBMS::PROBEHEAT, FREQ_4HZ))
    {
      ucTemp |= 0x40;
    }
  }
  /* stuffing bit */
  ucTemp |= 0x80;

  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00; // reset ucTemp

  /* no support by AF
   if(m_pFalconSMR->getAtfNotEngaged())
   {
   ucTemp |= 0x02;
   } */
  if (m_pFalconSMR->getAftFuelLow())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getDualFault()) // check for correct source
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getBuc())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getFwdFuelLow())
  {
    ucTemp |= 0x40;
  }

  /* stuffing bit */
  ucTemp |= 0x80;

  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return ERROR_OK;
}

// ***********************       PFL         ***********************
/* 
 gets Pilot Fault List data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getPfl(FalconSMR *m_pFalconSMR, unsigned int &iIndex,
    bool bPowerOff) {
  int iComBuffer = 0;
  unsigned int i = 0;

  m_pFalconSMR->cData[iIndex++] = ID_PFL; //message type PFL

  if (bPowerOff)
  {
    for (i = 0; i < 90; i++)
    {
      m_pFalconSMR->cData[iIndex++] = 0x20;
    }
    return ERROR_OK;
  }
  // PFL needs cdata of 91 byte incl init byte
  for (i = 0; i < PFL_MAX_LINES; i++)
  {
    char* cLine = new char[PFL_LINE_LENGTH + 1];
    strncpy(cLine, m_pFalconSMR->getPfl(i), PFL_LINE_LENGTH);
    cLine[PFL_LINE_LENGTH + 1] = TERMINATOR; // DO NOT REMOVE THIS LINE

    for (int k = PFL_LINE_INDENT; k < 22; k++)
    {
      iComBuffer++;
      m_pFalconSMR->cData[iIndex++] = cLine[k];
    }
    delete cLine;
  }

  return ERROR_OK;
}

// ***********************      EPU Fuel       ***********************
/* 
 gets EPU Fuel data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getEpuFuel(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_EPU_FUEL; //message type EPU_FUEL

  /*
   convert to needle angle
   0 - 100 %	>	0 - 218.5 degrees
   y = mx + t
   m = 2.185
   t = 0
   */
  iTemp = (unsigned short) (m_pFalconSMR->getEpuFuel() * 2.185);
  // split in high and low byte
  ucTemp = (iTemp & 0x007F);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  // high byte
  ucTemp = (byte) ((iTemp & 0x3F80) >> 7);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return ERROR_OK;
}

// ***********************       Compass       ***********************
/* 
 gets Compass data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getCompass(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_COMPASS; //message type COMPASS

  iTemp = (unsigned short) m_pFalconSMR->getCurrentHeading();
  // split in high and low byte
  ucTemp = (iTemp & 0x007F);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  // high byte
  ucTemp = (byte) ((iTemp & 0x3F80) >> 7);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return ERROR_OK;
}

// ***********************       Fuel         ***********************
/* 
 gets Fuel data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getFuel(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_FUEL; //message type FUEL

  iTemp = (unsigned short) m_pFalconSMR->getAftFuel();
  ucTemp = iTemp & 0x007F;
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = (byte) ((iTemp & 0x0180) >> 7);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex] = ucTemp;

  iTemp = (unsigned short) m_pFalconSMR->getFwdFuel();
  ucTemp = (byte) ((iTemp & 0x0007) << 4);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] |= ucTemp;
  ucTemp = (byte) ((iTemp & 0x01F8) >> 3);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  // total fuel for drum counters
  iTemp = (unsigned short) m_pFalconSMR->getTotalFuel();
  ucTemp = iTemp & 0x007F;
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = (byte) ((iTemp & 0x3F80) >> 3);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return ERROR_OK;
}

// ***********************    Cabin Pressure    ***********************
/* 
 gets Cabin Pressure data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getCabinPressure(FalconSMR *m_pFalconSMR,
    unsigned int &iIndex) {
  m_pFalconSMR->cData[iIndex++] = ID_CABIN_PRESSURE; //message type CABIN_PRESSURE

  // as long as there is no analogue cabinpressure value....
  if (m_pFalconSMR->getCabinPressureFault())
  {
    m_pFalconSMR->cData[iIndex++] = 0x81; // includes stuffing bit
  } else
  {
    m_pFalconSMR->cData[iIndex++] = 0x80; // includes stuffing bit
  }

  return ERROR_OK;
}

// ***********************      Clock      ***********************
/* 
 gets Clock data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getClock(FalconSMR *m_pFalconSMR, unsigned int &iIndex,
    bool bShowRealtime) {
  m_pFalconSMR->cData[iIndex++] = ID_CLOCK; //message type CLOCK

  StructClock strClock;
  if (bShowRealtime)
  {
    strClock = m_pFalconSMR->getRealtimeClock();
  } else
  {
    strClock = m_pFalconSMR->getClock();
    // validation and denial of transmission, since value is only available on default DED page
    if (strClock.cHours < 0 || strClock.cHours > 12)
    {
      strClock.cHours = 0x0F; // 0x0F indicates invalid flag. use uC internal clock
      strClock.cMinutes = 0;
      strClock.cSeconds = 0;
    }

  }
  m_pFalconSMR->cData[iIndex++] = (strClock.cSeconds & 0x3F) | 0x80;
  m_pFalconSMR->cData[iIndex++] = (strClock.cMinutes & 0x3F) | 0x80;
  m_pFalconSMR->cData[iIndex] = (strClock.cHours & 0x0F) | 0x80;
  if (bShowRealtime)
  {
    m_pFalconSMR->cData[iIndex] |= 0x10;
  }
  iIndex++;

  return ERROR_OK;
}
