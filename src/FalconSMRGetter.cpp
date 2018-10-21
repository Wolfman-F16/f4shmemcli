/*
 * FalconSMRGetter.cpp
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#include "math.h"
#include "FalconSMR.h"

/*
 getter methods of FalconSMR class for use with GUI. placed here as separate file for
 clarity's sake
 */

/// ******** left eyebrow lights ********
/// return master caution
bool FalconSMR::getMasterCautionOn() {
  if (flightDataF4->isSet(flightDataF4->MasterCaution))
  {
    return true;
  }
  return false;
}

/// return terrain following failure
bool FalconSMR::getTerrainFollowFault() {
  if (flightDataF4->isSet(flightDataF4->TF_Fail))
  {
    return true;
  }
  return false;
}

/// ******** left indexer lights ********

/// return aoa above index light
bool FalconSMR::getAoaAboveOn() {
  if (flightDataF4->isSet(flightDataF4->AOAAbove))
  {
    return true;
  }
  return false;
}

/// return aoa on index light
bool FalconSMR::getAoaOnGlideSlopeOn() {
  if (flightDataF4->isSet(flightDataF4->AOAOn))
  {
    return true;
  }
  return false;
}

/// return aoa above index light
bool FalconSMR::getAoaBelowOn() {
  if (flightDataF4->isSet(flightDataF4->AOABelow))
  {
    return true;
  } else
  {
    strcpy(cValue, ".");
  }
  return false;
}

/// ******** right indexer lights ********

/// return refuel ready light
bool FalconSMR::getRefuelRdyOn() {
  if (flightDataF4->isSet(flightDataF4->RefuelRDY))
  {
    return true;
  }
  return false;
}

/// return refuel tanker / nose wheel steering light
bool FalconSMR::getRefuelAirOn() {
  if (flightDataF4->isSet(flightDataF4->RefuelAR))
  {
    return true;
  }
  return false;
}

/// return refuel ready light
bool FalconSMR::getRefuelDisconnectOn() {
  if (cValue == NULL)
  {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->RefuelDSC))
  {
    return true;
  } else
  {
    strcpy(cValue, ".");
  }
  return false;
}

/// ******** right eyebrow ********

/// return eyebrow engine fire
bool FalconSMR::getEngineFireOn() {
  if (flightDataF4->isSet(flightDataF4->EngineFire))
  {
    return true;
  }
  return false;
}

/// return engine failure
bool FalconSMR::getEngineOn() {
  if (flightDataF4->isSet2(flightDataF4->Engine))
  {
    return true;
  }
  return false;
}

/// return eyebrow hydraulic oil pressure
bool FalconSMR::getHydraulicsFault() {
  if (flightDataF4->isSet(flightDataF4->Hyd))
  {
    return true;
  }
  return false;
}

/// eyebrow return flcs / dual (old block 40/42)
bool FalconSMR::getDualFault() {
  if (flightDataF4->isSet(flightDataF4->Dual))
  {
    return true;
  }
  return false;
}

/// eyebrow return DBU warning
bool FalconSMR::getDbuWarnOn() {
  if (flightDataF4->isSet3(flightDataF4->DbuWarn))
  {
    return true;
  }
  return false;
}

/// eyebrow return takeoff landing config
bool FalconSMR::getTLConfigFault() {
  if (flightDataF4->isSet(flightDataF4->To_Lndg_Config))
  {
    return true;
  }
  return false;
}

/// eyebrow return canopy / oxygen low
bool FalconSMR::getCanopyPressureFault() {
  if (flightDataF4->isSet(flightDataF4->Canopy))
  {
    return true;
  }
  return false;
}

/// eyebrow return oxygen low
bool FalconSMR::getObs() {
  if (flightDataF4->isSet(flightDataF4->OxyLow))
  {
    return true;
  }
  return false;
}

/// ******** flcs panel ********

/// return flcs bit fail
bool FalconSMR::getFlcsBitFailOn() {
  if (flightDataF4->isSet3(flightDataF4->FlcsBitFail))
  {
    return true;
  }
  return false;
}

/// return FLCS BIT run
bool FalconSMR::getFlcsBitRunOn() {
  if (flightDataF4->isSet3(flightDataF4->FlcsBitRun))
  {
    return true;
  }
  return false;
}

