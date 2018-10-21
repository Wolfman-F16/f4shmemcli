#include "Application.h"

// ############################################################################
// ###                            CENTER CONSOLE                            ###
// ############################################################################
/*
 fills send buffer with data for center console

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::prepareCenterConsole(FalconSMR *m_pFalconSMR,
                                       unsigned int &iIndex,
                                       bool bPowerOff) {
  unsigned int initialIndexValue = iIndex;

  if (getCenterConsoleIndication(m_pFalconSMR, iIndex))
  {
    return 1;
  } // Index 5
  if (getAirspeed(m_pFalconSMR, iIndex))
  {
    return 2;
  } // 4
  if (getAltimeter(m_pFalconSMR, iIndex))
  {
    return 3;
  } // 5
  if (getAoa(m_pFalconSMR, iIndex))
  {
    return 4;
  } // 2
  if (getAdi(m_pFalconSMR, iIndex))
  {
    return 5;
  } // 5
  if (getVvi(m_pFalconSMR, iIndex))
  {
    return 6;
  } // 2
  if (getHsi(m_pFalconSMR, iIndex))
  {
    return 7;
  } // 9
  if (getDed(m_pFalconSMR, iIndex, bPowerOff))
  {
    return 8;
  } // 126
  if (getFuelFlow(m_pFalconSMR, iIndex))
  {
    return 9;
  } // 3
  if (getOilPressure(m_pFalconSMR, iIndex))
  {
    return 10;
  } // 2
  if (getNozzlePos(m_pFalconSMR, iIndex))
  {
    return 11;
  } // 2
  if (getRpm(m_pFalconSMR, iIndex))
  {
    return 12;
  } // 2
  if (getFtit(m_pFalconSMR, iIndex))
  {
    return 13;
  } // 2

  if ((iIndex - initialIndexValue) != 169) // const 169 byte
  {
    return ((iIndex - initialIndexValue) * -1);
  }

  if (getRwr(m_pFalconSMR, iIndex))
  {
    return 14;
  } // max 33

  if ((iIndex - initialIndexValue) > 202) // max 202 byte
  {
    return ((iIndex - initialIndexValue) * -1);
  }
  return ERROR_OK;
}

// ***********************      Eyebrow, Indexer lights      **************
/*
 gets Threat Warning Prima, Misc Panel lights data
 gets eyebrow and indexer light data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getCenterConsoleIndication(FalconSMR *m_pFalconSMR,
                                             unsigned int &iIndex) {
  byte ucTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_EYEBROW_INDEXER; //message type EYEBROW_INDEXER

  ucTemp = 0x00;
  if (m_pFalconSMR->getRefuelDisconnectOn())
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getRefuelRdyOn())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getRefuelAirOn())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getPriorityModeOn())
  {
    if (getBlink(FlightDataBMS::PriMode, FREQ_4HZ))
    {
      ucTemp |= 0x08;
    }
  }
  if (m_pFalconSMR->getHandOffOn())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getUnknownOn())
  {
    if (getBlink(FlightDataBMS::Unk, FREQ_4HZ))
    {
      ucTemp |= 0x20;
    }
  }
  if (m_pFalconSMR->getTargetSeparationOn())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = 0x00;
  if (m_pFalconSMR->getObs())
  {
    ucTemp |= 0x01;
  }
  // simpit failure
  if (m_pFalconSMR->getFalconVersion() == 0)
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getSysTestOn())
  {
    ucTemp |= 0x08; /* is 0x04 acc. to docu */
  }
  if (m_pFalconSMR->getAoaBelowOn())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getAoaOnGlideSlopeOn())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getAoaAboveOn())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = 0x00;
  if (m_pFalconSMR->getCanopyPressureFault()) // TODO check with fault board sync
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getTLConfigFault())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getEngineFireOn()) // TODO check alternate error causes
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getEngineOn())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getHydraulicsFault())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getDualFault())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getDbuWarnOn())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = 0x00;
  if (m_pFalconSMR->getLaunchOn())
  {
    if (getBlink(FlightDataBMS::Launch, FREQ_4HZ))
    {
      ucTemp |= 0x01;
    }
  }
  if (m_pFalconSMR->getMiddleMarker()) // the shit is, the outer marker is also there
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getEcmPower())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getTfRadarStby())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getTfRadarEngaged())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getMasterCautionOn())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getTerrainFollowFault())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return 0;
}

