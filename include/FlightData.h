/*
 * FlightData.h
 *
 * Copyright: (c) Tommo
 */

#ifndef _FLIGHT_DATA_H
#define _FLIGHT_DATA_H
/*
makes shared memory data accessible
*/
class FlightData
{

public:
  enum LightBits
  {
    // Brow Lights
    MasterCaution   = 0x1,
    TF_Fail         = 0x2,
    OBS				= 0x4,	// not in AF ?
    ALT				= 0x8,	// HUD Pull Up
    WOW				= 0x10,	// not in AF ?!
    EngineFire      = 0x20,
    Config          = 0x40,  // caution light
    Hyd             = 0x80,
    Oil				= 0x100,
    Dual            = 0x200, // caution light
    Canopy			= 0x400,
    To_Lndg_Config  = 0x800,

    // AOA Indexers
    AOAAbove        = 0x1000,
    AOAOn           = 0x2000,
    AOABelow        = 0x4000,

    // Refuel/NWS
    RefuelRDY       = 0x8000,
    RefuelAR        = 0x10000,
    RefuelDSC       = 0x20000,

    // Caution Lights
    FltControlSys   = 0x40000,
    LEFlaps         = 0x80000,
    EngineFault     = 0x100000,
    Overheat        = 0x200000,    // MAYBE Elec Sys ? <- likely when ramp start
    FuelLow         = 0x400000,    // no caution light // always on
    Avionics        = 0x800000,
    RadarAlt        = 0x1000000,
    IFF             = 0x2000000,
    ECM             = 0x4000000,
    Hook            = 0x8000000,
    NWSFail         = 0x10000000,
    CabinPress      = 0x20000000,
    // other lights ??
    AutoPilotOn		= 0x40000000,
    TFR_Stby        = 0x80000000  // on misc panel
  };

  enum LightBits2
  {
    // Threat Warning Prime
    HandOff         = 0x1,
    Launch          = 0x2,
    PriMode         = 0x4,
    Naval           = 0x8,
    Unk             = 0x10,
    TgtSep          = 0x20,
    Unk1		= 0x40,
    Unk2		= 0x80,
    // Aux Threat Warning
    AuxSrch         = 0x1000,
    AuxAct          = 0x2000,
    AuxLow          = 0x4000,
    AuxPwr          = 0x8000,

    // ECM
    EcmPwr          = 0x10000,    // on misc panel
    EcmFail         = 0x20000,

    // Caution Lights
    FwdFuelLow      = 0x40000,
    AftFuelLow      = 0x80000,

    //Engine lights
    EPUOn           = 0x100000,    // on epu panel
    JFSOn           = 0x200000,    // on engine panel

    // Caution Lights
    SEC             = 0x400000,
    OxygenLow       = 0x800000,
    ProbeHeat       = 0x1000000,
    SeatArm         = 0x2000000,
    BUC             = 0x4000000,
    FuelOilHot      = 0x8000000,
    AntiSkid        = 0x10000000,

    TFR_Engaged     = 0x20000000,  // on misc panel
    GearHandle      = 0x40000000,  // on gear panel
    // right eyebrow
    Engine          = 0x80000000
  };

  enum LightBits3
  {
    // ELEC panel
    FlcsPmg         = 0x1,
    MainGen         = 0x2,
    StbyGen         = 0x4,
    EpuGen          = 0x8,
    EpuPmg          = 0x10,
    ToFlcs          = 0x20,
    FlcsRly         = 0x40,
    BatFail         = 0x80,
    // EPU panel
    Hydrazine       = 0x100,
    Air             = 0x200,
    // Caution lights
    Elec_Fault      = 0x400,
    Lef_Fault       = 0x800,  // try this as flaps extended flag
    Power_Off		= 0x1000,	// from here on down, no support in AF
    Eng2_Fire		= 0x2000,
    LockLight		= 0x4000,
    Shoot			= 0x8000,
    // Gear lights
    NoseGearDown    = 0x10000,  // not in AF
    LeftGearDown    = 0x20000,  // not in AF
    RightGearDown	= 0x40000     // not in AF
  };

