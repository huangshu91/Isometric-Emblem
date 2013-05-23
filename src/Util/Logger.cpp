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
  log.open(LOG_FILE.c_str(), ios_base::trunc);
  log << "LOG SYSTEM FOR '" << GAME_LABEL << " VER-" << VERSION_NUM
      << " STARTED." << endl;
  debugEnabled = true;
  prevLogType = ' ';
  gameClock.resetClock();
}

Logger::~Logger() {
  log << "LOG SYSTEM CLOSING." << endl;
  log.close();
}

void Logger::i(string msg) {
  if (prevLogType != 'i') {
    printheader('i');
  }

  if (DEBUG) cout << gameClock.getFormatTime() << " - " << msg << endl;
  log << gameClock.getFormatTime() << " - " << msg << endl;
  prevLogType = 'i';
}

void Logger::e(string msg) {
  if (prevLogType != 'e') {
    printheader('e');
  }

  if (DEBUG) cout << gameClock.getFormatTime() << " - " << msg << endl;
  log << gameClock.getFormatTime() << " - " << msg << endl;
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
  log << gameClock.getFormatTime() << " - " << msg << endl;
  prevLogType = 'd';
}

void Logger::printheader(char type) {
  log << "============ ";

  switch (type) {
  case ('i'):
    log << "INFO ";
    break;
  case ('e'):
    log << "ERROR ";
    break;
  case ('d'):
    log << "DEBUG ";
    break;
  default:
    log << "EXTRA ";
    break;
  }

  log << "============" << endl;
}
