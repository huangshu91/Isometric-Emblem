/*
 * MenuController.cpp
 *
 *  Created on: May 30, 2013
 *      Author: Maiev
 */

#include "MenuController.h"
#include "InputController.h"
#include "../HUDWidget/MenuWidget.h"
#include "../Entity/DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Gamestate/PlayState.h"
#include "../Util/Constants.h"

MenuController::MenuController() {
  eng_ptr = 0;
  win_ptr = 0;
  selected = 0;
  focus = menucon::NONE;
  base_menu = 0;
  unitcon = 0;
  cur_menu = 0;
}

MenuController::~MenuController() {
}

void MenuController::setup(GameEngine* eng, InputController* ic) {
  eng_ptr = eng;
  win_ptr = eng->getWindow();
  unitcon = ic;

  base_menu = eng->getHUD()->getMenuHUD();
}

void MenuController::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
    && timer.getElapsedTime() > INPUT_DELAY) {
    timer.resetClock();
    base_menu->select(base_menu->getChoice()-1);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
    && timer.getElapsedTime() > INPUT_DELAY) {
    timer.resetClock();
    base_menu->select(base_menu->getChoice()+1);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
    && timer.getElapsedTime() > INPUT_DELAY) {
    timer.resetClock();
    base_menu->selectAction();
    action();
  }
}

void MenuController::action() {
  if (base_menu->getChoiceName().compare("ATTACK")) {
    base_menu->disable();
    //eng_ptr->getPlayState()->changePhase(playstate::ENEMY);
  }

}

void MenuController::render() {

}

void MenuController::enable(DynamicEntity* e, menucon::Type t) {
  if (e) selected = e;
  focus = t;
  base_menu->enable();
}
