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
  phase = gamestate::PLAYER;
  is_visible = false;

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

void PhaseWidget::changePhase(gamestate::Playphase p) {
  phase = p;
  timer.resetClock();
  is_visible = true;
}

void PhaseWidget::render() {
  if (is_visible) {
    switch (phase) {
    case gamestate::PLAYER:
      win_ptr->draw(player_sprite);
      break;
    case gamestate::ENEMY:
      win_ptr->draw(enemy_sprite);
      break;
    case gamestate::NEUTRAL:
      break;
    default:
      break;
    }
  }

  if (timer.getElapsedTime() >= PHASE_DUR) {
    is_visible = false;
    eng_ptr->getPlayState()->finishTransition();
  }
}
