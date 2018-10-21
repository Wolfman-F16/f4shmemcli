/*
 * swtimer.cpp
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#include "windows.h"
#include "SwTimer.h"

void CSwTimer::setTime(uint8_t idx, uint32_t timeVal) {
    timerArray[idx] = timeVal;
}

bool CSwTimer::checkTimeout(uint8_t idx) {
  if( timerArray[idx] == 0) {
    return true;
  }
  return false;
}

void CSwTimer::updateTime() {
  uint8_t i;
  static uint32_t oldTime = 0;
  uint32_t newTime = timeGetTime();
  uint32_t delta = newTime - oldTime;

  for(i = 0; i < 32; i++) {
    if(timerArray[i] > delta) {
      timerArray[i] = timerArray[i] - delta;
    } else {
      timerArray[i] = 0;
    }
  }
  oldTime = newTime;
}
