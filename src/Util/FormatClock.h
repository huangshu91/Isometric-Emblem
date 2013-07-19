/*
 * FormatClock.h
 *
 *  Created on: Jun 25, 2012
 *      Author: Maiev
 */

#ifndef FORMATCLOCK_H_
#define FORMATCLOCK_H_

#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <sstream>

class FormatClock {
public:
  FormatClock();
  ~FormatClock();
  void resetClock();
  bool isPaused();

  //calling pause on a paused clock does nothing
  //void PauseClock();

  //calling start on a running clock does nothing
  //void StartClock();

  //sets a breakpoint in the time and retrieved elapsed time since that point.
  void setBreakTime();
  float timeSinceBreak();

  //get the time as a string formatted in H:M:S.MS
  std::string getFormatTime();

  float getElapsedTime();

private:
  sf::Clock internalclock;

  float breaktime;
  bool paused;
};

#endif /* FORMATCLOCK_H_ */
