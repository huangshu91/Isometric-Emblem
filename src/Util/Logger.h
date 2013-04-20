/*
 * Logger.h
 *
 *  Created on: Jun 24, 2012
 *      Author: Maiev
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "Constants.h"
#include "FormatClock.h"
#include <iostream>
#include <fstream>
using namespace std;

class Logger {
public:
  Logger(FormatClock *clock);
  ~Logger();

  //info message
  void i(string msg);

  //error message
  void e(string msg);

  //debug message
  void d(string msg);

private:
  void printheader(char type);

  ofstream log;
  FormatClock *gameClockPtr;

  bool debugEnabled;
  char prevLogType;
};

#endif /* LOGGER_H_ */
