/*
 * EffectManager.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: Maiev
 */

#include "EffectManager.h"
#include "GameEngine.h"

EffectManager::EffectManager() {
  eng_ptr = 0;
  win_ptr = 0;
  num_effects = 0;
}

EffectManager::~EffectManager() {
  // TODO Auto-generated destructor stub
}

void EffectManager::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();
}