/// ******** manual trim panel ********

/// return trim pitch
float FalconSMR::getTrimPitch() {
  return flightDataF4->fTrimPitch;
}

/// return trim roll
float FalconSMR::getTrimRoll() {
  return flightDataF4->fTrimRoll;
}

/// return trim yaw
float FalconSMR::getTrimYaw() {
  return flightDataF4->fTrimYaw;
}

/// ******** TACAN lights ********

/// return ufc tacan channel
int FalconSMR::getUfcTacan() {
  return flightDataF4->iUfcTacChan;
}

/// return aux tacan channel
int FalconSMR::getAuxTacan() {
  return flightDataF4->iAuxTacChan;
}

/// ******** epu panel ********

/// return epu on
bool FalconSMR::getEpuOn() {
  if (flightDataF4->isSet2(flightDataF4->EPUOn))
  {
    return true;
  }
  return false;
}

/// return hydrazin
bool FalconSMR::getHydrazineOn() {
  if (flightDataF4->isSet3(flightDataF4->Hydrazine))
  {
    return true;
  }
  return false;
}

/// return air
bool FalconSMR::getAirOn() {
  if (flightDataF4->isSet3(flightDataF4->Air))
  {
    return true;
  }
  return false;
}

/// ******** elec panel ********

/// return flcs powermanagement
bool FalconSMR::getFlcsPmgOn() {
  if (flightDataF4->isSet3(flightDataF4->FlcsPmg))
  {
    return true;
  }
  return false;
}

/// return main generator
bool FalconSMR::getMainGeneratorOn() {
  if (flightDataF4->isSet3(flightDataF4->MainGen))
  {
    return true;
  }
  return false;
}

/// return standby generator
bool FalconSMR::getStbyGeneratorOn() {
  if (flightDataF4->isSet3(flightDataF4->StbyGen))
  {
    return true;
  }
  return false;
}

/// return epu generator
bool FalconSMR::getEpuGeneratorOn() {
  if (flightDataF4->isSet3(flightDataF4->EpuGen))
  {
    return true;
  }
  return false;
}

/// return epu powermanagement
bool FalconSMR::getEpuPmgOn() {
  if (flightDataF4->isSet3(flightDataF4->EpuPmg))
  {
    return true;
  }
  return false;
}

/// return battery fail
bool FalconSMR::getBatteryFailure() {
  if (flightDataF4->isSet3(flightDataF4->BatFail))
  {
    return true;
  }
  return false;
}

/// return to flcs
bool FalconSMR::getToFlcsOn() {
  if (flightDataF4->isSet3(flightDataF4->ToFlcs))
  {
    return true;
  }
  return false;
}

/// return battery fail
bool FalconSMR::getFlcsRelayOn() {
  if (flightDataF4->isSet3(flightDataF4->FlcsRly))
  {
    return true;
  }
  return false;
}

/// ******** avtr panel ********

/// return avtr
bool FalconSMR::getAvtrOn() {
  if (flightDataF4->isSetHsi(flightDataF4->AVTR))
  {
    return true;
  }
  return false;
}

/// ******** avtr panel ********

/// return Backup UHF Frequency
int FalconSMR::getBupUhfFreq() {
  return flightDataBms->BupUhfFreq;
}

/// return Backup UHF Channel
int FalconSMR::getBupUhfChan() {
  return flightDataBms->BupUhfPreset;
}

/// ******** engine panel ********

/// return jfs on
bool FalconSMR::getJfsOn() {
  if (flightDataF4->isSet2(flightDataF4->JFSOn))
  {
    return true;
  }
  return false;
}

/// ******** threat warning aux panel ********

/// return aux search
bool FalconSMR::getAuxSearchOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->AuxSrch)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return aux active
bool FalconSMR::getAuxActiveOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->AuxAct)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return aux low altitude
bool FalconSMR::getAuxLowOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->AuxLow)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return aux power
bool FalconSMR::getAuxPower() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    return true;
  }
  return false;
}

/// ******** cmds panel ********

