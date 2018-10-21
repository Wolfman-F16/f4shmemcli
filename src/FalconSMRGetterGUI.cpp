#include "FalconSMR.h"

/*
getter methods of FalconSMR class for use with GUI. placed here as separate file for
clarity's sake
*/

/// ******** left eyebrow lights ********

/// return master caution
char* FalconSMR::getMasterCautionAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->MasterCaution)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return terrain following failure
char* FalconSMR::getTerrainFollowingAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->TF_Fail)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** left indexer lights ********

/// return aoa above index light
char* FalconSMR::getAoaAboveAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->AOAAbove)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return aoa on index light
char* FalconSMR::getAoaOnAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->AOAOn)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return aoa above index light
char* FalconSMR::getAoaBelowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->AOABelow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** right indexer lights ********

/// return refuel ready light
char* FalconSMR::getRefuelRdyAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->RefuelRDY)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return refuel tanker / nose wheel steering light
char* FalconSMR::getRefuelAirAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->RefuelAR)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return refuel ready light
char* FalconSMR::getRefuelDisconnectAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->RefuelDSC)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** right eyebrow ********

/// return engine fire
char* FalconSMR::getEngineFireEyebrowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->EngineFire)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return engine failure
char* FalconSMR::getEngineAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->Engine)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hydraulic oil pressure
char* FalconSMR::getHydraulicsEyebrowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Hyd)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return flcs / dual
char* FalconSMR::getDualEyebrowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Dual)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return takeoff landing config
char* FalconSMR::getTLConfigEyebrowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->To_Lndg_Config)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return canopy / oxygen low
char* FalconSMR::getCanopyPressureEyebrowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Canopy)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** flcs panel ********

/// ******** manual trim panel ********

/// return trim pitch
char* FalconSMR::getTrimPitchAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fTrimPitch);

  return cValue;
}

/// return trim roll
char* FalconSMR::getTrimRollAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fTrimRoll);

  return cValue;
}

/// return trim yaw
char* FalconSMR::getTrimYawAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fTrimYaw);

  return cValue;
}

/// ******** left indexer lights ********

/// return ufc tacan channel
char* FalconSMR::getUfcTacanAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%d", flightDataF4->iUfcTacChan);

  return cValue;
}

/// return aux tacan channel
char* FalconSMR::getAuxTacanAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%03d", flightDataF4->iAuxTacChan);

  return cValue;
}

/// ******** epu panel ********

/// return epu on
char* FalconSMR::getEpuOnAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->EPUOn)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hydrazin
char* FalconSMR::getHydrazineAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->Hydrazine)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return air
char* FalconSMR::getAirAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->Air)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** elec panel ********

/// return flcs powermanagement
char* FalconSMR::getFlcsPmgAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->FlcsPmg)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return main generator
char* FalconSMR::getMainGeneratorAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->MainGen)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return standby generator
char* FalconSMR::getStbyGeneratorAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->StbyGen)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return epu generator
char* FalconSMR::getEpuGeneratorAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->EpuGen)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return epu powermanagement
char* FalconSMR::getEpuPmgAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->EpuPmg)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return battery fail
char* FalconSMR::getBatteryFailureAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->BatFail)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return to flcs
char* FalconSMR::getToFlcsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->ToFlcs)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return battery fail
char* FalconSMR::getFlcsRelayAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->FlcsRly)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** avtr panel ********

/// return avtr
char* FalconSMR::getAvtrAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->AVTR)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** engine panel ********

/// return jfs on
char* FalconSMR::getJfsOnAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->JFSOn)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** threat warning aux panel ********

/// return aux search
char* FalconSMR::getAuxSearchAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->AuxSrch)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return aux active
char* FalconSMR::getAuxActiveAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->AuxAct)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return aux low altitude
char* FalconSMR::getAuxLowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->AuxLow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return aux power
char* FalconSMR::getAuxPowerAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->AuxPwr)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** cmds panel ********

