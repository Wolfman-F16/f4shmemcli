/*
  dumpSharedMem
  TODO dumpData
*/
#include "FalconSMR.h"

/**
dumps shared mem to file. used for debugging purposes
\return 1 if dump file could not be opened, 0 otherwise
*/
int FalconSMR::dumpSharedMem()
{
  FILE *fLog = NULL;
  fLog = fopen("dump.txt", "w");

  if (fLog == NULL)
  {
    return ERROR_FILE_NOT_FOUND;
  }

  fprintf(fLog, "open shared memory mapping...\n");

  if (status == 0) {

    fprintf(fLog, "Light Bit Series 1\n0x%X\n", flightDataF4->iLightBits);
    fprintf(fLog, "Light Bit Series 2\n0x%X\n", flightDataF4->iLightBits2);
    fprintf(fLog, "Light Bit Series 3\n0x%X\n", flightDataF4->iLightBits3);
    fprintf(fLog, "HSI Bit Series\n0x%X\n", flightDataF4->iHsiBits);


    fprintf(fLog, "Master Caution    ");
    if (flightDataF4->isSet(flightDataF4->MasterCaution)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Terrain Following ");
    if (flightDataF4->isSet(flightDataF4->TF_Fail)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "OBS               ");
    if (flightDataF4->isSet(flightDataF4->OxyLow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Altitude          ");
    if (flightDataF4->isSet(flightDataF4->EquipHot)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Weight on Wheels  ");
    if (flightDataF4->isSet(flightDataF4->WOW)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Engine fire       ");
    if (flightDataF4->isSet(flightDataF4->EngineFire)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Configuration     ");
    if (flightDataF4->isSet(flightDataF4->Config)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Hydraulics        ");
    if (flightDataF4->isSet(flightDataF4->Hyd)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Oil pressure      ");
    if (flightDataF4->isSet(flightDataF4->FlcsAbcd)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "DUAL              ");
    if (flightDataF4->isSet(flightDataF4->Dual)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Canopy pressure   ");
    if (flightDataF4->isSet(flightDataF4->Canopy)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Terrain following cfg ");
    if (flightDataF4->isSet(flightDataF4->To_Lndg_Config)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "AOA above         ");
    if (flightDataF4->isSet(flightDataF4->AOAAbove)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "AOA on            ");
    if (flightDataF4->isSet(flightDataF4->AOAOn)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "AOA below         ");
    if (flightDataF4->isSet(flightDataF4->AOABelow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Refuel Ready      ");
    if (flightDataF4->isSet(flightDataF4->RefuelRDY)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Refuel AR         ");
    if (flightDataF4->isSet(flightDataF4->RefuelAR)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Refuel Disconnect ");
    if (flightDataF4->isSet(flightDataF4->RefuelDSC)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Flt Cntrl Sys     ");
    if (flightDataF4->isSet(flightDataF4->FltControlSys)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "LEFlaps           ");
    if (flightDataF4->isSet(flightDataF4->LEFlaps)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Engine Fault      ");
    if (flightDataF4->isSet(flightDataF4->EngineFault)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Overheat          ");
    if (flightDataF4->isSet(flightDataF4->Overheat)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Fuel Low          ");
    if (flightDataF4->isSet(flightDataF4->FuelLow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Avionics          ");
    if (flightDataF4->isSet(flightDataF4->Avionics)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Radar Altimeter   ");
    if (flightDataF4->isSet(flightDataF4->RadarAlt)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "IFF               ");
    if (flightDataF4->isSet(flightDataF4->IFF)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "ECM               ");
    if (flightDataF4->isSet(flightDataF4->ECM)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Hook              ");
    if (flightDataF4->isSet(flightDataF4->Hook)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "NWSFail           ");
    if (flightDataF4->isSet(flightDataF4->NWSFail)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Cabin Pressure     ");
    if (flightDataF4->isSet(flightDataF4->CabinPress)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Auto Pilot On      ");
    if (flightDataF4->isSet(flightDataF4->AutoPilotOn)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "TFR_STBY           ");
    if (flightDataF4->isSet(flightDataF4->TFR_Stby)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }



    // Light bits 2
    fprintf(fLog, "Hand off          ");
    if (flightDataF4->isSet2(flightDataF4->HandOff)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Launch            ");
    if (flightDataF4->isSet2(flightDataF4->Launch)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Priority mode      ");
    if (flightDataF4->isSet2(flightDataF4->PriMode)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Naval             ");
    if (flightDataF4->isSet2(flightDataF4->Naval)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Unknown           ");
    if (flightDataF4->isSet2(flightDataF4->Unk)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Target Separation ");
    if (flightDataF4->isSet2(flightDataF4->TgtSep)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Auxiliary Search  ");
    if (flightDataF4->isSet2(flightDataF4->AuxSrch)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Auxiliary active  ");
    if (flightDataF4->isSet2(flightDataF4->AuxAct)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Auxiliary Low prios ");
    if (flightDataF4->isSet2(flightDataF4->AuxLow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Auxiliary Power   ");
    if (flightDataF4->isSet2(flightDataF4->AuxPwr)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "ECM Power         ");
    if (flightDataF4->isSet2(flightDataF4->EcmPwr)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Ecm Failure       ");
    if (flightDataF4->isSet2(flightDataF4->EcmFail)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Forward Fuel low  ");
    if (flightDataF4->isSet2(flightDataF4->FwdFuelLow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Aft Fuel low      ");
    if (flightDataF4->isSet2(flightDataF4->AftFuelLow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "EPU On            ");
    if (flightDataF4->isSet2(flightDataF4->EPUOn)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "JFS On            " );
    if (flightDataF4->isSet2(flightDataF4->JFSOn)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Sec On            ");
    if (flightDataF4->isSet2(flightDataF4->SEC)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Oxygen low        ");
    if (flightDataF4->isSet2(flightDataF4->OxygenLow)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Probe heat        ");
    if (flightDataF4->isSet2(flightDataF4->ProbeHeat)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Seat arming       ");
    if (flightDataF4->isSet2(flightDataF4->SeatArm)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "BUC               ");
    if (flightDataF4->isSet2(flightDataF4->BUC)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Fuel Oil Hot      ");
    if (flightDataF4->isSet2(flightDataF4->FuelOilHot)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Anti Skid         ");
    if (flightDataF4->isSet2(flightDataF4->AntiSkid)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "TF Radar engaged  ");
    if (flightDataF4->isSet2(flightDataF4->TFR_Engaged)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Gear handle       ");
    if (flightDataF4->isSet2(flightDataF4->GearHandle)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Engine            ");
    if (flightDataF4->isSet2(flightDataF4->Engine)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }
    // Light Bits 3
    fprintf(fLog, "FLCS Program      ");
    if (flightDataF4->isSet3(flightDataF4->FlcsPmg)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Main generator    ");
    if (flightDataF4->isSet3(flightDataF4->MainGen)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Standby generator ");
    if (flightDataF4->isSet3(flightDataF4->StbyGen)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }


    fprintf(fLog, "EPU generator     ");
    if (flightDataF4->isSet3(flightDataF4->EpuGen)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "EPU Program       ");
    if (flightDataF4->isSet3(flightDataF4->EpuPmg)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "To FLCS           ");
    if (flightDataF4->isSet3(flightDataF4->ToFlcs)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "FLCS Relay        ");
    if (flightDataF4->isSet3(flightDataF4->FlcsRly)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Battery Failure   ");
    if (flightDataF4->isSet3(flightDataF4->BatFail)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Hydrazine         ");
    if (flightDataF4->isSet3(flightDataF4->Hydrazine)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Air               ");
    if (flightDataF4->isSet3(flightDataF4->Air)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Electric Failure  ");
    if (flightDataF4->isSet3(flightDataF4->Elec_Fault)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "LEF Fault         ");
    if (flightDataF4->isSet3(flightDataF4->Lef_Fault)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Power Off         ");
    if (flightDataF4->isSet3(flightDataF4->OnGround)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Engine 2 Fire     ");
    if (flightDataF4->isSet3(flightDataF4->FlcsBitRun)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HUD Lock Light    ");
    if (flightDataF4->isSet3(flightDataF4->FlcsBitFail)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HUD Shoot         ");
    if (flightDataF4->isSet3(flightDataF4->DbuWarn)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Nose Gear down    ");
    if (flightDataF4->isSet3(flightDataF4->NoseGearDown)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Left Gear down    ");
    if (flightDataF4->isSet3(flightDataF4->LeftGearDown)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Right Gear down   ");
    if (flightDataF4->isSet3(flightDataF4->RightGearDown)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    // HSI
    fprintf(fLog, "HSI To            ");
    if (flightDataF4->isSetHsi(flightDataF4->ToTrue)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI ILS Warning   ");
    if (flightDataF4->isSetHsi(flightDataF4->IlsWarning)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI Course Warning ");
    if (flightDataF4->isSetHsi(flightDataF4->CourseWarning)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI Init Flag     ");
    if (flightDataF4->isSetHsi(flightDataF4->Init)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI Total Flags   ");
    if (flightDataF4->isSetHsi(flightDataF4->TotalFlags)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI ADI Off       ");
    if (flightDataF4->isSetHsi(flightDataF4->ADI_OFF)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI ADI AUX       ");
    if (flightDataF4->isSetHsi(flightDataF4->ADI_AUX)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI ADI GS        ");
    if (flightDataF4->isSetHsi(flightDataF4->ADI_GS)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI ADI LOC       ");
    if (flightDataF4->isSetHsi(flightDataF4->ADI_LOC)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "HSI OFF           ");
    if (flightDataF4->isSetHsi(flightDataF4->HSI_OFF)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Backup ADI Off    ");
    if (flightDataF4->isSetHsi(flightDataF4->BUP_ADI_OFF)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Vert Velocity Ind ");
    if (flightDataF4->isSetHsi(flightDataF4->VVI)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "AOA               ");
    if (flightDataF4->isSetHsi(flightDataF4->AOA)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "AVTR              ");
    if (flightDataF4->isSetHsi(flightDataF4->AVTR)) {
      fprintf(fLog, "\ton\n");
    } else {
      fprintf(fLog, "\toff\n");
    }

    fprintf(fLog, "Position x       \t%f\n", flightDataF4->fX);
    fprintf(fLog, "Position y       \t%f\n", flightDataF4->fY);
    fprintf(fLog, "Position z       \t%f\n", flightDataF4->fZ);

    fprintf(fLog, "Speed x          \t%f\n", flightDataF4->fXDot);
    fprintf(fLog, "Speed y          \t%f\n", flightDataF4->fYDot);
    fprintf(fLog, "Speed z          \t%f\n", flightDataF4->fZDot);

    fprintf(fLog, "AOA              \t%f\n", flightDataF4->fAlpha);
    fprintf(fLog, "Beta             \t%f\n", flightDataF4->fBeta);
    fprintf(fLog, "Gamma            \t%f\n", flightDataF4->fGamma);

    fprintf(fLog, "Pitch            \t%f\n", flightDataF4->fPitch);
    fprintf(fLog, "Roll              \t%f\n", flightDataF4->fRoll);
    fprintf(fLog, "Yaw              \t%f\n", flightDataF4->fYaw);

    fprintf(fLog, "Mach             \t%f\n", flightDataF4->fMach);
    fprintf(fLog, "Indicated Airspd \t%f\n", flightDataF4->fKias);
    fprintf(fLog, "True Airspeed  \t%f\n", flightDataF4->fVt);

    fprintf(fLog, "G Load           \t%f\n", flightDataF4->fGs);

    fprintf(fLog, "Wind               \t%f\n", flightDataF4->fWindOffset);

    fprintf(fLog, "Nozzle Position  \t%f\n", flightDataF4->fNozzlePos);
    fprintf(fLog, "Turbine Inlet Temp \t%f\n", flightDataF4->fFtit);
    fprintf(fLog, "RPM              \t%f \n", flightDataF4->fRpm);

    fprintf(fLog, "FuelFlow         \t%f \n", flightDataF4->fFuelFlow);
    fprintf(fLog, "Internal Fuel    \t%f \n", flightDataF4->fInternalFuel);
    fprintf(fLog, "External Fuel  \t%f \n", flightDataF4->fExternalFuel);
    fprintf(fLog, "Aft Fuel          \t%f \n", flightDataF4->fAftFuel);
    fprintf(fLog, "Fwd Fuel          \t%f \n", flightDataF4->fFwdFuel);
    fprintf(fLog, "Total Fuel       \t%f \n", flightDataF4->fTotalFuel);
    fprintf(fLog, "EPU Fuel         \t%f \n", flightDataF4->fEpuFuel);

    fprintf(fLog, "Oil pressure      \t%f\n", flightDataF4->fOilPressure);

    fprintf(fLog, "Gear Position    \t%f\n", flightDataF4->fGearPos);
    fprintf(fLog, "Nose Gear Position\t%f\n", flightDataF4->fNoseGearPos);
    fprintf(fLog, "Left Gear Position\t%f\n", flightDataF4->fLeftGearPos);
    fprintf(fLog, "Right Gear Position\t%f\n", flightDataF4->fRightGearPos);

    fprintf(fLog, "Flare Count      \t%f \n", flightDataF4->fFlareCount);
    fprintf(fLog, "Chaff Count      \t%f \n", flightDataF4->fChaffCount);

    fprintf(fLog, "ADI ILS Horizontal\t%f \n", flightDataF4->fAdiIlsHorPos);
    fprintf(fLog, "ADI ILS Vertical\t%f \n", flightDataF4->fAdiIlsVerPos);
    fprintf(fLog, "HSI Course State \t%d \n", flightDataF4->iCourseState);
    fprintf(fLog, "HSI Heading State \t%d \n", flightDataF4->iHeadingState);
    fprintf(fLog, "HSI Total States \t%d \n", flightDataF4->iTotalStates);
    fprintf(fLog, "HSI Course Deviation\t%f \n", flightDataF4->fCourseDeviation);
    fprintf(fLog, "HSI Desired Course\t%f \n", flightDataF4->fDesiredCourse);
    fprintf(fLog, "HSI Distance to WP\t%f \n", flightDataF4->fDistanceToBeacon);
    fprintf(fLog, "HSI Bearing to WP\t%f \n", flightDataF4->fBearingToBeacon);
    fprintf(fLog, "HSI Current Heading\t%f \n", flightDataF4->fCurrentHeading);
    fprintf(fLog, "HSI Desired Heading\t%f \n", flightDataF4->fDesiredHeading);
    fprintf(fLog, "HSI Deviation Limit\t%f \n", flightDataF4->fDeviationLimit);
    fprintf(fLog, "HSI Localizer Course\t%f \n", flightDataF4->fLocalizerCourse);
    fprintf(fLog, "HSI Airbase x  \t%f \n", flightDataF4->fAirbaseX);
    fprintf(fLog, "HSI Airbase y  \t%f \n", flightDataF4->fAirbaseY);
    fprintf(fLog, "HSI Total Values \t%f \n", flightDataF4->fTotalValues);
    fprintf(fLog, "Trim Pitch       \t%f \n", flightDataF4->fTrimPitch);
    fprintf(fLog, "Trim Roll        \t%f \n", flightDataF4->fTrimRoll);
    fprintf(fLog, "Trim Yaw         \t%f \n", flightDataF4->fTrimYaw);

    fprintf(fLog, "\nDED \t\t%s \n", flightDataF4->sDedLines[0]);
    fprintf(fLog, "DED \t\t%s \n", flightDataF4->sDedLines[1]);
    fprintf(fLog, "DED \t\t%s \n", flightDataF4->sDedLines[2]);
    fprintf(fLog, "DED \t\t%s \n", flightDataF4->sDedLines[3]);
    fprintf(fLog, "DED \t\t%s \n\n", flightDataF4->sDedLines[4]);

    fprintf(fLog, "\nPFL \t\t%s \n", flightDataF4->sPflLines[0]);
    fprintf(fLog, "PFL \t\t%s \n", flightDataF4->sPflLines[1]);
    fprintf(fLog, "PFL \t\t%s \n", flightDataF4->sPflLines[2]);
    fprintf(fLog, "PFL \t\t%s \n", flightDataF4->sPflLines[3]);
    fprintf(fLog, "PFL \t\t%s \n\n", flightDataF4->sPflLines[4]);

    fprintf(fLog, "AUX TACAN        \t%d \n", flightDataF4->iAuxTacChan);
    fprintf(fLog, "UFC TACAN        \t%d \n", flightDataF4->iUfcTacChan);

    fprintf(fLog, "Speed brake      \t%f \n", flightDataF4->fSpeedBrake);

    // RWR section
    fprintf(fLog, "RWR Objects      \t%d \n", flightDataF4->iRwrObjectCount);
    for (int i = 0; i < flightDataF4->iRwrObjectCount; i++) {
      fprintf(fLog, "Symbol \t\t%d   \t%d \n", i, flightDataF4->iRwrSymbol[i]);
      fprintf(fLog, "Bearing \t%d    \t%f \n", i, flightDataF4->fBearing[i]);
      fprintf(fLog, "Missle Act \t%d \t%d \n", i, flightDataF4->iMissileActivity[i]);
      fprintf(fLog, "Missle Launch \t%d\t%d \n", i, flightDataF4->iMissileLaunch[i]);
      fprintf(fLog, "Selected \t%d   \t%d \n", i, flightDataF4->iSelected[i]);
      fprintf(fLog, "Lethality \t%d  \t%f \n", i, flightDataF4->fLethality[i]);
      fprintf(fLog, "New Detection \t%d   \t%d \n", i, flightDataF4->iNewDetection[i]);
      fprintf(fLog, "------------------------------------\n");
    }

    fprintf(fLog, "\nMain Pwr Switch\t%d \n", flightDataF4->iMainPower);
    fprintf(fLog, "Falcon Version \t%d \n\n", flightDataF4->iFalconVersion);

    if(flightDataBms != NULL) {
      fprintf(fLog, "BMS Shared Mem Version \t%d\n\n",flightDataBms->VersionNum);
      fprintf(fLog, "Nozzle Pos. Engine 2\t%f \n", flightDataBms->nozzlePos2);   // Ownship engine nozzle2 percent open (0-100)
      fprintf(fLog, "RPM Engine 2\t\t%f\n", flightDataBms->rpm2);         // Ownship engine rpm2 (Percent 0-103)
      fprintf(fLog, "FTIT Engine 2\t\t%f\n", flightDataBms->ftit2);        // Ownship Forward Turbine Inlet Temp2 (Degrees C)
      fprintf(fLog, "Oil Press Engine 2\t%f\n", flightDataBms->oilPressure2); // Ownship Oil Pressure2 (Percent 0-100)
      // if BMS 4.33
      fprintf(fLog, "Fuel Flow 2\t\t%f\n", flightDataBms->fuelFlow2);
      fprintf(fLog, "VTOL angle\t\t%f\n", flightDataBms->vtolPos);
      // endif
      fprintf(fLog, "Nav Mode \t\t0x%x\n", flightDataBms->navMode);  // current mode selected for HSI/eHSI
      fprintf(fLog, "Baro Altitude\t%f\n", flightDataBms->fBaroAlt);
      fprintf(fLog, "TACAN UFC Band\t0x%x\n",flightDataBms->tacanInfo[0]);
      fprintf(fLog, "TACAN AUX Band\t0x%x\n",flightDataBms->tacanInfo[1]);
      fprintf(fLog, "Alt. Calibration\t%d\n",flightDataBms->AltCalReading);
      if(flightDataBms->altBits == FlightDataBMS::CalType) {
        fprintf(fLog, "Calibrated Altitude\n");
      } else {
        fprintf(fLog, "Pneumatic Altitude\n");
      }
      fprintf(fLog, "Power State\t0x%x\n", flightDataBms->powerBits);
      fprintf(fLog, "Blinkenbits\t0x%x\n", flightDataBms->blinkBits);
      fprintf(fLog, "BUP UHF Preset\t%d\n", flightDataBms->BupUhfPreset);
      fprintf(fLog, "BUP UHF Freq.\t%d\n", flightDataBms->BupUhfFreq);
      fprintf(fLog, "Cabin Altitude\t%f\n", flightDataBms->cabinAlt);
      fprintf(fLog, "Hyd. Pressure A\t%f\n", flightDataBms->hydPressureA);
      fprintf(fLog, "Hyd. Pressure B\t%f\n", flightDataBms->hydPressureB);
      fprintf(fLog, "Leading Edge\t%f\n", flightDataBms->lefPos);
      fprintf(fLog, "Trailing Edge\t%f\n", flightDataBms->tefPos);
      fprintf(fLog, "Time \t\t%d\n", flightDataBms->currentTime);
      fprintf(fLog, "A/C Type\t%d\n", flightDataBms->vehicleACD);

      for(int i= 0; i < flightDataBms->pilotsOnline; i++) {
        fprintf(fLog, "%d\t%s\t%x\n",(i+1),flightDataBms->pilotsCallsign[i],flightDataBms->pilotsStatus[i]);
      }
    }

  }

  // close link
  fprintf(fLog, "close shared memory mapping dump file...\n");
  fclose(fLog);

  return 0;
}

/**
  writes data intended for serial interface to file
  \return error code
*/
int FalconSMR::dumpData(unsigned int iLength)
{
  FILE *fDebug = NULL;
  fDebug = fopen("d:\\falconSMR_raw.txt", "wb+");

  if (fDebug == NULL)
  {
    return ERROR_FILE_NOT_FOUND;
  }

  fprintf(fDebug, "cData stream :\r\n");

  fwrite((const char*)cData, sizeof(char), iLength, fDebug);
  fflush(fDebug);

  // close link
  fprintf(fDebug, "\r\nEOF\r\n");
  fclose(fDebug);
  fDebug = NULL;

  return ERROR_OK;
}
