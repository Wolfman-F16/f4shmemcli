/*
 InitInstance
 reverseByte
 reverse16
 transmitData
 */
#include "Application.h"

/**
 constructor
 */
CApplication::CApplication() {
  m_pFalconSMR = NULL;
  bSingleShotFlag = true;
}

/**
 destructor, deleting pointer pSerialComm and pFalconSMR
 */
CApplication::~CApplication() {
  delete m_pFalconSMR;
}

/**
 init instance. gets serial port config data, shared memory data and initialises gui
 \retVal true if successful
 */
BOOL CApplication::InitInstance() {
  int error = ERROR_DATA;
  // init memory access
  m_pFalconSMR = new FalconSMR;

  if (m_pFalconSMR->sync() != ERROR_OK) {

    while (error != ERROR_OK) {
      Log::getInstance()->debug("trying again...\n");

      Sleep(5000); // wait 5 seconds before next try
      error = m_pFalconSMR->sync();

      if (m_pFalconSMR->getFalconVersion() == 0) {
        Log::getInstance()->debug("failed\n");
        error = ERROR_DATA;
      }
    }
  }

  m_pFalconSMR->dumpSharedMem();

  return TRUE;
}

/**
 reads shared memory, writes data to serial port
 \param[in] bShowRealtime true to show realtime instead of game time
 */
int CApplication::prepareData(unsigned char* cData, unsigned int* length,
    bool bShowRealtime) {
  unsigned int iIndex = 0;
  int iErrorCode = ERROR_OK;
  bool bPowerOff = FALSE;

  if (m_pFalconSMR->cData == NULL) {
    m_pFalconSMR->cData = new byte[FRAME_LENGTH + RWR_SIZE]; // RWR needs space (345 in total)
  }

  m_pFalconSMR->cData[iIndex++] = SOF1;
  m_pFalconSMR->cData[iIndex++] = SOF2;

  if (m_pFalconSMR->getPowerOff()) {
    bPowerOff = TRUE;
  }
  iErrorCode = prepareRightConsole(m_pFalconSMR, iIndex, bShowRealtime,
      bPowerOff);
  if (iErrorCode != ERROR_OK) {
    errorIndex = SRC_RIGHT_CONSOLE;
    return iErrorCode;
  }
  iErrorCode = prepareCenterConsole(m_pFalconSMR, iIndex, bPowerOff);
  if (iErrorCode != ERROR_OK) {
    errorIndex = SRC_CENTER_CONSOLE;
    return iErrorCode;
  }
  iErrorCode = prepareLeftConsole(m_pFalconSMR, iIndex, bPowerOff);
  if (iErrorCode != ERROR_OK) {
    errorIndex = SRC_LEFT_CONSOLE;
    return iErrorCode;
  }

  m_pFalconSMR->cData[iIndex++] = 0x00;

  // update communications
#if DEBUG > 0
  if (bSingleShotFlag)
  {
    iErrorCode = m_pFalconSMR->dumpData(iIndex);
    if (iErrorCode)
    {
      Beep(840, 1000);
    }
    bSingleShotFlag = false;
  }
#endif

  *length = iIndex;
  //cData = m_pFalconSMR->cData;

  return iErrorCode;
}

/**
 reverses bit order of a byte. (8 bit)
 \param[in] x byte to reverse order
 \return reversed byte
 */
unsigned char CApplication::reverseByte(unsigned char x) {
  unsigned char h = 0;
  unsigned int i = 0;

  h = 0;

  for (i = 0; i < 8; i++) {
    h = (h << 1) + (x & 1);
    x >>= 1;
  }

  return h;
}

/**
 reverses bit order of two byte. (16 bit)
 \param[in] x 16 bit variable to reverse order
 \return reversed 16 bit variable
 */
unsigned short CApplication::reverse16(unsigned short x) {
  unsigned short h = 0;
  unsigned int i = 0;

  h = 0;

  for (i = 0; i < 16; i++) {
    h = (h << 1) + (x & 1);
    x >>= 1;
  }

  return h;
}

/*
 return transmission data in case off dark cockpit (POWER OFF).
 TODO only DED PFL and CMDS need shut off
 others are override only until Fuel != 0 (check for plausibility)
 \return number of characters to transmit
 */
