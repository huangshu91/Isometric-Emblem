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
#include "../Entity/BattleManager.h"

PlayState::PlayState(GameEngine* eng) : GameState(eng) {
  stateId = gamestate::PLAY;
  level = new Map(eng_ptr);
  input = new InputController(eng_ptr);
  ai = new AIController(eng_ptr);
  phase = playstate::PLAYER;
  turn = playstate::PLAYER;
  wait = false;
  bm = eng_ptr->getBattle();
  round_num = 1;
}

PlayState::~PlayState() {
  delete level;
  delete input;
  delete ai;
}

// eventually load from file
void PlayState::setup() {
  //level->setDimensions(20,7);
  level->loadMap("1");
  level->setupEntity();

  input->setMap(level);
  input->setCurrentCell(3,3);
  input->updateCell();
  ai->setMap(level);

  eng_ptr->getGameCam()->setCenter(sf::Vector2f(input->getCurrentCenter()));
  eng_ptr->getGameCam()->zoomCamera(0.8f);
}

void PlayState::changePhase(playstate::Phase next) {
  phase = next;

  if (phase == playstate::PLAYER || phase == playstate::ENEMY) {
    if (eng_ptr->getHUD()->getWidget(PHASE_HUD)) {
      eng_ptr->getHUD()->getPhaseHUD()->changePhase(next);
      turn = phase;
      wait = true;
    }
  }

  if (phase == playstate::NEWTURN) {
    level->resetUnits();
    changePhase(playstate::PLAYER);
    level->checkLoss();
    round_num++;
  }

  if (phase == playstate::UNITDEATH) {
    // is there anything that needs to be handled here?
    // just switch back to previous state;
    phase = turn;

    //finishTransition();
  }

  if (phase == playstate::FIGHT) {
    // set some hud stuff?
  }

  if (phase == playstate::FINISHFIGHT) {
    // exp stuff here as well
    phase = turn;
  }
}

void PlayState::finishTransition() {
  wait = false;
}

void PlayState::update() {
  if (!wait) {
    if (phase == playstate::PLAYER) {
      input->update();
    }

    else if (phase == playstate::ENEMY) {
      ai->update();
    }

    else if (phase == playstate::LOSS) {
      // loss, menu options for player
      input->update();
    }

    else if (phase == playstate::FIGHT) {
      bm->update();
    }
  }

  eng_ptr->getGameCam()->update();
}

void PlayState::render() {
  eng_ptr->getWindow()->setView(*(eng_ptr->getGameCam()->GetView()));

  level->render();
  input->render();
  //level->renderUnits();
  level->renderAdd();
  level->renderUnits();

  eng_ptr->getHUD()->render();
}
