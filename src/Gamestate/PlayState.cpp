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
#include "../Controller/MenuController.h"
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

void PlayState::setup() {
  mc.setup(eng_ptr, input);
  sc.setup(eng_ptr);
  input->setup(eng_ptr);

  level->loadMap("1");
  level->setupEntity();

  input->setMap(level);
  input->setCurrentCell(3,3);
  input->updateCell(KEY_PAN_SENS);
  ai->setMap(level);

  eng_ptr->getGameCam()->setCenter(sf::Vector2f(input->getCurrentCenter()));
  eng_ptr->getGameCam()->zoomCamera(0.8f);

  sf::Vector2f loc(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

  effect::param op;
  op.s = "TEST";
  op.loc = loc;
  op.fade = true;
  eng_ptr->getEffect()->addEffectObj(effect::TEXT, op);
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
    level->newTurn();
    changePhase(playstate::PLAYER);
    level->checkLoss();
    input->reset();
    round_num++;
  }
  else if (phase == playstate::CONVO) {
    sc.enable();
  }
  else if (phase == playstate::UNITDEATH) {
    //exp and stuff
    phase = turn;

    //finishTransition();
  }
  else if (phase == playstate::MENU) {
    mc.enable();
  }
  else if (phase == playstate::FIGHT) {
    // set some hud stuff?
  }
  else if (phase == playstate::FINISHFIGHT) {
    // exp stuff here as well
    phase = turn;
  }
  else if (phase == playstate::RETURN) {
    phase = turn;
    input->returnDelay();
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
    else if (phase == playstate::MENU) {
      mc.update();
    }
    else if (phase == playstate::CONVO) {
      sc.update();
    }
  }

  eng_ptr->getGameCam()->update();
  eng_ptr->getEffect()->update();
}

void PlayState::render() {
  //eng_ptr->getWindow()->setView(*(eng_ptr->getGameCam()->GetView()));
  level->render();
  input->render();
  level->renderAdd();
  level->renderUnits();

  eng_ptr->getHUD()->render();
  eng_ptr->getEffect()->render();
}
