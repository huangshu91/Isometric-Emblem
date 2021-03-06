/*
 * PhaseWidget.cpp
 *
 *  Created on: May 12, 2013
 *      Author: Maiev
 */

#include "PhaseWidget.h"
#include "../System/GameEngine.h"
#include "../Gamestate/PlayState.h"

PhaseWidget::PhaseWidget() {
  phase = playstate::PLAYER;

  timer.resetClock();
}

PhaseWidget::~PhaseWidget() {
  // TODO Auto-generated destructor stub
}

void PhaseWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  eng_ptr->getRes()->addResource(PHASE_PLAYER_KEY, PHASE_PLAYER);
  eng_ptr->getRes()->addResource(PHASE_ENEMY_KEY, PHASE_ENEMY);
  player_sprite.setTexture(*(eng_ptr->getRes()->getResource(PHASE_PLAYER_KEY)));
  enemy_sprite.setTexture(*(eng_ptr->getRes()->getResource(PHASE_ENEMY_KEY)));
  player_sprite.setOrigin(player_sprite.getLocalBounds().width/2,
      player_sprite.getLocalBounds().height/2);
  enemy_sprite.setOrigin(enemy_sprite.getLocalBounds().width/2,
      enemy_sprite.getLocalBounds().height/2);

  player_sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
  enemy_sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
}

void PhaseWidget::changePhase(playstate::Phase p) {
  phase = p;
  timer.resetClock();
  enable();
}

void PhaseWidget::render() {
  if (visible) {
    switch (phase) {
    case playstate::PLAYER:
      win_ptr->draw(player_sprite);
      break;
    case playstate::ENEMY:
      win_ptr->draw(enemy_sprite);
      break;
    case playstate::NEUTRAL:
      break;
    default:
      break;
    }
  }

  if (timer.getElapsedTime() >= PHASE_DUR) {
    disable();
    eng_ptr->getPlayState()->finishTransition();
  }
}