/// return chaff
int FalconSMR::getChaff() {
  if (flightDataF4->fChaffCount < 0)
  {
    return 0;
  }
  return (int) flightDataF4->fChaffCount;
}

/// return flare
int FalconSMR::getFlare() {
  if (flightDataF4->fFlareCount < 0)
  {
    return 0;
  }
  return (int) flightDataF4->fFlareCount;
}

bool FalconSMR::getNoGoOn() {
  if (flightDataF4->iFalconVersion != FALCON_AF_VERSION)
  {
    if (flightDataF4->isSet2(flightDataF4->Go))
    {
      return true;
    }
  }
  return false;
}

bool FalconSMR::getCmdsRdy() {
  if (flightDataF4->iFalconVersion != FALCON_AF_VERSION)
  {
    if (!flightDataF4->isSet2(flightDataF4->Rdy))
    {
      return false;
    }
  }
  return true;
}

bool FalconSMR::getDegradeOn() {
  if (flightDataF4->iFalconVersion != FALCON_AF_VERSION)
  {
    if (flightDataF4->isSet2(flightDataF4->Degr))
    {
      return true;
    }
  }
  return false;
}

/// ******** gear panel ********

/// return speed brake
float FalconSMR::getSpeedBrake() {
  return flightDataF4->fSpeedBrake;
}

/// return left gear light
bool FalconSMR::getLeftGearDown() {
  if (flightDataF4->iFalconVersion == FALCON_AF_VERSION)
  {
    if (flightDataF4->fLeftGearPos > 0.99)
    {
      return true;
    }
  } else
  {
    if (flightDataF4->isSet3(flightDataF4->LeftGearDown))
    {
      return true;
    }
  }
  return false;
}

/// return nose gear light
bool FalconSMR::getNoseGearDown() {
  if (flightDataF4->iFalconVersion == FALCON_AF_VERSION)
  {
    if (flightDataF4->fNoseGearPos > 0.99)
    {
      return true;
    }
  } else
  {
    if (flightDataF4->isSet3(flightDataF4->NoseGearDown))
    {
      return true;
    }
  }
  return false;
}

/// return left gear light
bool FalconSMR::getRightGearDown() {
  if (flightDataF4->iFalconVersion == FALCON_AF_VERSION)
  {
    if (flightDataF4->fRightGearPos > 0.99)
    {
      return true;
    }
  } else if (flightDataF4->isSet3(flightDataF4->RightGearDown))
  {
    return true;
  }
  return false;
}

/// return gear handle light
bool FalconSMR::getGearInTransition() {
  if (flightDataF4->isSet2(flightDataF4->GearHandle))
  {
    return true;
  }
  return false;
}

/// ******** misc panel ********

/// return TFR active
bool FalconSMR::getTfRadarEngaged() {
  if (flightDataF4->isSet2(flightDataF4->TFR_Engaged))
  {
    return true;
  }
  return false;
}

/// return TFR active
bool FalconSMR::getTfRadarStby() {
  if (flightDataF4->isSet(flightDataF4->TFR_Stby))
  {
    return true;
  }
  return false;
}

/// return ECM power on
bool FalconSMR::getEcmPower() {
  if (flightDataF4->isSet2(flightDataF4->EcmPwr))
  {
    return true;
  }
  return false;
}

/// ******** threat warning prime panel ********

/// return Handoff
bool FalconSMR::getHandOffOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->HandOff)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return missile launch
bool FalconSMR::getLaunchOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->Launch)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return priority mode
bool FalconSMR::getPriorityModeOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->PriMode)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return naval
bool FalconSMR::getNavalOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->Naval)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return unkown / system test
bool FalconSMR::getUnknownOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->Unk)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return target separation
bool FalconSMR::getTargetSeparationOn() {
  if (flightDataF4->isSet2(flightDataF4->AuxPwr))
  {
    if (flightDataF4->isSet2(flightDataF4->TgtSep)
        || flightDataF4->isSet3(flightDataF4->SysTest))
    {
      return true;
    }
  }
  return false;
}

/// return target separation
bool FalconSMR::getSysTestOn() {
  if (flightDataF4->isSet3(flightDataF4->SysTest))
  {
    return true;
  }
  return false;
}

/// ******** rwr panel ********

