/*
 * AppLeft.cpp
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#include "Application.h"

// ############################################################################
// ###                             LEFT CONSOLE                             ###
// ############################################################################
/*
 fills send buffer with data for left console

 \param[in|out] m_pFalconSMR   needed for access to send buffer 'cData'
 \param[in|out] iIndex         current index of send buffer
 \return        error code
 */
int CApplication::prepareLeftConsole(FalconSMR *m_pFalconSMR,
    unsigned int &iIndex, bool bPowerOff) {
  unsigned int initialIndexValue = iIndex;

  getLeftConsoleIndication(m_pFalconSMR, iIndex); // 7
  getCmds(m_pFalconSMR, iIndex, bPowerOff); // 3
  getUhf(m_pFalconSMR, iIndex); // 4
  getTacan(m_pFalconSMR, iIndex); // 3

  if ((iIndex - initialIndexValue) != 17) // const 18 byte
  {
    return ((iIndex - initialIndexValue) * -1);
  }

  return ERROR_OK;
}

// *********************** gear, gearhandle and TWA ***********************
/*
 gets gear, gear handle and Threat Warning Aux data and writes it to send
 buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getLeftConsoleIndication(FalconSMR *m_pFalconSMR,
    unsigned int &iIndex) {
  byte ucTemp = 0;
  float fTemp = 0.0f;

  m_pFalconSMR->cData[iIndex++] = ID_LC_INDICATORS; // message type left console indication

  if (m_pFalconSMR->getAuxLowOn())
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getAuxActiveOn())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getAuxSearchOn())
  {
    if (getBlink(FlightDataBMS::AuxSrch, FREQ_4HZ))
    {
      ucTemp |= 0x04;
    }
  }
  if (m_pFalconSMR->getAuxPower())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getFlcsAbcdOn())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getHydrazineOn())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getAirOn())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00;

  if (m_pFalconSMR->getEpuGeneratorOn())
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getEpuPmgOn())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getBatteryFailure())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getToFlcsOn())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getFlcsRelayOn())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getFlcsPmgOn())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getMainGeneratorOn())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00;

  if (m_pFalconSMR->getGearInTransition())
  {
    ucTemp |= 0x01;
  }
  if (m_pFalconSMR->getNoseGearDown())
  {
    ucTemp |= 0x02;
  }
  if (m_pFalconSMR->getRightGearDown())
  {
    ucTemp |= 0x04;
  }
  if (m_pFalconSMR->getLeftGearDown())
  {
    ucTemp |= 0x08;
  }
  if (m_pFalconSMR->getEpuOn())
  {
    ucTemp |= 0x10;
  }
  if (m_pFalconSMR->getJfsOn())
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getStbyGeneratorOn())
  {
    ucTemp |= 0x40;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00;
  // ROLL trim adjusted to go 0 to 10 instead of -1.5 to 1.5
  fTemp = m_pFalconSMR->getTrimRoll();
  fTemp *= 10.0f;
  if (fabs(fTemp) < 0.05f)
  {
    ucTemp = 0x0F; // means lights out
  } else
  {
    ucTemp = (byte) ((fTemp) + 5.0f);
  }
  ucTemp &= 0x0F; // mask, just to be safe
  // CVTS not supported
  if (m_pFalconSMR->getAvtrOn())
  {
    ucTemp |= 0x20;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00;

  // PITCH trim adjusted to go 0 to 10
  fTemp = m_pFalconSMR->getTrimPitch();
  fTemp *= 10.0f;
  if (fabs(fTemp) < 0.05f)
  {
    ucTemp = 0x0F; // means lights out
  } else
  {
    ucTemp = (byte) ((fTemp) + 5.0f);
  }
  ucTemp &= 0x0F; // mask, just to be safe
  // FLCS Run not supported in AF
  if (m_pFalconSMR->getFlcsBitRunOn())
  {
    ucTemp |= 0x10;
  }
  // FLCS Fail not supported
  if (m_pFalconSMR->getFlcsBitFailOn())
  {
    ucTemp |= 0x20;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;
  ucTemp = 0x00;

  ucTemp = (byte) (m_pFalconSMR->getSpeedBrake() * 10.0f);
  ucTemp &= 0x0F; // mask, just to be safe
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return 0;
}

// *********************** CMDS            ***********************
/*
 gets CMDS data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getCmds(FalconSMR *m_pFalconSMR, unsigned int &iIndex,
    bool bPowerOff) {
  byte ucTemp = 0x00;
  unsigned int i = 0;

  m_pFalconSMR->cData[iIndex++] = ID_CMDS; // message type CMDS

  if (bPowerOff)
  {
    for (i = 0; i < 2; i++)
    {
      m_pFalconSMR->cData[iIndex++] = 0x9F; // 0x9F = cmds power off
    }
    return ERROR_OK;
  }

  ucTemp = (byte) m_pFalconSMR->getChaff();
  ucTemp &= 0x3F; // mask, just to be safe

  if (m_pFalconSMR->getNoGoOn())
  {
    ucTemp |= 0x40;
  } else
  {
    ucTemp &= 0xBF;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  ucTemp = (byte) m_pFalconSMR->getFlare();
  if (m_pFalconSMR->getCmdsRdy())
  {
    ucTemp &= 0xDF; // RDY when bit 0, for compatibility with AF
  } else
  {
    ucTemp |= 0x20;
  }
  if (m_pFalconSMR->getDegradeOn())
  {
    ucTemp |= 0x40;
  } else
  {
    ucTemp &= 0xBF;
  }
  /* stuffing bit */
  ucTemp |= 0x80;
  m_pFalconSMR->cData[iIndex++] = ucTemp;

  return ERROR_OK;
}

