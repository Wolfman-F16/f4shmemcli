/**
header. reads ini file smr.ini
*/
#ifndef CONFIG_DATA_H
#define CONFIG_DATA_H

#include <cstdio>
#include <string>
#include <fstream> 
#include "Log.h"

class CConfigData
{
public:
  // constructor, destructor
  CConfigData();
  virtual ~CConfigData();

  // methods
  unsigned int getComPort();
  unsigned int getBaudRate();
  unsigned int getBits();
  unsigned int getStopBit();
  unsigned int getParity();

private:
  // constants
  const char* m_sComPort;
  const char* m_sBaudrate;
  const char* m_sBits;
  const char* m_sParity;
  const char* m_sStopBit;

  // members
  unsigned int iComPort;
  unsigned int iBaudRate;
  unsigned int iBits;
  unsigned int iStopBit;
  unsigned int iParity;
  int iFileRead;

  // methods
  int readFile();

};

#endif  // CONFIG_DATA_H