  enum HsiBits
  {
    ToTrue          = 0x1,
    IlsWarning      = 0x2,
    CourseWarning   = 0x4,
    Init            = 0x8,
    TotalFlags      = 0x10,
    ADI_OFF         = 0x20,
    ADI_AUX         = 0x40,
    ADI_GS          = 0x80,
    ADI_LOC         = 0x100,
    HSI_OFF         = 0x200,
    BUP_ADI_OFF     = 0x400,
    VVI             = 0x800,
    AOA             = 0x1000,
    AVTR			= 0x2000
  };

  float fX;         //  Ownship North (Ft)
  float fY;         //  Ownship East (Ft)
  float fZ;         //  Ownship Down(Ft)
  float fXDot;      //  Ownship NorthRate(ft/sec)
  float fYDot;       //  Ownship EastRate(ft/sec)
  float fZDot;      //  Ownship DownRate(ft/sec)
  float fAlpha;      //  Ownship AOA(Degrees)
  float fBeta;       //  Ownship Beta(Degrees)
  float fGamma;      //  Ownship Gamma(Radians)
  float fPitch;       //  Ownship Pitch(Radians)
  float fRoll;			//	Ownship Pitch(Radians)
  float fYaw;				//	Ownship Pitch(Radians)
  float fMach;      //  Ownship Machnumber
  float fKias;      //  Ownship IndicatedAirspeed(Knots)
  float fVt;        //  Ownship TrueAirspeed(Ft/Sec)
  float fGs;        //  Ownship NormalGs
  float fWindOffset;    //  Wind delta to FPM (Radians)
  float fNozzlePos;    //  Ownship enginenozzlepercentopen(0-100)
  //float NozzlePos2;    //
  float fInternalFuel;  //  Ownship internalfuel(Lbs)
  float fExternalFuel;  //  Ownship externalfuel(Lbs)
  float fFuelFlow;     //  Ownship fuelflow(Lbs/Hour)
  float fRpm;        //  Ownship enginerpm(Percent0-103)
  //float RPM2;      //
  float fFtit;      //  Ownship ForwardTurbineInletTemp(DegreesC)
  //float FTIT2;      //
  float fGearPos;     //  Ownship Gearposition0=up,1=down;
  float fSpeedBrake;    //  Ownship speedbrakeposition0=closed,1=60Degreesopen
  float fEpuFuel;      //  Ownship EPUfuel(Percent0-100)
  float fOilPressure;    //  Ownship OilPressure(Percent0-100)
  //float OilPressure2;  //
  unsigned int iLightBits;//	Cockpit Indicator Lights, one bit per bulb. See enum
  float fHeadPitch;     //  Head pitch off set from designeye (radians)
  float fHeadRoll;     //  Head roll off set from designeye (radians)
  float fHeadYaw;      //  Head yaw off set from designeye (radians)
  unsigned int iLightBits2;			//	Cockpit Indicator Lights, one bit per bulb. See enum
  unsigned int iLightBits3;			//	Cockpit Indicator Lights, one bit per bulb.See enum
  float fChaffCount;     //  Number of Chaff left
  float fFlareCount;    //  Number of Flare left
  float fNoseGearPos;    //  Position of the nose landing gear
  float fLeftGearPos;    //  Position of the left landing gear
  float fRightGearPos;  //  Position of the right landing gear
  float fAdiIlsHorPos;  //  Position of horizontal ILS bar
  float fAdiIlsVerPos;  //  Position of vertical ILS bar
  int iCourseState;     //  position of course knob
  int iHeadingState;    //  position of heading knob
  int iTotalStates;    //  no idea
  float fCourseDeviation; //  HSI_VAL_CRS_DEVIATION
  float fDesiredCourse;   //  HSI_VAL_DESIRED_CRS
  float fDistanceToBeacon;//  HSI_VAL_DISTANCE_TO_BEACON
  float fBearingToBeacon; //  HSI_VAL_BEARING_TO_BEACON
  float fCurrentHeading;   //  HSI_VAL_CURRENT_HEADING
  float fDesiredHeading;  //  HSI_VAL_DESIRED_HEADING
  float fDeviationLimit;  //  HSI_VAL_DEV_LIMIT
  float fHalfDeviationLimit;   //  HSI_VAL_HALF_DEV_LIMIT
  float fLocalizerCourse; //  HSI_VAL_LOCALIZER_CRS
  float fAirbaseX;    //  HSI_VAL_AIRBASE_X
  float fAirbaseY;    //  HSI_VAL_AIRBASE_Y
  float fTotalValues;   //  HSI_VAL_TOTAL_VALUES???
  float fTrimPitch; 		//	 Value of trim in pitch axis, -0.5 to +0.5
  float fTrimRoll; 		//	Value of trim in roll axis, -0.5 to +0.5
  float fTrimYaw;			//	 Value of trim in yaw axis, -0.5 to +0.5
  int iHsiBits;      //  HSI flags
  char sDedLines[5][26];   //  25 usable chars
  char sDedInvert[5][26]; //  25 usable chars
  char sPflLines[5][26];   //  25 usable chars
  char sPflInvert[5][26];  //  25 usable chars
  int iUfcTacChan;    //  Tacan Channels
  int iAuxTacChan;    //