unsigned int CApplication::getPowerOffData() {
  unsigned int i = 0;
  unsigned int iIndex = 0;

  if (m_pFalconSMR->cData == NULL) {
    m_pFalconSMR->cData = new byte[FRAME_LENGTH + RWR_SIZE]; // RWR needs space (345 in total)
  }

  m_pFalconSMR->cData[iIndex++] = SOF1;
  m_pFalconSMR->cData[iIndex++] = SOF2;
  // right console
  // Fault board lights
  m_pFalconSMR->cData[iIndex++] = ID_FAULT_LIGHTS;
  for (i = 0; i < 4; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // PFL
  m_pFalconSMR->cData[iIndex++] = ID_PFL;
  for (i = 0; i < 90; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x20;
  }
  // EPU Fuel
  m_pFalconSMR->cData[iIndex++] = ID_EPU_FUEL;
  for (i = 0; i < 2; i++) {
    m_pFalconSMR->cData[iIndex++] = 0xA5;
  }
  // Compass
  getCompass(m_pFalconSMR, iIndex);
  // Fuel
  m_pFalconSMR->cData[iIndex++] = ID_FUEL;
  for (i = 0; i < 5; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // Cabin Pressure
  m_pFalconSMR->cData[iIndex++] = ID_CABIN_PRESSURE;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // Clock
  getClock(m_pFalconSMR, iIndex, TRUE);

  // center console
  // indication
  m_pFalconSMR->cData[iIndex++] = ID_EYEBROW_INDEXER;
  for (i = 0; i < 4; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // Airspeed
  m_pFalconSMR->cData[iIndex++] = ID_AIRSPEED;
  for (i = 0; i < 3; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // Altimeter
  m_pFalconSMR->cData[iIndex++] = ID_ALTIMETER;
  for (i = 0; i < 3; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // AOA
  m_pFalconSMR->cData[iIndex++] = ID_AOA;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // ADI
  m_pFalconSMR->cData[iIndex++] = ID_ADI;
  for (i = 0; i < 4; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // VVI
  m_pFalconSMR->cData[iIndex++] = ID_VVI;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // HSI
  m_pFalconSMR->cData[iIndex++] = ID_HSI;
  for (i = 0; i < 8; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // DED
  m_pFalconSMR->cData[iIndex++] = ID_DED;
  for (i = 0; i < 125; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x20;
  }
  // Fuel Flow
  getFuelFlow(m_pFalconSMR, iIndex);
  // Oil pressure
  m_pFalconSMR->cData[iIndex++] = ID_OIL_PRESSURE;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // Nozzle Pos
  m_pFalconSMR->cData[iIndex++] = ID_NOZZLE_POS;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // RPM
  m_pFalconSMR->cData[iIndex++] = ID_RPM;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // FTIT
  m_pFalconSMR->cData[iIndex++] = ID_FTIT;
  m_pFalconSMR->cData[iIndex++] = 0x80;
  // RWR

  // left console
  // indication
  m_pFalconSMR->cData[iIndex++] = ID_LC_INDICATORS;
  for (i = 0; i < 6; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // CMDS
  m_pFalconSMR->cData[iIndex++] = ID_CMDS;
  for (i = 0; i < 2; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x9F; // 0x9F = cmds power off
  }
  // UHF
  m_pFalconSMR->cData[iIndex++] = ID_UHF;
  for (i = 0; i < 3; i++) {
    m_pFalconSMR->cData[iIndex++] = 0x80;
  }
  // TACAN
  getTacan(m_pFalconSMR, iIndex);
  return iIndex;
}

/*
 * Blink type function handling.
 * NOTE: sys test blinks 4 times, but only on Blk 52
 *
 */
bool CApplication::getBlink(uint32_t pBitmask, uint32_t pFreq) {

  if (m_pFalconSMR->isSetBlink(pBitmask))
  {
    if (swTimer.checkTimeout(pBitmask))
    {
      if (blinkStateOn[pBitmask] != true)
      {
        swTimer.setTime(pBitmask, pFreq);
        blinkStateOn[pBitmask] = true;
        return true;
      } else
      {
        swTimer.setTime(pBitmask, pFreq);
        blinkStateOn[pBitmask] = false;
        return false;
      }
    }
  }
  return true;
}