/// return number of rwr objects as char array
int FalconSMR::getNumberOfRwrObjects() {
  return flightDataF4->iRwrObjectCount;
}

/// return rwr objects
StructRwr FalconSMR::getRwrObject(int iIndex) {
  StructRwr strRwr;
  float AbsHeading = 0;
  float RelHeading = 0;
  float Roll = 0;
  float RwrBearing = (flightDataF4->fBearing[iIndex]) * 180.0 / M_PI;
  /* bearing is angle with reference north */
  /* -180 to 0 is converted to 180 to 360 */
  (RwrBearing < 0) ? AbsHeading = 360.0f + RwrBearing : AbsHeading = RwrBearing;
  /* handle ownship orientation */
  RelHeading = AbsHeading - (flightDataF4->fCurrentHeading);
  if (RelHeading < 0)
  {
    RelHeading = 360.0f + RelHeading; /* -180 to 0 is converted to 180 to 360 */
  }
  /* handle flying upside down: more than 90 deg bank switches sides */
  /* check bank angle regardless of left or right */
  (flightDataF4->fRoll < 0) ? Roll = flightDataF4->fRoll * -1 : Roll =
                                  flightDataF4->fRoll;
  if (Roll > (M_PI / 2.0))
  {
    RelHeading = 360.0f - RelHeading;
  }
  if (RelHeading == 360)
  { // prevent overflow
    RelHeading = 0;
  }

  strRwr.iRwrSymbol = flightDataF4->iRwrSymbol[iIndex];
  strRwr.iLethality = floor(flightDataF4->fLethality[iIndex] * 7); // convert to 0 to 7
  if (strRwr.iLethality > 7)
  {
    strRwr.iLethality = 7;
  }
  strRwr.fHeading = RelHeading / 360 * 400;     // convert to 0 to 400
  (flightDataF4->iSelected[iIndex] == 1) ?
      strRwr.bSelected = true : strRwr.bSelected = false;
  (flightDataF4->iNewDetection[iIndex] == 1) ?
      strRwr.bNew = true : strRwr.bNew = false;
  (flightDataF4->iMissileActivity[iIndex] == 1) ? strRwr.bMissileActivity =
                                                      true :
                                                  strRwr.bMissileActivity =
                                                      false;
  (flightDataF4->iMissileLaunch[iIndex] == 1) ?
      strRwr.bMissileLaunch = true : strRwr.bMissileLaunch = false;

  return strRwr;
}

/// ******** center console ********

/// ---------- hud ----------

/// return g load
float FalconSMR::getGLoad() {
  return flightDataF4->fGs;
}

/// return airspeed
float FalconSMR::getAirspeed() {
  return flightDataF4->fKias;
}

/// return true airspeed
float FalconSMR::getTrueAirspeed() {
  return flightDataF4->fVt;
}

/// return lock
bool FalconSMR::getHudLockLightOn() {
  if (flightDataF4->isSet3(flightDataF4->FlcsBitFail))
  {
    return true;
  }
  return false;
}

/// return shoot
bool FalconSMR::getHudShootOn() {
  if (flightDataF4->isSet3(flightDataF4->DbuWarn))
  {
    return true;
  }
  return false;
}

/// return fuel low
bool FalconSMR::getHudFuelLow() {
  if (flightDataF4->isSet(flightDataF4->FuelLow))
  {
    return true;
  }
  return false;
}

/// return fpm offset (wind)
float FalconSMR::getWind() {
  return flightDataF4->fWindOffset;
}

/// ---------- airspeed ----------

/// return mach
float FalconSMR::getMach() {
  return flightDataF4->fMach;
}

/// ---------- altitude ----------

/// return altitude
float FalconSMR::getAltitude() {
  if (flightDataF4->iFalconVersion != FALCON_AF_VERSION)
  {
    // invert the value
    return flightDataBms->fBaroAlt * -1;
  } else
  {
    return flightDataF4->fZ * -1;
  }
}

/// ---------- aoa ----------

/// return AOA
float FalconSMR::getAoa() {
  return flightDataF4->fAlpha;
}

/// return aoa off
bool FalconSMR::getAoaFlag() {
  if (flightDataF4->isSetHsi(flightDataF4->AOA))
  {
    return true;
  }
  return false;
}