// ***********************      AIRSPEED    ***********************
/*
 gets airspeed data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getAirspeed(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;
  int iTemp = 0;
  float fAirspeed = 0;
  float fAngle = 0;

  m_pFalconSMR->cData[iIndex++] = ID_AIRSPEED; //message type AIRSPEED

  fAirspeed = m_pFalconSMR->getAirspeed();
  fAngle = 0.0f;
  /* do some math to convert airspeed to angle. Note: this is non linear stuff.
   0 degree is pointing north or top
   0 - 40 deg  >  0 - 100 knots
   40 - 138 deg  > 100 - 200 knots
   138 - 182 deg  > 200 - 300 knots
   182 - 221 deg  > 300 - 400 knots
   221 - 253 deg  > 400 - 500 knots
   253 - 345 deg  > 500 - 850 knots

   */
  if (fAirspeed < 100)
  { // mx + t with m = 40/100 and t = 0
    fAngle = (fAirspeed * 0.4f);

  } else if (fAirspeed < 200)
  { // mx + t with m = 98/100 and t = -58
    fAngle = 0.98f * fAirspeed - 58;
  } else if (fAirspeed < 300)
  { // mx + t with m = 44/100 and t = 50
    fAngle = 0.44f * fAirspeed + 50;
  } else if (fAirspeed < 400)
  { // mx + t with m = 39/100 and t = 65
    fAngle = 0.39f * fAirspeed + 65;
  } else if (fAirspeed < 500)
  { // mx + t with m = 32/100 and t = 93
    fAngle = 0.32f * fAirspeed + 93;
  } else if (fAirspeed < 850)
  { // mx + t with m = 92/350 and t = 121.57
    fAngle = 0.2629f * fAirspeed + 121.57f;
  } else
  {
    fAngle = 345.0;
  }
  iTemp = (int) fAngle;
  // low byte
  ucTemp = (byte)(iTemp & 0x007F);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  // high byte
  ucTemp = (byte)((iTemp & 0x0180) >> 7);

  m_pFalconSMR->cData[iIndex] = ucTemp;
  // mach value range 0.00 to 2.55
  iTemp = (unsigned short) (m_pFalconSMR->getMach() * 100.0f);
  // low byte
  ucTemp = (byte)((iTemp & 0x07) << 4);
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] |= ucTemp;
  // high byte
  ucTemp = (byte)((iTemp & 0xF8) >> 3);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  return 0;
}
// ***********************      ALTIMETER     ***********************
/*
 gets Threat Warning Prima, Misc Panel and left eyebrow indicator lights data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getAltimeter(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;
  int iTemp = 0;
  float fAltitude = 0;

  m_pFalconSMR->cData[iIndex++] = ID_ALTIMETER; //message type ALTIMETER

  fAltitude = m_pFalconSMR->getAltitude();
  // low byte
  iTemp = (unsigned short) fAltitude;
  ucTemp = (byte)(iTemp & 0x007F) | 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  // mid section
  ucTemp = (byte)((iTemp & 0x3F80) >> 7);
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  // high byte
  ucTemp = (byte)((iTemp & 0xC000) >> 14) & 0x03;
  ucTemp |= 0x80; // stuffing bit
  m_pFalconSMR->cData[iIndex] = ucTemp;

  if (m_pFalconSMR->getPowerOff())
  {
    m_pFalconSMR->cData[iIndex] |= 0x04; /* PNEU on if no POWER */
  }

  iTemp = (unsigned short) (2992 - 2048);
  ucTemp = (byte)((iTemp & 0x0F) << 3);
  m_pFalconSMR->cData[iIndex++] |= ucTemp;

  ucTemp = (byte)((iTemp & 0x7F0) >> 4);
  m_pFalconSMR->cData[iIndex++] = (ucTemp | 0x80);

  return 0;
}
// ***********************        AOA      ***********************
/*
 gets angle of attack data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getAoa(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_AOA; //message type AOA

  if (m_pFalconSMR->getAoaFlag())
  {
    ucTemp = 0x80; // AOA is ON (note this is inverse)
    if (m_pFalconSMR->getAoa() < 0)
    {
      ucTemp |= 0x40;
    }
    iTemp = (unsigned short) abs(m_pFalconSMR->getAoa());
    if (iTemp > 32) // max out at 32, simulation ranges till 35
    {
      ucTemp |= 0x3F;
    } else
    {
      ucTemp |= (byte) iTemp & 0x3F; // mask for 6 bit
    }
    m_pFalconSMR->cData[iIndex++] = ucTemp;
  } else
  {
    m_pFalconSMR->cData[iIndex++] = 0xEF; // AOA is OFF
  }

  return 0;
}

// ***********************      ADI        ***********************
/*
 gets Artificial direction indicator

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getAdi(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;
  int iTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_ADI; //message type ADI
  ucTemp = 0x80; // stuffing bit
  if (m_pFalconSMR->getAdiOff())
  {
    ucTemp |= 0x40;
  }
  if (m_pFalconSMR->getPitch() < 0)
  {
    ucTemp |= 0x20;
  }
  iTemp = (unsigned short) abs(m_pFalconSMR->getPitch() * 10.0f);
  ucTemp |= (iTemp & 0x1F);
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = 0x80; // stuffing bit
  if (m_pFalconSMR->getRoll() < 0)
  {
    ucTemp |= 0x40;
  }
  iTemp = (unsigned short) abs(m_pFalconSMR->getRoll() * 10.0f);
  ucTemp |= iTemp & 0x3F;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = 0x80; // stuffing bit
  if (m_pFalconSMR->getAdiAuxOn())
  {
    m_pFalconSMR->cData[iIndex] |= 0x40;
  }
  if (m_pFalconSMR->getAdiIlsHorizontal() < 0)
  {
    ucTemp |= 0x20;
  }
  iTemp = (unsigned short) abs(m_pFalconSMR->getAdiIlsHorizontal() * 10.0f);
  ucTemp |= iTemp & 0x1F;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = 0x80;
  if (m_pFalconSMR->getAdiGsOn())
  {
    m_pFalconSMR->cData[iIndex] |= 0x40;
  }
  if (m_pFalconSMR->getAdiLocOn())
  {
    m_pFalconSMR->cData[iIndex] |= 0x80;
  }
  if (m_pFalconSMR->getAdiIlsVertical() < 0)
  {
    ucTemp |= 0x20;
  }
  iTemp = (unsigned short) abs(m_pFalconSMR->getAdiIlsVertical() * 10.0f);
  ucTemp |= iTemp & 0x1F;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return 0;
}

// ***********************      VVI         ***********************
/*
 gets vertical velocity indicator data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getVvi(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;
  float fAngle = 0;

  m_pFalconSMR->cData[iIndex++] = ID_VVI; //message type VVI
  /*
   TODO validate this !
   This one is difficult, since VVI returns the FlighPathMarker (FPM) deviation
   Example: Plane is flying straight and level. Nose indicator on horizont
   line. Speed low: -> FPM low to the ground
   Speed high:      -> FPM almost at Nose indicator
   Both times plane sinks, calculation for sink rate would be

   sinkRate = vvi * kias
   1 knot = 101.268591426 feet/min

   Plane is NOT flying straight and level. Nose indicator at 30 degree
   line. Speed low.
   Calculation would be

   climbRate = (pitch - vvi) * kias
   */
  if (m_pFalconSMR->getVviFlag())
  {
    ucTemp = 0x80; // VVI FLAG OFF is off (indicated by 1)

    fAngle = (float) (m_pFalconSMR->getPitch() - m_pFalconSMR->getVvi());
    iTemp = (int) (fAngle * m_pFalconSMR->getAirspeed());
    // get sign bit
    if (iTemp < 0)
    {
      ucTemp |= 0x40;
    }
    ucTemp |= abs(iTemp) & 0x3F;
    m_pFalconSMR->cData[iIndex++] = ucTemp;
  } else
  {
    m_pFalconSMR->cData[iIndex++] = 0xEF; // VVI FLAG OFF is on (indicated by 0)
  }

  return 0;
}