/// return chaff
char* FalconSMR::getChaffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->fChaffCount < 0)
  {
    // necessary due to Falcon not stopping subtracting when 0 has been already reached
    strncpy(cValue,"0\0",2);
  }
  else
  {
    sprintf(cValue,"%03.0f", flightDataF4->fChaffCount);
  }

  return cValue;
}

/// return flare
char* FalconSMR::getFlareAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->fFlareCount < 0)
  {
    // necessary due to Falcon not stopping subtracting when 0 has been already reached
    strncpy(cValue,"0\0",2);
  }
  else
  {
    sprintf(cValue,"%03.0f", flightDataF4->fFlareCount);
  }

  return cValue;
}

/// ******** gear panel ********

/// return speed brake
char* FalconSMR::getSpeedBrakeAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fSpeedBrake);

  return cValue;
}

/// return left gear light
char* FalconSMR::getLeftGearDownAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if(flightDataF4->iFalconVersion == FALCON_AF_VERSION) {
    if(flightDataF4->fNoseGearPos > 0.99) {
      strcpy(cValue,"*");
    } else {
      strcpy(cValue,".");
    }
    return cValue;
  } 
  if (flightDataF4->isSet3(flightDataF4->LeftGearDown)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  
  return cValue;
}

/// return nose gear light
char* FalconSMR::getNoseGearDownAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->NoseGearDown)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return left gear light
char* FalconSMR::getRightGearDownAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->RightGearDown)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return gear handle light
char* FalconSMR::getGearHandleAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->GearHandle)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}


/// ******** misc panel ********

/// return TFR active
char* FalconSMR::getTfRadarEngagedAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->TFR_Engaged)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return TFR active
char* FalconSMR::getTfRadarStbyAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->TFR_Stby)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return ECM power on
char* FalconSMR::getEcmPowerAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->EcmPwr)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** threat warning prime panel ********

/// return Handoff
char* FalconSMR::getHandOffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->HandOff)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return missile launch
char* FalconSMR::getLaunchAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->Launch)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return priority mode
char* FalconSMR::getPriorityModeAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->PriMode)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return naval
char* FalconSMR::getNavalAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->Naval)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return unkown / system test
char* FalconSMR::getUnknownAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->Unk)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return target separation
char* FalconSMR::getTargetSeparationAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->TgtSep)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** rwr panel ********

/// return number of rwr objects as char array
char* FalconSMR::getNumberOfRwrObjectsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%d", flightDataF4->iRwrObjectCount);

  return cValue;
}

/// return rwr objects
char* FalconSMR::getRwrObjectAsChar(int iIndex)
{
  StructRwr strRwr = getRwrObject(iIndex); 

  sprintf(cValue,"%d : %d : %d : %d : %3.2f : %d : %d", strRwr.iRwrSymbol,
          strRwr.bSelected,
          strRwr.bNew,
          strRwr.iLethality,
          strRwr.fHeading,
          strRwr.bMissileActivity,
          strRwr.bMissileLaunch);

  return cValue;
}




/// ******** center console ********

/// ---------- hud ----------

/// return g load
char* FalconSMR::getGLoadAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.1f", flightDataF4->fGs);

  return cValue;
}

/// return airspeed
char* FalconSMR::getAirspeedAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.1f", flightDataF4->fKias);

  return cValue;
}

/// return true airspeed
char* FalconSMR::getTrueAirspeedAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.1f", flightDataF4->fVt);

  return cValue;
}

/// return lock
char* FalconSMR::getHudLockLightAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->FlcsBitFail)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}


/// return shoot
char* FalconSMR::getHudShootAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->DbuWarn)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return fuel low
char* FalconSMR::getFuelLowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->FuelLow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return fpm offset (wind)
char* FalconSMR::getWindAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fWindOffset);

  return cValue;
}

/// ---------- airspeed ----------

/// return mach
char* FalconSMR::getMachAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fMach);

  return cValue;
}

