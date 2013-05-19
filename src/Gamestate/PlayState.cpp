/*
 * PlayState.cpp
 *
 *  Created on: May 11, 2013
 *      Author: Maiev
 */

#include "PlayState.h"
#include "../Levelmap/Map.h"
#include "../Controller/InputController.h"
#include "../Controller/AIController.h"
#include "../System/GameEngine.h"

PlayState::PlayState(GameEngine* eng) : GameState(eng) {
  stateId = gamestate::PLAY;
  level = new Map(eng_ptr);
  input = new InputController(eng_ptr);
  ai = new AIController(eng_ptr);
  phase = gamestate::PLAYER;
  wait = false;
}

PlayState::~PlayState() {
  delete level;
  delete input;
  delete ai;
}

// eventually load from file
void PlayState::setup() {
  level->setDimensions(20,7);
  level->setupEntity();
  input->setMap(level);
  input->setCurrentCell(1,3);
  input->updateCell();
  ai->setMap(level);

  eng_ptr->getGameCam()->setCenter(sf::Vector2f(input->getCurrentCenter()));
  eng_ptr->getGameCam()->zoomCamera(0.8f);

}

void PlayState::changePhase(gamestate::Playphase next) {
  gamestate::Playphase prev = phase;
  phase = next;

  if (phase == gamestate::PLAYER || phase == gamestate::ENEMY) {
    if (eng_ptr->getHUD()->getWidget(PHASE_HUD)) {
      eng_ptr->getHUD()->getPhaseHUD()->changePhase(next);
      wait = true;
    }
  }

  if (phase == gamestate::NEWTURN) {
    level->resetUnits();
    changePhase(gamestate::PLAYER);
    level->checkLoss();
  }

  if (phase == gamestate::UNITDEATH) {
    // is there anything that needs to be handled here?
    // until exp is implemented, just switch back to previous state;
    phase = prev;
  }
}

void PlayState::finishTransition() {
  wait = false;
}

void PlayState::update() {
  if (!wait) {
    if (phase == gamestate::PLAYER) {
      input->update();
    }

    else if (phase == gamestate::ENEMY) {
      ai->update();
    }

    else if (phase == gamestate::LOSS) {
      // loss, menu options for player
      input->update();
    }
  }

  eng_ptr->getGameCam()->update();
}

void PlayState::render() {
  eng_ptr->getWindow()->setView(*(eng_ptr->getGameCam()->GetView()));

  level->render();
  input->render();
  level->renderUnits();

  eng_ptr->getHUD()->render();
}