/// ---------- adi ----------

/// return a/c pitch
float FalconSMR::getPitch() {
  return flightDataF4->fPitch;
}

/// return a/c roll
float FalconSMR::getRoll() {
  return flightDataF4->fRoll;
}

/// return adi aux
bool FalconSMR::getAdiAuxOn() {
  if (flightDataF4->isSetHsi(flightDataF4->ADI_AUX))
  {
    return true;
  }
  return false;
}

/// return adi gs
bool FalconSMR::getAdiGsOn() {
  if (flightDataF4->isSetHsi(flightDataF4->ADI_GS))
  {
    return true;
  }
  return false;
}

/// return adi loc
bool FalconSMR::getAdiLocOn() {
  if (flightDataF4->isSetHsi(flightDataF4->ADI_LOC))
  {
    return true;
  }
  return false;
}

/// return adi off
bool FalconSMR::getAdiOff() {
  if (flightDataF4->isSetHsi(flightDataF4->ADI_OFF))
  {
    return true;
  }
  return false;
}

/// return adi ils horizontal position
float FalconSMR::getAdiIlsHorizontal() {
  return flightDataF4->fAdiIlsHorPos * 100;
}

/// return adi ils vertical position
float FalconSMR::getAdiIlsVertical() {
  return flightDataF4->fAdiIlsVerPos * 100;
}

/// ---------- vvi ----------

/// return vvi flag
bool FalconSMR::getVviFlag() {
  if (flightDataF4->isSetHsi(flightDataF4->VVI))
  {
    return true;
  }
  return false;
}

/// return vvi
float FalconSMR::getVvi() {
  float vvi = 0;
  // calculate cosinus of pitch and speed
  vvi = flightDataF4->fZDot;

  return vvi;
}

/// ---------- hsi ----------

/// return hsi off
bool FalconSMR::getHsiOff() {
  if (flightDataF4->isSetHsi(flightDataF4->HSI_OFF))
  {
    return true;
  }
  return false;
}

/// return hsi to true
bool FalconSMR::getHsiTo() {
  if (flightDataF4->isSetHsi(flightDataF4->ToTrue))
  {
    return true;
  }
  return false;
}

/// return hsi ils warning
bool FalconSMR::getHsiIlsWarningOn() {
  if (flightDataF4->isSetHsi(flightDataF4->IlsWarning))
  {
    return true;
  }
  return false;
}

/// return hsi course warning
bool FalconSMR::getHsiCourseWarningOn() {
  if (flightDataF4->isSetHsi(flightDataF4->CourseWarning))
  {
    return true;
  }
  return false;
}

/// return hsi init
bool FalconSMR::getHsiInitFlag() {
  if (flightDataF4->isSetHsi(flightDataF4->Init))
  {
    return true;
  }
  return false;
}

/// return course state (knob position)
int FalconSMR::getHsiCourseState() {
  return flightDataF4->iCourseState;
}

/// return heading state (knob position)
int FalconSMR::getHsiHeadingState() {
  return flightDataF4->iHeadingState;
}

/// return desired course
float FalconSMR::getDesiredCourse() {
  return flightDataF4->fDesiredCourse;
}

/// return course deviation
float FalconSMR::getCourseDeviation() {
  return flightDataF4->fCourseDeviation;
}

/// return desired heading
float FalconSMR::getDesiredHeading() {
  return flightDataF4->fDesiredHeading;
}

/// return current heading
float FalconSMR::getCurrentHeading() {
  return flightDataF4->fCurrentHeading;
}

/// return distance to beacon
float FalconSMR::getDistanceToBeacon() {
  return flightDataF4->fDistanceToBeacon;
}

/// return bearing to beacon
float FalconSMR::getBearingToBeacon() {
  return flightDataF4->fBearingToBeacon;
}

/// return deviation limit
float FalconSMR::getDeviationLimit() {
  return flightDataF4->fDeviationLimit;
}

/// return half deviation limit
float FalconSMR::getHalfDeviationLimit() {
  return flightDataF4->fHalfDeviationLimit;
}

/// return localizer course
float FalconSMR::getLocalizerCourse() {
  return flightDataF4->fLocalizerCourse;
}