/// ---------- altitude ----------

/// return altitude
char* FalconSMR::getAltitudeAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if(flightDataF4->iFalconVersion == FALCON_AF_VERSION) {
     // invert the value
    sprintf(cValue,"%.1f", flightDataF4->fZ);
  } else {
    sprintf(cValue,"%.1f", flightDataBms->fBaroAlt);
  }
 
  return cValue;
}

char* FalconSMR::getBaroAltAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }

  if(flightDataF4->iFalconVersion == FALCON_AF_VERSION) {
     // invert the value
    sprintf(cValue, "0");
  } else {
    sprintf(cValue,"%.1f", (flightDataF4->fZ - flightDataBms->fBaroAlt));
  }

  return cValue;
}

/// ---------- aoa ----------

/// return AOA
char* FalconSMR::getAoaAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fAlpha);

  return cValue;
}

/// return aoa off
char* FalconSMR::getAoaFlagAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->AOA)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ---------- adi ----------

/// return adi pitch
char* FalconSMR::getPitchAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fPitch);

  return cValue;
}

/// return adi roll
char* FalconSMR::getRollAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fRoll);

  return cValue;
}

/// return adi roll
char* FalconSMR::getYawAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fYaw);

  return cValue;
}

/// return adi aux
char* FalconSMR::getAdiAuxAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->ADI_AUX)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return adi gs
char* FalconSMR::getAdiGsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->ADI_GS)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return adi loc
char* FalconSMR::getAdiLocAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->ADI_LOC)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return adi off
char* FalconSMR::getAdiOffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->ADI_OFF)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return adi ils horizontal position
char* FalconSMR::getAdiIlsHorizontalAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fAdiIlsHorPos * 100);

  return cValue;
}

/// return adi ils vertical position
char* FalconSMR::getAdiIlsVerticalAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fAdiIlsVerPos * 100);

  return cValue;
}


/// ---------- vvi ----------

/// return vvi flag
char* FalconSMR::getVviFlagAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->VVI)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return vvi
char* FalconSMR::getVviAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  // half the value, invert it and top it at 60
  sprintf(cValue,"%.2f", flightDataF4->fZDot);

  return cValue;
}

char* FalconSMR::getVerticalSpeedAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue, "%.2f", flightDataF4->fZDot / -2);

  return cValue;
}
/// ---------- hsi ----------

/// return hsi off
char* FalconSMR::getHsiOffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->HSI_OFF)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hsi to true
char* FalconSMR::getHsiToAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->ToTrue)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hsi ils warning
char* FalconSMR::getHsiIlsWarningAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->IlsWarning)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hsi course warning
char* FalconSMR::getHsiCourseWarningAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->CourseWarning)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hsi init
char* FalconSMR::getHsiInitFlagAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->Init)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return course state (knob position)
char* FalconSMR::getHsiCourseStateAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%d", flightDataF4->iCourseState);

  return cValue;
}

/// return heading state (knob position)
char* FalconSMR::getHsiHeadingStateAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%d", flightDataF4->iHeadingState);

  return cValue;
}


/// return desired course
char* FalconSMR::getDesiredCourseAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.1f", flightDataF4->fDesiredCourse);

  return cValue;
}

/// return course deviation
char* FalconSMR::getCourseDeviationAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fCourseDeviation);

  return cValue;
}

/// return desired heading
char* FalconSMR::getDesiredHeadingAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.1f", flightDataF4->fDesiredHeading);

  return cValue;
}

/// return current heading
char* FalconSMR::getCurrentHeadingAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fCurrentHeading);

  return cValue;
}

/// return distance to beacon
char* FalconSMR::getDistanceToBeaconAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fDistanceToBeacon);

  return cValue;
}

/// return bearing to beacon
char* FalconSMR::getBearingToBeaconAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fBearingToBeacon);

  return cValue;
}

/// return deviation limit
char* FalconSMR::getDeviationLimitAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fDeviationLimit);

  return cValue;
}

