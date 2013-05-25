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
  paused = false;
  breaktime = 0;
}

FormatClock::~FormatClock() {
}

bool FormatClock::isPaused() {
  if (paused == false) {
    return false;
  }

  //paused == true
  else
    return true;
}

void FormatClock::setBreakTime() {
  breaktime = internalclock.getElapsedTime().asSeconds();
}

float FormatClock::timeSinceBreak() {
  return (internalclock.getElapsedTime().asSeconds() - breaktime);
}

string FormatClock::getFormatTime() {
  float currenttime = internalclock.getElapsedTime().asSeconds();

  int hours = (int) floor(currenttime / 3600);

  currenttime = fmod(currenttime, 3600);

  int minutes = (int) floor(currenttime / 60);

  currenttime = fmod(currenttime, 60);
  stringstream ss;
  ss << hours << "h_" << minutes << "m_" << currenttime;

  return ss.str();
}

float FormatClock::getElapsedTime() {
  return internalclock.getElapsedTime().asSeconds();
}

void FormatClock::resetClock() {
  internalclock.restart();
}
