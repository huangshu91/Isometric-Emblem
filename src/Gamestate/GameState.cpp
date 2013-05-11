/*
 * GameState.cpp
 *
 *  Created on: May 11, 2013
 *      Author: Maiev
 */

#include "GameState.h"
#include "../System/GameEngine.h"

GameState::GameState(GameEngine* eng) : eng_ptr(eng) {
  win_ptr = eng_ptr->getWindow();
  stateId = gamestate::UNINIT;
}