// ***********************      HSI        ***********************
/*
 gets horizontal situation indicator data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getHsi(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_HSI; //message type HSI

  iTemp = (int) m_pFalconSMR->getCurrentHeading();
  ucTemp = (byte)(iTemp & 0x7F);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  ucTemp = (byte)((iTemp & 0x0180) >> 7);
  if (m_pFalconSMR->getHsiIlsWarningOn())
  {
    ucTemp |= 0x04;
  } else
  {
    ucTemp &= 0xFB;
  }
  if (m_pFalconSMR->getHsiCourseWarningOn())
  {
    ucTemp |= 0x08;
  } else
  {
    ucTemp &= 0xF7;
  }
  // desired HEADING low bits
  iTemp = (int) m_pFalconSMR->getDesiredHeading();
  ucTemp |= (byte)((iTemp & 0x07) << 4);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  ucTemp = (byte)((iTemp & 0x01F8) >> 3);
  if (m_pFalconSMR->getHsiTo())
  {
    ucTemp |= 0x40;
  } else
  {
    ucTemp &= 0xBF;
  }
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  // desired COURSE
  iTemp = (int) m_pFalconSMR->getDesiredCourse();
  ucTemp = (byte)(iTemp & 0x7F);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  ucTemp = (byte)((iTemp & 0x0180) >> 3);
  if (m_pFalconSMR->getHsiInitFlag())
  {
    ucTemp |= 0x04;
  } else
  {
    ucTemp &= 0xFB;
  }
  if (m_pFalconSMR->getHsiOff())
  {
    ucTemp |= 0x08;
  } else
  {
    ucTemp &= 0xF7;
  }
  // course deviation
  iTemp = (int) ((m_pFalconSMR->getCourseDeviation() * 100.0f) + 360.0f);
  ucTemp |= (byte)((iTemp & 0x0007) << 4);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  ucTemp = (byte)((iTemp & 0x03F8) >> 3);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  ucTemp = (byte)((iTemp & 0x1C00) >> 10);
  iTemp = (int) m_pFalconSMR->getDistanceToBeacon();
  ucTemp |= (byte)((iTemp & 0x0007) << 4);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  ucTemp = (byte)((iTemp & 0x03F8) >> 3);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  return 0;
}

// ***********************      DED         ***********************
/*
 gets Data Entry Display data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getDed(FalconSMR *m_pFalconSMR,
                         unsigned int &iIndex,
                         bool bPowerOff) {
  unsigned int i = 0;

  m_pFalconSMR->cData[iIndex++] = ID_DED; //message type DED
#define test_ded 0
#if test_ded < 1
  if (bPowerOff)
  {
    for (i = 0; i < 125; i++)
    {
      m_pFalconSMR->cData[iIndex++] = 0x20;
    }
    return ERROR_OK;
  }

  // DED needs cdata of 126 byte incl init byte
  for (i = 0; i < DED_MAX_LINES; i++)
  {

    char* cLine = new char[DED_LINE_LENGTH + 1];
    strncpy(cLine, m_pFalconSMR->getDed(i), DED_LINE_LENGTH);
    cLine[DED_LINE_LENGTH + 1] = TERMINATOR; // DO NOT REMOVE THIS LINE

    for (int k = 0; k < DED_LINE_LENGTH; k++)
    {
      unsigned char character = cLine[k];
      /*  BMS
       '.' = 0x2E
       ',' = 0x2C
       '*' = 0x2A
       '�' = 0x5E
       */
      switch (character) {
      case DED_ARROW_VAL:
        character = DED_ARROW_CHAR; // replace arrow hex value
        break;
      case DED_STAR_VAL_AF:
      case DED_STAR_VAL_BMS:
        character = DED_STAR_CHAR; // replace star hex value
        break;
      case DED_DEGREE_VAL:
        character = DED_DEGREE_CHAR;
        break;
        // fix bug of FALCON AF
      case 0x0D:
      case 0x0A:
      case 0x00:
        character = 0x20;
        break;
      default:
        break;
      }
      // check for inverted display
      if (m_pFalconSMR->getDedInv(i)[k] == DED_INVERTED_VAL)
      {
        character |= 0x80; // set inverted bit
      }
      if (character < 0x20)
      {
        return character; // error
      }
      m_pFalconSMR->cData[iIndex++] = character;
    }
    delete cLine;
  }
