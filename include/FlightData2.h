#ifndef _FLIGHT_DATA2_H
#define _FLIGHT_DATA2_H

#include "Definitions.h"

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
    OxyLow          = 0x4,  // was OBS not used in AF
    EquipHot        = 0x8,  // HUD Pull Up
    WOW             = 0x10,  // not a light bit not in AF ?!
    EngineFire      = 0x20,
    Config          = 0x40,  // caution light
    Hyd             = 0x80,
    FlcsAbcd        = 0x100,
    Dual            = 0x200, // caution light
    Canopy          = 0x400, // canopy spider
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
    AutoPilotOn     = 0x40000000, // no light bit
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
    // CMDS
    Go              = 0x40,
    NoGo            = 0x80,
    Degr            = 0x100,
    Rdy             = 0x200,
    ChaffLow        = 0x400,
    FlareLow        = 0x800,
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
    OnGround        = 0x1000,  // no light bit, no support in AF
    FlcsBitRun      = 0x2000,  // no support in AF
    FlcsBitFail     = 0x4000,  // no support in AF
    DbuWarn         = 0x8000,  // no support in AF
    // Gear lights
    NoseGearDown    = 0x10000,
    LeftGearDown    = 0x20000,
    RightGearDown   = 0x40000,
    unused          = 0x80000,
    ParkingBrake    = 0x100000,
    PowerOff        = 0x200000,
    CADC            = 0x400000,
    SpeedBrake      = 0x800000,
    SysTest         = 0x1000000,
    ATF_notEngaged  = 0x10000000
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
    AVTR            = 0x2000,
    OuterMarker     = 0x4000,
    MiddleMarker    = 0x8000,
    FromTrue        = 0x10000,
    Flying          = 0x80000000
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
  float fRoll;      //  Ownship Roll(Radians)
  float fYaw;        //  Ownship Yaw(Radians)
  float fMach;      //  Ownship Machnumber
  float fKias;      //  Ownship IndicatedAirspeed(Knots)
  float fVt;        //  Ownship TrueAirspeed(Ft/Sec)
  float fGs;        //  Ownship NormalGs
  float fWindOffset;    //  Wind delta to FPM (Radians)
  float fNozzlePos;    //  Ownship enginenozzlepercentopen(0-100)
  float fInternalFuel;  //  Ownship internalfuel(Lbs)
  float fExternalFuel;  //  Ownship externalfuel(Lbs)
  float fFuelFlow;     //  Ownship fuelflow(Lbs/Hour)
  float fRpm;        //  Ownship enginerpm(Percent0-103)
  float fFtit;      //  Ownship ForwardTurbineInletTemp(DegreesC)
  float fGearPos;     //  Ownship Gearposition0=up,1=down;
  float fSpeedBrake;    //  Ownship speedbrakeposition0=closed,1=60Degreesopen
  float fEpuFuel;      //  Ownship EPUfuel(Percent0-100)
  float fOilPressure;    //  Ownship OilPressure(Percent0-100)
  unsigned int iLightBits;//  Cockpit Indicator Lights, one bit per bulb  See enum
  float fHeadPitch;     //  Head pitch off set from designeye (radians)
  float fHeadRoll;     //  Head roll off set from designeye (radians)
  float fHeadYaw;      //  Head yaw off set from designeye (radians)
  unsigned int iLightBits2;      //  Cockpit Indicator Lights, one bit per bulb  See enum
  unsigned int iLightBits3;      //  Cockpit Indicator Lights, one bit per bulb See enum
  float fChaffCount;     //  Number of Chaff left
  float fFlareCount;    //  Number of Flare left
  float fNoseGearPos;    //  Position of the nose landing gear
  float fLeftGearPos;    //  Position of the left landing gear
  float fRightGearPos;  //  Position of the right landing gear
  float fAdiIlsHorPos;  //  Position of horizontal ILS bar
  float fAdiIlsVerPos;  //  Position of vertical ILS bar
  int iCourseState;     //  position of course knob
  int iHeadingState;    //  position of heading knob
  int iTotalStates;    //  never set / unused
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
  float fTrimPitch;     //   Value of trim in pitch axis, -0 5 to +0 5
  float fTrimRoll;     //  Value of trim in roll axis, -0 5 to +0 5
  float fTrimYaw;      //   Value of trim in yaw axis, -0 5 to +0 5
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
  int iMainPower;          // main power switch state

  /// queries light bit for lightBits
  bool isSet(unsigned int  pNewBit) {
    if (iLightBits & pNewBit) {
      return true;
    } else {
      return false;
    }
  }

  /// queries light bit for lightBits2
  bool isSet2(int  pNewBit) {
    if (iLightBits2 & pNewBit) {
      return true;
    } else {
      return false;
    }
  }

  /// queries light bit for lightBits3
  bool isSet3(unsigned int  pNewBit) {
    if (iLightBits3 & pNewBit) {
      return true;
    } else {
      return false;
    }
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


class FlightDataBMS
{
public:

	// TACAN
	enum TacanSources
	{
		UFC = 0,
		AUX,
		NUMBER_OF_SOURCES,
	};
	enum TacanBits
	{
		band = 0x01,   // true in this bit position if band is X
		mode = 0x02,   // true in this bit position if domain is air to air
	};

	// ALTIMETER
	enum AltBits
	{
		CalType  = 0x01,	// true if calibration in inches of Mercury (Hg), false if in hectoPascal (hPa)
		PneuFlag = 0x02,	// true if PNEU flag is visible
	};

	// POWER
	enum PowerBits
	{
		BusPowerBattery      = 0x01,	// true if at least the battery bus is powered
		BusPowerEmergency    = 0x02,	// true if at least the emergency bus is powered
		BusPowerEssential    = 0x04,	// true if at least the essential bus is powered
		BusPowerNonEssential = 0x08,	// true if at least the non-essential bus is powered
		MainGenerator        = 0x10,	// true if the main generator is online
		StandbyGenerator     = 0x20,	// true if the standby generator is online
		JetFuelStarter       = 0x40,	// true if JFS is running, can be used for magswitch
	};

	// BLINKING LIGHTS - only indicating *IF* a lamp is blinking, not implementing the actual on/off/blinking pattern logic!
	enum BlinkBits
	{
		// currently working
		OuterMarker  ,	// defined in HsiBits    - slow flashing for outer marker
		MiddleMarker ,	// defined in HsiBits    - fast flashing for middle marker
		PROBEHEAT    ,	// defined in LightBits2 - probeheat system is tested
		AuxSrch      ,	// defined in LightBits2 - search function in NOT activated and a search radar is painting ownship
		Launch       ,	// defined in LightBits2 - missile is fired at ownship
		PriMode      ,	// defined in LightBits2 - priority mode is enabled but more than 5 threat emitters are detected
		Unk          ,	// defined in LightBits2 - unknown is not active but EWS detects unknown radar

		// not working yet, defined for future use
		Elec_Fault   ,	// defined in LightBits3 - non-resetting fault
		OXY_BROW     ,	// defined in LightBits  - monitor fault during Obogs
		EPUOn        ,	// defined in LightBits3 - abnormal EPU operation
		JFSOn_Slow   ,	// defined in LightBits3 - slow blinking: non-critical failure
		JFSOn_Fast   ,	// defined in LightBits3 - fast blinking: critical failure
	};

	// CMDS mode state
	enum CmdsModes
	{
		CmdsOFF  = 0,
		CmdsSTBY = 1,
		CmdsMAN  = 2,
		CmdsSEMI = 3,
		CmdsAUTO = 4,
		CmdsBYP  = 5,
	};

	// HSI/eHSI mode state
	enum NavModes 
	{
		ILS_TACAN   = 0,
		TACAN       = 1, 
		NAV         = 2,
		ILS_NAV     = 3,
	};

	// human pilot state
	enum FlyStates
	{
		IN_UI   = 0, // UI      - in the UI
		LOADING = 1, // UI>3D   - loading the sim data
		WAITING = 2, // UI>3D   - waiting for other players
		FLYING  = 3, // 3D      - flying
		DEAD    = 4, // 3D>Dead - dead, waiting to respawn
		UNKNOWN = 5, // ???
	};

	// VERSION 1
  float nozzlePos2;   // Ownship engine nozzle2 percent open (0-100)
  float rpm2;         // Ownship engine rpm2 (Percent 0-103)
  float ftit2;        // Ownship Forward Turbine Inlet Temp2 (Degrees C)
  float oilPressure2; // Ownship Oil Pressure2 (Percent 0-100)

	unsigned char navMode;  // current mode selected for HSI/eHSI

	float fBaroAlt;         // Ownship barometric altitude given by AAU (depends on calibration)

	char tacanInfo[NUMBER_OF_SOURCES];      // Tacan band/mode settings for UFC and AUX COMM

	// VERSION 2 / 7
	int AltCalReading;	// barometric altitude calibration (depends on CalType)
	unsigned int altBits;		// various altimeter bits, see AltBits enum for details
	unsigned int powerBits;		// Ownship power bus / generator states, see PowerBits enum for details
	unsigned int blinkBits;		// Cockpit indicator lights blink status, see BlinkBits enum for details
						// NOTE: these bits indicate only *if* a lamp is blinking, in addition to the
						// existing on/off bits. It's up to the external program to implement the
						// *actual* blinking.
	int cmdsMode;		// Ownship CMDS mode state, see CmdsModes enum for details
	int BupUhfPreset;	// BUP UHF channel preset

	// VERSION 3
	int BupUhfFreq;		// BUP UHF channel frequency
	float cabinAlt;		// Ownship cabin altitude
	float hydPressureA;	// Ownship Hydraulic Pressure A
	float hydPressureB;	// Ownship Hydraulic Pressure B
	int currentTime;	// Current time in seconds (max 60 * 60 * 24)
	short vehicleACD;	// Ownship ACD index number, i.e. which aircraft type are we flying.
	int VersionNum;		// Version of FlightData2 mem area

	// VERSION 4
	float fuelFlow2;    // Ownship fuel flow2 (Lbs/Hour)

	// VERSION 5 / 8
	char RwrInfo[RWRINFO_SIZE]; // New RWR Info
	float lefPos;               // Ownship LEF position
	float tefPos;               // Ownship TEF position

	// VERSION 6
	float vtolPos;      // Ownship VTOL exhaust angle

	// VERSION 9
	char pilotsOnline;                                // Number of pilots in an MP session
	char pilotsCallsign[MAX_CALLSIGNS][CALLSIGN_LEN]; // List of pilots callsign connected to an MP session
	char pilotsStatus[MAX_CALLSIGNS];                 // Status of the MP pilots, see enum FlyStates


	// getters for external reader programs
	bool UfcTacanIsAA(void) {return ((tacanInfo[UFC] & mode) ? true : false); }
	bool AuxTacanIsAA(void) {return ((tacanInfo[AUX] & mode) ? true : false); }
	bool UfcTacanIsX(void)  {return ((tacanInfo[UFC] & band) ? true : false); }
	bool AuxTacanIsX(void)  {return ((tacanInfo[AUX] & band) ? true : false); }

	// ALTIMETER
	bool IsSetAlt(unsigned int newBit) { return ((altBits & newBit) ? true : false); };

	// POWER
	bool IsSetPower(unsigned int newBit) { return ((powerBits & newBit) ? true : false); };

    // BLINKING LIGHTS
	bool IsSetBlink(unsigned int newBit) { return ((blinkBits & (1 << newBit)) ? true : false); };

	// CMDS mode state
	int  GetCmdsMode(void) {return cmdsMode;};

	// HSI/eHSI mode state
	int  GetNavMode(void) {return navMode;};
};

#endif  //_FLIGHT_DATA2_H
