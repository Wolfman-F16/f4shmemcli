/*
 * ConfigData.cpp
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */
/*
  int getComPort();
  int getBaudRate();
  int getBits();
  int getStopBit();
  int getParity();
  int readFile();
*/

#include "ConfigData.h"
#include <windows.h>

using namespace std;

/**
constructor, setting default values
*/
CConfigData::CConfigData()
    :m_sComPort("comport"),
    m_sBaudrate("baudrate"),
    m_sBits("bits"),
    m_sParity("parity"),
    m_sStopBit("stopbit")

{
  Log::getInstance()->debug("setting default values for serial comm\n");
  iComPort = 1;
  iBaudRate = 38400;
  iBits = 8;
  iStopBit = ONESTOPBIT;	// one stop bit (comes from windows.h)
  iParity = 0;  // no parity
  iFileRead = 0;  // not read yet
}

/**
destructor, empty
*/
CConfigData::~CConfigData()
{

}

unsigned int CConfigData::getComPort()
{
  if (iFileRead)
  {
    return iComPort;
  }
  else
  {
    readFile();
    return iComPort;
  }

}

unsigned int CConfigData::getBaudRate()
{
  if (iFileRead)
  {
    return iBaudRate;
  }
  else
  {
    readFile();
    return iBaudRate;
  }
}

unsigned int CConfigData::getBits()
{
  if (iFileRead)
  {
    return iBits;
  }
  else
  {
    readFile();
    return iBits;
  }
}

unsigned int CConfigData::getStopBit()
{
  if (iFileRead)
  {
    return iStopBit;
  }
  else
  {
    readFile();
    return iStopBit;
  }
}

unsigned int CConfigData::getParity()
{
  if (iFileRead)
  {
    return iParity;
  }
  else
  {
    readFile();
    return iParity;
  }
}

/**
reads ini file, containing serial port config data
\return error code
*/
int CConfigData::readFile()
{
  const string sFileName = "smr.ini";	// TODO put his up please (constant string)
  fstream pFile;
  char *pLineBuffer = new char[255];

  pFile.open(sFileName.c_str(), fstream::in);
  if (pFile.is_open())
  {
    std::string sString;
    while (pFile.good())
    {
      pFile.getline(pLineBuffer, 254);
      sString = pLineBuffer;
      if (sString.find(m_sComPort) == 0)
      {
        sString = sString.substr(sString.find_first_of("=")+1, sString.size());	// TODO delimiter constant
        iComPort = atoi(sString.c_str());
      }
      if (sString.find(m_sBaudrate) == 0)
      {
        sString = sString.substr(sString.find_first_of("=")+1, sString.size());
        iBaudRate = atoi(sString.c_str());
      }
      if (sString.find(m_sBits) == 0)
      {
        sString = sString.substr(sString.find_first_of("=")+1, sString.size());
        iBits = atoi(sString.c_str());
      }
      if (sString.find(m_sParity) == 0)
      {
        sString = sString.substr(sString.find_first_of("=")+1, sString.size());
        iParity= atoi(sString.c_str());
      }
      if (sString.find(m_sStopBit) == 0)
      {
        sString = sString.substr(sString.find_first_of("=")+1, sString.size());
        iStopBit = atoi(sString.c_str());
      }
    }
  }
  else
  {
    Log::getInstance()->debug("error reading configuration file\n");
    delete pLineBuffer;
    return 1;
  }

  // release your resources
  delete pLineBuffer;
  pFile.close();

  iFileRead = 1;

  return 0;
}
