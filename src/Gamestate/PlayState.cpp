/*
 * PlayState.cpp
 *
 *  Created on: May 11, 2013
 *      Author: Maiev
 */

#include "PlayState.h"
#include "../Levelmap/Map.h"
#include "../Controller/InputController.h"
#include "../System/GameEngine.h"

PlayState::PlayState(GameEngine* eng) : GameState(eng) {
  stateId = gamestate::PLAY;
  level = new Map(eng_ptr);
  input = new InputController(eng_ptr);
  phase = gamestate::PLAYER;
}

PlayState::~PlayState() {
  delete level;
  delete input;
}

// eventually load from file
void PlayState::setup() {
  level->setDimensions(20,7);
  level->setupEntity();
  input->setMap(level);
  input->setCurrentCell(1,3);

  eng_ptr->getGameCam()->setCenter(sf::Vector2f(input->getCurrentCenter()));
  eng_ptr->getGameCam()->zoomCamera(0.8f);

  if (phase == gamestate::PLAYER) input->update();
  if (phase == gamestate::ENEMY) { phase = gamestate::PLAYER; }
}

void PlayState::changePhase(gamestate::Playphase next) {
  phase = next;
}

void PlayState::update() {
  input->update();
  eng_ptr->getGameCam()->update();
}

void PlayState::render() {
  eng_ptr->getWindow()->setView(*(eng_ptr->getGameCam()->GetView()));

  level->render();
  input->render();
  level->renderUnits();

  eng_ptr->getHUD()->render();
}