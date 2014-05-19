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

class Logger {
public:
  Logger();
  ~Logger();

  //info message
  void i(std::string msg);

  //error message
  void e(std::string msg);

  //debug message
  void d(std::string msg);

  //safe even if log not open
  void close() { logg.close(); };

private:
  void printheader(char type);

  std::ofstream logg;
  FormatClock gameClock;

  bool debugEnabled;
  char prevLogType;
};

#endif /* LOGGER_H_ */
