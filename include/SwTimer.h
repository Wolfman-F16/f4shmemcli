/*
 * SwTimer.h
 *
 *  Created on: Dec 1, 2015
 *
 * Copyright: (c) 2011 by Wolfgang Engelhard
 * License: GNU GPL v2 (see License.txt)
 */

#ifndef INCLUDE_SWTIMER_H_
#define INCLUDE_SWTIMER_H_

#include <inttypes.h>

class CSwTimer {
public:
  void setTime(uint8_t, uint32_t);
  bool checkTimeout(uint8_t);
  void updateTime();

private:
  uint32_t timerArray[32];
};


#endif /* INCLUDE_SWTIMER_H_ */
