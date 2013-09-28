/*
 * SkitController.cpp
 *
 *  Created on: Jul 27, 2013
 *      Author: Maiev
 */

#include "SkitController.h"
#include "../Util/Constants.h"
#include "../System/GameEngine.h"
#include "../Gamestate/PlayState.h"

SkitController::SkitController() {
  eng_ptr = 0;
  win_ptr = 0;
  sw_ptr = 0;
}

SkitController::~SkitController() {
  // TODO Auto-generated destructor stub
}

void SkitController::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng->getWindow();

  sw_ptr = eng->getHUD()->getSpeechHUD();
}

void SkitController::enable() {
  sw_ptr->enable();
  eng_ptr->getHUD()->getTerrainHUD()->disable();
}

void SkitController::update() {
  sw_ptr->update();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
    && timer.getElapsedTime() > INPUT_DELAY) {
    timer.resetClock();
    sw_ptr->nextPage();

    if (sw_ptr->isFinished()) {
      eng_ptr->getPlayState()->changePhase(playstate::RETURN);
      sw_ptr->disable();
      eng_ptr->getHUD()->getTerrainHUD()->enable();
    }
  }
}