/// return half deviation limit
char* FalconSMR::getHalfDeviationLimitAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fHalfDeviationLimit);

  return cValue;
}

/// return localizer course
char* FalconSMR::getLocalizerCourseAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fLocalizerCourse);

  return cValue;
}

/// return airbase x
char* FalconSMR::getAirbaseXAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fAirbaseX);

  return cValue;
}

/// return airbase y
char* FalconSMR::getAirbaseYAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fAirbaseY);

  return cValue;
}

/// ******** ded ********

/// return display entry data
char* FalconSMR::getDed(unsigned short iIndex)
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  strcpy(cValue, flightDataF4->sDedLines[iIndex]);

  return cValue;
}

/// return inverted chars of ded
char* FalconSMR::getDedInv(unsigned short iIndex)
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  for (int i = 0; i < 26; i++ ) {
    cValue[i] = flightDataF4->sDedInvert[iIndex][i];
  }


  return cValue;
}

/// ******** backup adi ********

/// return backup adi off
char* FalconSMR::getBackupAdiOffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->BUP_ADI_OFF)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ******** fuel flow ********

/// return fuel flow
char* FalconSMR::getFuelFlowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%05.0f", flightDataF4->fFuelFlow);

  return cValue;
}

/// ******** right aux panel ********

/// return oil pressure
char* FalconSMR::getOilPressureAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fOilPressure);

  return cValue;
}

/// return nozzle position
char* FalconSMR::getNozzlePosAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fNozzlePos);

  return cValue;
}

/// return rpm
char* FalconSMR::getRpmAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fRpm);

  return cValue;
}

/// return forward turbine inlet temperature
char* FalconSMR::getFtitAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fFtit);

  return cValue;
}

/// return aft fuel
char* FalconSMR::getAftFuelAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fAftFuel);

  return cValue;
}

/// return fwd fuel
char* FalconSMR::getFwdFuelAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fFwdFuel);

  return cValue;
}

/// return total fuel
char* FalconSMR::getTotalFuelAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.1f", flightDataF4->fTotalFuel);

  return cValue;
}

/// return pfl
char* FalconSMR::getPfl(unsigned short iIndex)
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  strcpy(cValue, flightDataF4->sPflLines[iIndex]);

  return cValue;
}

/// return inverted lines of pfl
char* FalconSMR::getPflInv(unsigned short iIndex)
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  strcpy(cValue, flightDataF4->sPflInvert[iIndex]);

  return cValue;
}


/// ---------- fault board ----------

/// return flcs fault
char* FalconSMR::getFltCntrlSysAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->FltControlSys)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return engine fault
char* FalconSMR::getEngineFaultAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->EngineFault)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return avionics fault
char* FalconSMR::getAvionicsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Avionics)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return seat not armed fault
char* FalconSMR::getSeatArmingAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->SeatArm)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return electrical fault
char* FalconSMR::getElectricFailureAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->Elec_Fault)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return secondary engine control on
char* FalconSMR::getSecOnAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->SEC)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return nose wheel steering fault
char* FalconSMR::getNwsFailAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->NWSFail)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return probe heat
char* FalconSMR::getProbeHeatAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->ProbeHeat)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return fuel oil hot
char* FalconSMR::getFuelOilHotAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->FuelOilHot)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return radar altimeter fault
char* FalconSMR::getRadarAltimeterAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->RadarAlt)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return anti skid fault
char* FalconSMR::getAntiSkidAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->AntiSkid)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return iff fault
char* FalconSMR::getIffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->IFF)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return hook fault
char* FalconSMR::getHookAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Hook)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return stores configuration fault
char* FalconSMR::getConfigurationAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Config)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return overheat
char* FalconSMR::getElecSysAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->Overheat)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return overheat
char* FalconSMR::getOverheatAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->Overheat)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return oxygen low
char* FalconSMR::getOxygenLowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->OxygenLow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// a terrain following not engaged