/// return airbase x
float FalconSMR::getAirbaseX() {
  return flightDataF4->fAirbaseX;
}

/// return airbase y
float FalconSMR::getAirbaseY() {
  return flightDataF4->fAirbaseY;
}

/// ******** backup adi ********

/// return backup adi off
bool FalconSMR::getBackupAdiOff() {
  if (flightDataF4->isSetHsi(flightDataF4->BUP_ADI_OFF))
  {
    return true;
  }
  return false;
}

/// ******** fuel flow ********

/// return fuel flow
float FalconSMR::getFuelFlow() {
  return flightDataF4->fFuelFlow;
}

/// ******** Fuel Ctrl ********

/// return OBS marker
bool FalconSMR::getMiddleMarker() {
  if (flightDataF4->isSetHsi(flightDataF4->MiddleMarker))
  {
    return true;
  }
  return false;
}

/// ******** right aux panel ********

/// return oil pressure
float FalconSMR::getOilPressure() {
  return flightDataF4->fOilPressure;
}

/// return nozzle position
float FalconSMR::getNozzlePos() {
  return flightDataF4->fNozzlePos;
}

/// return rpm
float FalconSMR::getRpm() {
  return flightDataF4->fRpm;
}

/// return forward turbine inlet temperature
float FalconSMR::getFtit() {
  return flightDataF4->fFtit;
}

/// return aft fuel
float FalconSMR::getAftFuel() {
  return flightDataF4->fAftFuel;
}

/// return fwd fuel
float FalconSMR::getFwdFuel() {
  return flightDataF4->fFwdFuel;
}

/// return total fuel
float FalconSMR::getTotalFuel() {
  return flightDataF4->fTotalFuel;
}

/// ---------- fault board ----------

/// return flcs fault
bool FalconSMR::getFltCntrlSysFault() {
  if (flightDataF4->isSet(flightDataF4->FltControlSys))
  {
    return true;
  }
  return false;
}

/// return engine fault
bool FalconSMR::getEngineFault() {
  if (flightDataF4->isSet(flightDataF4->EngineFault))
  {
    return true;
  }
  return false;
}

/// return avionics fault
bool FalconSMR::getAvionicsFault() {
  if (flightDataF4->isSet(flightDataF4->Avionics))
  {
    return true;
  }
  return false;
}

/// return seat not armed fault
bool FalconSMR::getSeatArmingFault() {
  if (flightDataF4->isSet2(flightDataF4->SeatArm))
  {
    return true;
  }
  return false;
}

/// return electrical fault
bool FalconSMR::getElectricFailure() {
  if (flightDataF4->isSet3(flightDataF4->Elec_Fault))
  {
    return true;
  }
  return false;
}

/// return secondary engine control on
bool FalconSMR::getSecOn() {
  if (flightDataF4->isSet2(flightDataF4->SEC))
  {
    return true;
  }
  return false;
}

/// return nose wheel steering fault
bool FalconSMR::getNwsFail() {
  if (flightDataF4->isSet(flightDataF4->NWSFail))
  {
    return true;
  }
  return false;
}

/// return fault board probe heat
bool FalconSMR::getProbeHeatOn() {
  if (flightDataF4->isSet2(flightDataF4->ProbeHeat))
  {
    return true;
  }
  return false;
}

/// return fuel oil hot
bool FalconSMR::getFuelOilHot() {
  if (flightDataF4->isSet2(flightDataF4->FuelOilHot))
  {
    return true;
  }
  return false;
}

/// return radar altimeter fault
bool FalconSMR::getRadarAltimeterFault() {
  if (flightDataF4->isSet(flightDataF4->RadarAlt))
  {
    return true;
  }
  return false;
}

/// return anti skid fault
bool FalconSMR::getAntiSkidFault() {
  if (flightDataF4->isSet2(flightDataF4->AntiSkid))
  {
    return true;
  }
  return false;
}

/// return iff fault
bool FalconSMR::getIffFault() {
  if (flightDataF4->isSet(flightDataF4->IFF))
  {
    return true;
  }
  return false;
}

