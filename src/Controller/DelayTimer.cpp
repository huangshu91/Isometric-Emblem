/*
 * DelayTimer.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Maiev
 */

#include "DelayTimer.h"

DelayTimer::DelayTimer() {
  timer_set = false;
  duration = 0;
}

DelayTimer::~DelayTimer() {
  // TODO Auto-generated destructor stub
}

bool DelayTimer::setTimer(float dur) {
  if (!timer_set) {
    timer.resetClock();
    duration = dur;
    timer_set = true;
    return false;
  }

  if (timer.getElapsedTime() >= duration) {
    timer_set = false;
    return true;
  }

  return false;
}
