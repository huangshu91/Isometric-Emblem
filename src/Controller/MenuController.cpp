/*
 * MenuController.cpp
 *
 *  Created on: May 30, 2013
 *      Author: Maiev
 */

#include "MenuController.h"
#include "../Entity/DynamicEntity.h"
#include "../Util/Constants.h"

MenuController::MenuController() {
  eng_ptr = 0;
  win_ptr = 0;
  selected = 0;
  focus = menucon::NONE;
}

MenuController::~MenuController() {
  // TODO Auto-generated destructor stub
}

void MenuController::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng->getWindow();
}

void MenuController::update() {

}

void MenuController::render() {

}

void MenuController::enable(DynamicEntity* e, menucon::Type t) {
  selected = e;
  focus = t;
}