/// return hook fault
bool FalconSMR::getHookFault() {
  if (flightDataF4->isSet(flightDataF4->Hook))
  {
    return true;
  }
  return false;
}

/// return C ADC fault
bool FalconSMR::getCadcFault() {
  if (flightDataF4->isSet3(flightDataF4->CADC))
  {
    return true;
  }
  return false;
}

/// return stores configuration fault
bool FalconSMR::getConfigurationFault() {
  if (flightDataF4->isSet(flightDataF4->Config))
  {
    return true;
  }
  return false;
}

/// return overheat
bool FalconSMR::getOverheat() {
  if (flightDataF4->isSet(flightDataF4->Overheat))
  {
    return true;
  }
  return false;
}

/// return oxygen low fault board warning
bool FalconSMR::getOxygenLow() {
  if (flightDataF4->isSet2(flightDataF4->OxygenLow))
  {
    return true;
  }
  return false;
}

/// a terrain following not engaged

/// return cabin pressure
bool FalconSMR::getCabinPressureFault() {
  if (flightDataF4->isSet(flightDataF4->CabinPress))
  {
    return true;
  }
  return false;
}

/// return fwd fuel low
bool FalconSMR::getFwdFuelLow() {
  if (flightDataF4->isSet2(flightDataF4->FwdFuelLow))
  {
    return true;
  }
  return false;
}

/// return buc backup control
bool FalconSMR::getBuc() {
  if (flightDataF4->isSet2(flightDataF4->BUC))
  {
    return true;
  }
  return false;
}

/// return aft fuel low
bool FalconSMR::getAftFuelLow() {
  if (flightDataF4->isSet2(flightDataF4->AftFuelLow))
  {
    return true;
  }
  return false;
}

/// ---------- end fault board ----------

/// return epu fuel
float FalconSMR::getEpuFuel() {
  return flightDataF4->fEpuFuel;
}

/// ******** not used values ********

/// return nose gear position
float FalconSMR::getNoseGearPosition() {
  return flightDataF4->fNoseGearPos;
}

/// return left gear position
float FalconSMR::getLeftGearPosition() {
  return flightDataF4->fLeftGearPos;
}

/// return right gear position
float FalconSMR::getRightGearPosition() {
  return flightDataF4->fRightGearPos;
}

/// return oxy low eyebrow indicator
bool FalconSMR::getOxyLowOn() {
  if (flightDataF4->isSet(flightDataF4->OxyLow))
  {
    return true;
  }
  return false;
}

/// return equipment hot
bool FalconSMR::getEquipHot() {
  if (flightDataF4->isSet(flightDataF4->EquipHot))
  {
    return true;
  }
  return false;
}

/// return weight on wheels
bool FalconSMR::getWeightOnWheels() {
  if (flightDataF4->isSet(flightDataF4->WOW))
  {
    return true;
  }
  return false;
}

/// return ecm failure
bool FalconSMR::getEcmFault() {
  if (flightDataF4->isSet2(flightDataF4->EcmFail))
  {
    return true;
  }
  return false;
}

/// return ecm failure as caution light
bool FalconSMR::getEcmCautionLightOn() {
  if (flightDataF4->isSet(flightDataF4->ECM))
  {
    return true;
  }
  return false;
}

/// returns internal fuel
float FalconSMR::getInternalFuel() {
  return flightDataF4->fInternalFuel;
}

/// returns external fuel
float FalconSMR::getExternalFuel() {
  return flightDataF4->fExternalFuel;
}

/// return Autopilot
bool FalconSMR::getAutoPilotOn() {
  if (flightDataF4->isSet(flightDataF4->AutoPilotOn))
  {
    return true;
  }
  return false;
}

/// return LEF Fault
bool FalconSMR::getLefFault() {
  if (flightDataF4->isSet3(flightDataF4->Lef_Fault))
  {
    return true;
  }
  return false;
}

/// return LEFlaps
bool FalconSMR::getLeFlapsFault() {
  if (flightDataF4->isSet(flightDataF4->LEFlaps))
  {
    return true;
  }
  return false;
}

/// return FLCS ABCD light
bool FalconSMR::getFlcsAbcdOn() {
  if (flightDataF4->isSet(flightDataF4->FlcsAbcd))
  {
    return true;
  }
  return false;
}

