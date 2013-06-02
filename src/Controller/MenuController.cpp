/*
 * MenuController.cpp
 *
 *  Created on: May 30, 2013
 *      Author: Maiev
 */

#include "MenuController.h"
#include "../HUDWidget/MenuWidget.h"
#include "../Entity/DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Util/Constants.h"

MenuController::MenuController() {
  eng_ptr = 0;
  win_ptr = 0;
  selected = 0;
  focus = menucon::NONE;
  base_menu = 0;
}

MenuController::~MenuController() {
}

void MenuController::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng->getWindow();

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
  }
}

void MenuController::render() {

}

void MenuController::enable(DynamicEntity* e, menucon::Type t) {
  if (e) selected = e;
  focus = t;
  base_menu->enable();
}