#else
  int i;

  for(i = 0x25; i <= 0x5F; i++)
  {
    m_pFalconSMR->cData[iIndex++] = i;
  }
  m_pFalconSMR->cData[iIndex++] = 'X';
  for( i = 0xC1; i <= 0xDA; i++)
  {
    m_pFalconSMR->cData[iIndex++] = i;
  }
  for( i = 0xB0; i <= 0xB9; i++)
  {
    m_pFalconSMR->cData[iIndex++] = i;
  }
  m_pFalconSMR->cData[iIndex++] = 'X';

  m_pFalconSMR->cData[iIndex++] = 'X';
  m_pFalconSMR->cData[iIndex++] = 'X';
  m_pFalconSMR->cData[iIndex++] = 'X';
  m_pFalconSMR->cData[iIndex++] = 'X';

  for( i = 0; i < 24; i++)
  {
    m_pFalconSMR->cData[iIndex++] = ' ';
  }
#endif
  return ERROR_OK;
}

// ***********************    Fuel Flow      ***********************
/*
 gets Fuel Flow data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getFuelFlow(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  char *cBuffer = new char[8];

  m_pFalconSMR->cData[iIndex++] = ID_FUELFLOW; //message type FUELFLOW
  // 2.digit
  strncpy(cBuffer, m_pFalconSMR->getFuelFlowAsChar(), FUELFLOW_LENGTH);
  cBuffer[0] = cBuffer[3];
  cBuffer[1] = '\0';
  ucTemp = (byte) atoi(cBuffer);
  m_pFalconSMR->cData[iIndex] = ucTemp & 0x0F; // 3.digit
  // not masked out since F-16 Block 50 shows only 3 active digits (5th to 3rd)
  // but moving digit not representable, so cue would be missing
  strncpy(cBuffer, m_pFalconSMR->getFuelFlowAsChar(), FUELFLOW_LENGTH);
  cBuffer[0] = cBuffer[2];
  cBuffer[1] = '\0';
  ucTemp = (byte) atoi(cBuffer);
  if (ucTemp == 0x00)
  { // stuffing bit if 0x00 at higher nibble
    ucTemp = 0x0A;
  }
  if (ucTemp == 0x01)
  { // stuffing bit if 0x01 at higher nibble
    ucTemp = 0x0B;
  }
  ucTemp *= 16; // left shift to higher nibble
  m_pFalconSMR->cData[iIndex++] |= ucTemp & 0xF0;
  // 4.digit
  strncpy(cBuffer, m_pFalconSMR->getFuelFlowAsChar(), FUELFLOW_LENGTH);
  cBuffer[0] = cBuffer[1];
  cBuffer[1] = '\0';
  ucTemp = (byte) atoi(cBuffer);
  m_pFalconSMR->cData[iIndex] = ucTemp & 0x0F;
  // 5.digit
  strncpy(cBuffer, m_pFalconSMR->getFuelFlowAsChar(), FUELFLOW_LENGTH);
  cBuffer[0] = cBuffer[0];
  cBuffer[1] = '\0';
  ucTemp = (byte) atoi(cBuffer);
  if (ucTemp == 0x00)
  { // stuffing bit if 0x00 at higher nibble
    ucTemp = 0x0A;
  }
  if (ucTemp == 0x01)
  { // stuffing bit if 0x01 at higher nibble
    ucTemp = 0x0B;
  }
  ucTemp *= 16; // left shift to higher nibble
  m_pFalconSMR->cData[iIndex++] |= ucTemp & 0xF0;

  delete[] cBuffer;
  cBuffer = NULL;

  return 0;
}

// ***********************    Oil Pressure    ***********************
/*
 gets Oil Pressure data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getOilPressure(FalconSMR *m_pFalconSMR,
                                 unsigned int &iIndex) {
  byte ucTemp = 0x00;

  m_pFalconSMR->cData[iIndex++] = ID_OIL_PRESSURE; //message type OIL_PRESSURE
  ucTemp = (int) (m_pFalconSMR->getOilPressure() * 2.0f); // widen range from 0 to 100: 0 to 200
  ucTemp = reverseByte(ucTemp);
  if (ucTemp < 0x20)
  {
    ucTemp |= 0x80;
  }
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return 0;
}

// ***********************    Nozzle Position    ***********************
/*
 gets Nozzle Position data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getNozzlePos(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_NOZZLE_POS; //message type NOZZLE_POS

  ucTemp = (byte)(m_pFalconSMR->getNozzlePos());
  ucTemp &= 0x7F;
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  return 0;
}

// ***********************      RPM        ***********************
/*
 gets Revolutions Per Minute data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getRpm(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_RPM; //message type RPM

  ucTemp = (byte)(m_pFalconSMR->getRpm());
  ucTemp &= 0x3F;
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  return 0;
}

// ***********************      FTIT      ***********************
/*
 gets Forward Turbine Intake Temperature data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getFtit(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;

  m_pFalconSMR->cData[iIndex++] = ID_FTIT; //message type FTIT

  ucTemp = (byte)(m_pFalconSMR->getFtit() - 700.0f); // special algorithm needed to get needle at correct angle
  ucTemp &= 0x3F;
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  return 0;
}

// ***********************      RWR        ***********************
/*
 gets Radar Warning Receiver data

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::getRwr(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  int iTemp = 0;
  unsigned int iRwrIndex = 0;
  unsigned int iRwrMaxIndex = 0;
  unsigned int iErrorCode = 0;

  m_pFalconSMR->cData[iIndex++] = ID_RWR; //message type RWR

  /*
   we transmit number of rwr symbols.
   Subject to change:
   heading and lethality
   Alternate:
   x,y coordinate on 128x128 display. consider grid and symbol size. That could
   allow for value ranging from 0 to 16 on each axis, reducing required bits to 8.
   though higher position accuracy is preferred.

   */
  iRwrMaxIndex = m_pFalconSMR->getNumberOfRwrObjects();
  if (iRwrMaxIndex > RWR_MAX_FRAMES)
  {
    iRwrMaxIndex = RWR_MAX_FRAMES;
    //iErrorCode = 1; // too many warnings
  }
  // frame size (frames left...)
  ucTemp = (byte)(iRwrMaxIndex & 0x0F);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  for (iRwrIndex = 0; iRwrIndex < iRwrMaxIndex; iRwrIndex++)
  {
    Falcon4::StructRwr strRwr = m_pFalconSMR->getRwrObject(iRwrIndex);

    // heading
    iTemp = (int) strRwr.fHeading;
    ucTemp = (byte)((iTemp / 4) & 0x007F);
    m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

    // lethality
    iTemp = (int) (strRwr.iLethality);
    ucTemp = ((byte) iTemp & 0x07);

    // flags
    if (strRwr.bSelected)
    {
      ucTemp |= 0x08;
    }
    if (strRwr.bMissileActivity)
    {
      ucTemp |= 0x10;
    }
    if (strRwr.bMissileLaunch)
    {
      ucTemp |= 0x20;
    }
    if (strRwr.bNew)
    {
      ucTemp |= 0x40;
    }
    m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit    

    // symbol
    ucTemp = (byte) strRwr.iRwrSymbol;
    m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit
  }

  return iErrorCode;
}
