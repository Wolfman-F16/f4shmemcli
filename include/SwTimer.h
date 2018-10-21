/*
 * SwTimer.h
 *
 *  Created on: Dec 1, 2015
 *      Author: wolfgang
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
