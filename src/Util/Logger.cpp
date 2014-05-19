/*
 * Logger.cpp
 *
 *  Created on: Jun 24, 2012
 *      Author: Maiev
 */
#include "Logger.h"
#include <iostream>
using namespace std;

Logger::Logger() {
  logg.open(LOG_FILE.c_str(), ios_base::trunc);
  logg << "LOG SYSTEM FOR '" << GAME_LABEL << " VER-" << VERSION_NUM
      << " STARTED." << endl;
  cout << "LOG SYSTEM FOR '" << GAME_LABEL << " VER-" << VERSION_NUM
      << " STARTED." << endl;
  debugEnabled = true;
  prevLogType = ' ';
  gameClock.resetClock();
}

Logger::~Logger() {
  logg << "LOG SYSTEM CLOSING." << endl;
  logg.close();
}

void Logger::i(string msg) {
  if (prevLogType != 'i') {
    printheader('i');
  }

  if (DEBUG) cout << gameClock.getFormatTime() << " - " << msg << endl;
  logg << gameClock.getFormatTime() << " - " << msg << endl;
  prevLogType = 'i';
}

void Logger::e(string msg) {
  if (prevLogType != 'e') {
    printheader('e');
  }

  if (DEBUG) cout << gameClock.getFormatTime() << " - " << msg << endl;
  logg << gameClock.getFormatTime() << " - " << msg << endl;
  prevLogType = 'e';
}

void Logger::d(string msg) {
  if (debugEnabled == false) {
    return;
  }

  if (prevLogType != 'd') {
    printheader('d');
  }

  if (DEBUG) cout << gameClock.getFormatTime() << " - " << msg << endl;
  logg << gameClock.getFormatTime() << " - " << msg << endl;
  prevLogType = 'd';
}

void Logger::printheader(char type) {
  logg << "============ ";

  switch (type) {
  case ('i'):
    logg << "INFO ";
    break;
  case ('e'):
    logg << "ERROR ";
    break;
  case ('d'):
    logg << "DEBUG ";
    break;
  default:
    logg << "EXTRA ";
    break;
  }

  logg << "============" << endl;
}
