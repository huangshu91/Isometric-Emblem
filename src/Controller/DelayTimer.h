/*
 * DelayTimer.h
 *
 *  Created on: May 18, 2014
 *      Author: Maiev
 */

#ifndef DELAYTIMER_H_
#define DELAYTIMER_H_
#include "../Util/FormatClock.h"

class DelayTimer {
public:
  DelayTimer();
  virtual ~DelayTimer();

  bool setTimer(double dur);

private:
  FormatClock timer;
  bool        timer_set;

  double duration;
};

#endif /* DELAYTIMER_H_ */