  int iRwrObjectCount;   //
  int iRwrSymbol[RWR_SIZE];    //
  float fBearing[RWR_SIZE];    //
  unsigned long iMissileActivity[RWR_SIZE]; //
  unsigned long iMissileLaunch[RWR_SIZE];   //
  unsigned long iSelected[RWR_SIZE];    //
  float fLethality[RWR_SIZE];        //
  unsigned long iNewDetection[RWR_SIZE];
  //
  float fFwdFuel;            //
  float fAftFuel;            //
  float fTotalFuel;          //

  int iFalconVersion;         // Falcon Version
  int iPaddingBytes[3];        // is possibly head position inputs x, y, z
  int iVersionNum;          // Version of Memarea ! is possibly main power
//

  /// sets light bit for lightBits
  void SetLightBit(int  pNewBit) {
    iLightBits |= pNewBit;
  }

  /// clears light bit for lightBits
  void ClearLightBit(int  pNewBit) {
    iLightBits &= ~pNewBit;
  }

  /// queries light bit for lightBits
  bool isSet(unsigned int  pNewBit) {
    if (iLightBits & pNewBit) {
      return true;
    } else {
      return false;
    }
  }

  /// sets light bit for lightBits2
  void SetLightBit2(int  pNewBit) {
    iLightBits2 |= pNewBit;
  }

  /// clears light bit for lightBits2
  void ClearLightBit2(int  pNewBit) {
    iLightBits2 &= ~pNewBit;
  }

  /// queries light bit for lightBits2
  bool isSet2(int  pNewBit) {
    if (iLightBits2 & pNewBit) {
      return true;
    } else {
      return false;
    }
  }

  /// sets light bit for lightBits3
  void SetLightBit3(unsigned int  pNewBit) {
    iLightBits3 |= pNewBit;
  }

  /// clears light bit for lightBits3
  void ClearLightBit3(unsigned int  pNewBit) {
    iLightBits3 &= ~pNewBit;
  }

  /// queries light bit for lightBits3
  bool isSet3(unsigned int  pNewBit) {
    if (iLightBits3 & pNewBit) {
      return true;
    } else {
      return false;
    }
  }

  /// sets light bit for hsi
  void setHsiBit(unsigned int  pNewBit) {
    iHsiBits |= pNewBit;
  }

  /// clears light bit for hsi
  void clearHsiBit(unsigned int  pNewBit) {
    iHsiBits &= ~pNewBit;
  }

  /// queries light bit for hsi
  bool isSetHsi(unsigned int  pNewBit) {
    if (iHsiBits & pNewBit) {
      return true;
    } else {
      return false;
    }
  }
};

#endif  //_FLIGHT_DATA_H