// *********************** UHF Freq          ***********************
/*
 gets UHF radio data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getUhf(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0;
  // 225000
  byte dig1 = m_pFalconSMR->getBupUhfFreq() / 100000;
  byte dig2 = (m_pFalconSMR->getBupUhfFreq() / 10000) % 10;
  byte dig3 = (m_pFalconSMR->getBupUhfFreq() / 1000) % 10;
  byte dig4 = (m_pFalconSMR->getBupUhfFreq() / 100) % 10;
  byte dig5 = (m_pFalconSMR->getBupUhfFreq()) % 100;

  m_pFalconSMR->cData[iIndex++] = ID_UHF; // message type UHF

  ucTemp = ((dig1 << 4) & 0x30) | (dig2 & 0xF) | ((dig4 << 6) & 0x40);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80;

  ucTemp = ((dig3 << 3) & 0x78) | ((dig4 >> 1) & 0x07);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80;

  dig5 = dig5 / 25;
  ucTemp = ((dig5 << 5) & 0x60) | (m_pFalconSMR->getBupUhfChan() & 0x1F);
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80;

  return 0;
}

// *********************** TACAN           ***********************
/*
 gets TACAN data and writes it to send buffer 'cData'

 \param[in|out]  m_pFalconSMR    contains send buffer
 \param[in|out]  iIndex          index of send buffer
 \return         error code
 */
int CApplication::getTacan(FalconSMR *m_pFalconSMR, unsigned int &iIndex) {
  byte ucTemp = 0x00;
  char *cBuffer = new char[TACAN_LENGTH];

  m_pFalconSMR->cData[iIndex++] = ID_TACAN; // message type TACAN

  // get digit of hundreds; should be 1 or 0
  strncpy(cBuffer, m_pFalconSMR->getAuxTacanAsChar(), TACAN_LENGTH);
  cBuffer[0] = cBuffer[0];
  cBuffer[1] = '\0';
  ucTemp = (byte) atoi(cBuffer);
  ucTemp *= 16; // left shift 4 times
  // get digit of tens
  strncpy(cBuffer, m_pFalconSMR->getAuxTacanAsChar(), TACAN_LENGTH);
  cBuffer[0] = cBuffer[1];
  cBuffer[1] = '\0';
  ucTemp |= (byte) atoi(cBuffer) & 0x0F;

  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit

  // get digit of units
  strncpy(cBuffer, m_pFalconSMR->getAuxTacanAsChar(), TACAN_LENGTH);
  cBuffer[0] = cBuffer[2];
  cBuffer[1] = '\0';
  ucTemp = (byte) atoi(cBuffer);
  if (m_pFalconSMR->getAuxAABand())
  {
    ucTemp &= 0xEF;
  } else
  {
    ucTemp |= 0x10;
  }
  m_pFalconSMR->cData[iIndex++] = ucTemp | 0x80; // stuffing bit; X band

  delete[] cBuffer;
  return 0;
}
