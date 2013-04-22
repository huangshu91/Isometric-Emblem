/*
 * InputController.cpp
 *
 *  Created on: Apr 22, 2013
 *      Author: Maiev
 */

#include "InputController.h"
#include "../Util/Constants.h"
#include "../System/GameEngine.h"
#include "Map.h"
#include "Cell.h"
#include <iostream>

InputController::InputController(GameEngine* eng) : eng_ptr(eng) {
  win_ptr = eng_ptr->getWindow();
  tilehighlight.setTexture(*(eng->getRes()->getResource(TILE_HIGH_KEY)));

  inputtimer.resetClock();
}

InputController::~InputController() {
  // TODO Auto-generated destructor stub
}

void InputController::setCurrentCell(int x, int y) {
  Cell* c = map_ptr->getCell(x, y);

  if (c != 0) {
    cur_cell = c;
    tilehighlight.setPosition(sf::Vector2f(cur_cell->getLoc()));
  }
}

void InputController::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    setCurrentCell(cur_cell->getRow()-1, cur_cell->getCol());
    inputtimer.resetClock();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    setCurrentCell(cur_cell->getRow(), cur_cell->getCol()-1);
    inputtimer.resetClock();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    setCurrentCell(cur_cell->getRow()+1, cur_cell->getCol());
    inputtimer.resetClock();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    setCurrentCell(cur_cell->getRow(), cur_cell->getCol()+1);
    inputtimer.resetClock();
  }
}

void InputController::render() {
  win_ptr->draw(tilehighlight);

}
