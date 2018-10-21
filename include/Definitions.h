/*
 * Definitions.h
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//#define byte unsigned char
/* Application config settings */
#define MAP_NAME "FalconSharedMemoryArea"
#define BMS_MAP_NAME "FalconSharedMemoryArea2"

const unsigned int    RWR_SIZE          = 40;
const unsigned int    RWRINFO_SIZE      = 512;
const unsigned int    CALLSIGN_LEN      = 12;
const unsigned int    MAX_CALLSIGNS     = 32;

namespace Falcon4
{
#define SUCCESS 0
#define FALCON_BMS_432_VERSION 110
#define FALCON_BMS_433_VERSION 117
#define FALCON_AF_VERSION      111

struct StructRwr
{
  int  iRwrSymbol;
  float fHeading;
  int  iLethality;
  bool bNew;
  bool bSelected;
  bool bMissileLaunch;
  bool bMissileActivity;
};

struct StructClock
{
  unsigned char cHours;
  unsigned char cMinutes;
  unsigned char cSeconds;
};

enum ID
{
  ID_FAULT_LIGHTS                  = 0x01,
  ID_PFL                          = 0x02,
  ID_EPU_FUEL                      = 0x03,
  ID_COMPASS                      = 0x04,
  ID_FUEL                          = 0x05,
  ID_CABIN_PRESSURE                = 0x06,
  ID_CLOCK                        = 0x07,

  ID_EYEBROW_INDEXER              = 0x08,
  ID_TWP_MISC_PITFAIL              = 0x09,
  ID_AIRSPEED                      = 0x0A,
  ID_ALTIMETER                    = 0x0B,
  ID_AOA                          = 0x0C,
  ID_ADI                          = 0x0D,
  ID_VVI                          = 0x0E,
  ID_HSI                          = 0x0F,
  ID_DED                          = 0x10,
  ID_FUELFLOW                      = 0x11,
  ID_OIL_PRESSURE                  = 0x12,
  ID_NOZZLE_POS                    = 0x13,
  ID_RPM                          = 0x14,
  ID_FTIT                          = 0x15,
  ID_RWR                          = 0x16,

  ID_LC_INDICATORS                = 0x18,
  ID_CMDS                          = 0x19,
  ID_UHF                          = 0x1A,
  ID_TACAN                        = 0x1B
  
};

enum cause {
  SRC_RIGHT_CONSOLE     = 11,
  SRC_CENTER_CONSOLE    = 12,
  SRC_LEFT_CONSOLE      = 13,
  SRC_POWER_OFF         = 14
};

/* global variables */
extern unsigned int    TIMEOUT_VALUE ;       // timeout value in milliseconds

/* constants */
const unsigned int    SOF1              = 0x55;      // start of frame definition,
const unsigned int    SOF2              = 0xAA;
const unsigned int    FRAME_LENGTH      = 306;      // length including RWR ID, but excluding RWR data 


//const double          M_PI              = 3.14159265358979323846;
const char            TERMINATOR        = '\0';

const unsigned short  HALF_SPEED        = 350;

const unsigned short  TACAN_LENGTH      = 3;
const unsigned short  FUELFLOW_LENGTH   = 4;
// min max value ranges of Falcon 4.0 Allied Force
const float           ROLL_MIN          = -0.5f;
const float           ROLL_MAX          = 0.5f;
const float           PITCH_MIN         = -0.5f;
const float           PITCH_MAX         = 0.5f;
const unsigned short  RWR_MAX_FRAMES    = 10;
//
const unsigned short  DED_LINE_LENGTH   = 25;
const unsigned short  DED_MAX_LINES     = 5;
const char            DED_ARROW_VAL     = 0x01;
const char            DED_ARROW_CHAR    = 'a';
const char            DED_STAR_VAL_AF   = 0x04;
const char            DED_STAR_VAL_BMS  = 0x02;
const char            DED_STAR_CHAR     = '*';
const char            DED_DEGREE_VAL    = 0x5E;
const char            DED_DEGREE_CHAR   = 0x60;
const char            DED_INVERTED_VAL  = 0x02;

const unsigned short  PFL_LINE_LENGTH   = 25;
const unsigned short  PFL_LINE_INDENT   = 4;
const unsigned short  PFL_MAX_LINES     = 5;

};

#endif // DEFINITIONS_H
