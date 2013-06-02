/*
 * DayCycle.cpp
 *
 *  Created on: Jun 2, 2013
 *      Author: Maiev
 */

#include "DayCycle.h"
#include "../System/GameEngine.h"

sf::Color bgcolor[] = { sf::Color(163,208,228), sf::Color(65,194,249),
                        sf::Color(14,64,85), sf::Color(100,128,139) };

DayCycle::DayCycle() {
  eng_ptr = 0;
  win_ptr = 0;
  time = 0;
}

DayCycle::~DayCycle() {
  // TODO Auto-generated destructor stub
}

void DayCycle::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng->getWindow();
}

void DayCycle::update() {
  time += 1;
  if (time > 4) time = 0;
}

void DayCycle::render() {
  win_ptr->clear(bgcolor[time]);
}
