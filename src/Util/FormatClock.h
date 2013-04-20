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
using namespace std;

/*
 * Wrapper for the sfml Clock class which has pause and start functionality.
 * Includes methods to format the second of the clock to hours/minutes for output.
 */
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
  string getFormatTime();

  float getElapsedTime();

private:
  sf::Clock* _internalclock;

  float _breaktime;
  bool _paused;
};

#endif /* FORMATCLOCK_H_ */
