/*
 * formatedClock.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: Maiev
 */
#include <cmath>
#include "FormatClock.h"
using namespace std;

FormatClock::FormatClock() {
  _paused = false;
  _breaktime = 0;
}

FormatClock::~FormatClock() {
}

bool FormatClock::isPaused() {
  if (_paused == false) {
    return false;
  }

  //paused == true
  else
    return true;
}

void FormatClock::setBreakTime() {
  _breaktime = _internalclock.getElapsedTime().asSeconds();
}

float FormatClock::timeSinceBreak() {
  return (_internalclock.getElapsedTime().asSeconds() - _breaktime);
}

string FormatClock::getFormatTime() {
  float _currenttime = _internalclock.getElapsedTime().asSeconds();

  int _hours = (int) floor(_currenttime / 3600);

  _currenttime = fmod(_currenttime, 3600);

  int _minutes = (int) floor(_currenttime / 60);

  _currenttime = fmod(_currenttime, 60);
  stringstream ss;
  ss << _hours << ":" << _minutes << ":" << _currenttime;

  return ss.str();
}

float FormatClock::getElapsedTime() {
  return _internalclock.getElapsedTime().asSeconds();
}

void FormatClock::resetClock() {
  _internalclock.restart();
}
