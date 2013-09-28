/*
 * Effect.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: Maiev
 */

#include "Effect.h"
#include "../System/GameEngine.h"

Effect::Effect() {
  type = effect::UNDEF;
  eng_ptr = 0;
  win_ptr = 0;

  bounce = false;
  fade = false;
}

Effect::~Effect() {
  // TODO Auto-generated destructor stub
}

void Effect::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng->getWindow();
}