/// return HSI total flags
bool FalconSMR::getHsiTotalFlag() {
  if (flightDataF4->isSetHsi(flightDataF4->TotalFlags))
  {
    return true;
  }
  return false;
}

/// return power off
bool FalconSMR::getPowerOff() {
  if (flightDataF4->isSet3(flightDataF4->PowerOff))
  {
    return true;
  }
  return false;
}

/// returns hsi total values
float FalconSMR::getHsiTotalValues() {
  return flightDataF4->fTotalValues;
}

/// returns hsi total states
int FalconSMR::getHsiTotalStates() {
  return flightDataF4->iTotalStates;
}

/// returns gamma
float FalconSMR::getGamma() {
  return flightDataF4->fGamma;
}

/// returns beta
float FalconSMR::getBeta() {
  return flightDataF4->fBeta;
}

/// returns falcon version
int FalconSMR::getFalconVersion() {
  if (flightDataF4)
  {
    return flightDataF4->iFalconVersion;
  }
  return 0;
}

/// ingame clock
StructClock FalconSMR::getClock() {
  StructClock strClock;
  unsigned short iIndex = 0;
  char* cBuffer = NULL;
  char* cTime = NULL;
  int i = 0;

  strClock.cHours = 0;
  strClock.cMinutes = 0;
  strClock.cSeconds = 0;
  cBuffer = new char[64];
  cTime = new char[8];

  // get DED line nr 3
  strcpy(cBuffer, getDed(2));
  // extract time: hours at char 17 to 18
  for (i = 16; i < 18; i++)
  {
    cTime[iIndex] = cBuffer[i];
    iIndex++;
  }
  // convert to int
  strClock.cHours = atoi(cTime);

  iIndex = 0;
  // extract time: minutes at char 20 to 21
  for (i = 19; i < 21; i++)
  {
    cTime[iIndex] = cBuffer[i];
    iIndex++;
  }
  // convert to int
  strClock.cMinutes = atoi(cTime);

  iIndex = 0;
  // extract time: seconds at char 23 to 24
  for (i = 22; i < 24; i++)
  {
    cTime[iIndex] = cBuffer[i];
    iIndex++;
  }
  // convert to int
  strClock.cSeconds = atoi(cTime);

  // release your resources
  delete cBuffer;
  delete cTime;

  return strClock;
}

/// realtime clock
StructClock FalconSMR::getRealtimeClock() {
  time_t rawtime;
  struct tm * timeinfo;

  StructClock strClock;
  char* cBuffer = NULL;

  strClock.cHours = 0;
  strClock.cMinutes = 0;
  strClock.cSeconds = 0;
  cBuffer = new char(16);

  // get realtime clock

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(cBuffer, 15, "%I", timeinfo);
  strClock.cHours = atoi(cBuffer);
  strftime(cBuffer, 15, "%M", timeinfo);
  strClock.cMinutes = atoi(cBuffer);
  strftime(cBuffer, 15, "%S", timeinfo);
  strClock.cSeconds = atoi(cBuffer);

  delete cBuffer;

  return strClock;
}

/// returns ingame or realtime clock as string. true returns realtime
char* FalconSMR::getClockAsChar(bool bRealtime) {
  StructClock strClock;

  if (cValue == NULL)
  {
    cValue = new char[128];
  }

  if (bRealtime)
  {
    strClock = getRealtimeClock();
  } else
  {
    strClock = getClock();
  }

  sprintf(cValue, "%02d:%02d:%02d\0", strClock.cHours, strClock.cMinutes,
          strClock.cSeconds);

  return cValue;
}

/* BMS additional data */
bool FalconSMR::getAuxAABand() {
  if (flightDataBms != NULL)
  {
    if ((flightDataBms->tacanInfo[1]) & 0x01)
    {
      return false;
    } else
    {
      return true;
    }
  }
  return false;
}

float FalconSMR::getBaroAlt() {
  if (flightDataBms != NULL)
  {
    return flightDataBms->fBaroAlt;
  }
  return 0;
}

bool FalconSMR::isSetBlink(uint8_t idx) {
  return flightDataBms->IsSetBlink(idx);
}