/// return cabin pressure
char* FalconSMR::getCabinPressureAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->CabinPress)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return fwd fuel low
char* FalconSMR::getForwardFuelLowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->FwdFuelLow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return buc
char* FalconSMR::getBucAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->BUC)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return aft fuel low
char* FalconSMR::getAftFuelLowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->AftFuelLow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// ---------- end fault board ----------

/// return epu fuel
char* FalconSMR::getEpuFuelAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.2f", flightDataF4->fEpuFuel);

  return cValue;
}



/// ******** not used values ********

/// return nose gear position
char* FalconSMR::getNoseGearPositionAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fNoseGearPos);

  return cValue;
}

/// return left gear position
char* FalconSMR::getLeftGearPositionAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fLeftGearPos);

  return cValue;
}

/// return right gear position
char* FalconSMR::getRightGearPositionAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%.4f", flightDataF4->fRightGearPos);

  return cValue;
}

/// returns light bits
int FalconSMR::getLightBits()
{
  return flightDataF4->iLightBits;
}

/// returns light bits 2
int FalconSMR::getLightBits2()
{
  return flightDataF4->iLightBits2;
}

/// returns light bits 3
int FalconSMR::getLightBits3()
{
  return flightDataF4->iLightBits3;
}

/// returns hsi bits
int FalconSMR::getHsiBits()
{
  return flightDataF4->iHsiBits;
}

/// return obs
char* FalconSMR::getObsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->OxyLow)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return alt
char* FalconSMR::getHudAltitudeWarningAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->EquipHot)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return weight on wheels
char* FalconSMR::getWeightOnWheelsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->WOW)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return ecm failure
char* FalconSMR::getEcmFailAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->EcmFail)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return ecm failure as caution light
char* FalconSMR::getEcmCautionLightAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->ECM)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// returns internal fuel
char* FalconSMR::getInternalFuelAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%0.2f", flightDataF4->fInternalFuel);

  return cValue;
}

/// returns external fuel
char* FalconSMR::getExternalFuelAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%0.2f", flightDataF4->fExternalFuel);

  return cValue;
}

/// return Engine 2 Fire
char* FalconSMR::getEngine2FireAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->FlcsBitRun)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return Autopilot
char* FalconSMR::getAutoPilotOnAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->AutoPilotOn)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return LEF Fault
char* FalconSMR::getLefFaultAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->Lef_Fault)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return LEFlaps
char* FalconSMR::getLeFlapsAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->LEFlaps)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return oil pressure eyebrow
char* FalconSMR::getOilPressureEyebrowAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet(flightDataF4->FlcsAbcd)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return HSI total flags
char* FalconSMR::getHsiTotalFlagAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSetHsi(flightDataF4->TotalFlags)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// return power off
char* FalconSMR::getPowerOffAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet3(flightDataF4->OnGround)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// returns hsi total values
char* FalconSMR::getHsiTotalValuesAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%f", flightDataF4->fTotalValues);

  return cValue;
}

/// returns hsi total states
char* FalconSMR::getHsiTotalStatesAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%d", flightDataF4->iTotalStates);

  return cValue;
}

/// returns gamma
char* FalconSMR::getGammaAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%0.2f", flightDataF4->fGamma);

  return cValue;
}

/// returns beta
char* FalconSMR::getBetaAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%0.2f", flightDataF4->fBeta);

  return cValue;
}

/// returns falcon version
char *FalconSMR::getVersionAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  sprintf(cValue,"%d", flightDataF4->iFalconVersion);

  return cValue;
}


/// unknown light signal
char* FalconSMR::getGoAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->Go)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}

/// unknown light signal 2
char* FalconSMR::getNoGoAsChar()
{
  if (cValue == NULL) {
    cValue = new char[128];
  }
  if (flightDataF4->isSet2(flightDataF4->NoGo)) {
    strcpy(cValue,"*");
  } else {
    strcpy(cValue,".");
  }
  return cValue;
}