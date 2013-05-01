/*
 * InputController.cpp
 *
 *  Created on: Apr 22, 2013
 *      Author: Maiev
 */

#include "InputController.h"
#include "../System/GameEngine.h"
#include "../Interface/TerrainMenu.h"
#include "../Entity/DynamicEntity.h"
#include "Map.h"
#include "Cell.h"
#include <iostream>

InputController::InputController(GameEngine* eng) : eng_ptr(eng) {
  win_ptr = eng_ptr->getWindow();
  eng->getRes()->addResource(TILE_HIGH_KEY, TILE_HIGH);
  tilehighlight.setTexture(*(eng->getRes()->getResource(TILE_HIGH_KEY)));
  terrainhud_ptr = eng_ptr->getHUD()->getTerrainHUD();

  inputtimer.resetClock();

  //set the beginning cell to be the one that the main unit is on
  //updateCell();
}

InputController::~InputController() {
  // TODO Auto-generated destructor stub
}

void InputController::setMap(Map* mp) {
  map_ptr = mp;
  selected = map_ptr->getUnit();
}

bool InputController::setCurrentCell(int x, int y) {
  Cell* c = map_ptr->getCell(x, y);
  inputtimer.resetClock();

  if (c != 0) {
    cur_cell = c;
    tilehighlight.setPosition(sf::Vector2f(cur_cell->getLoc()));
    return true;
  }
  return false;
}

void InputController::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow()-1, cur_cell->getCol())) updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol()-1)) updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow()+1, cur_cell->getCol())) updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol()+1)) updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    moveUnit(dir::UP);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    moveUnit(dir::DOWN);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    moveUnit(dir::LEFT);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && inputtimer.getElapsedTime() > INPUT_DELAY) {
    moveUnit(dir::RIGHT);
  }

}

void InputController::moveUnit(dir::Direction d) {
  inputtimer.resetClock();
  if (selected == 0) return;

  Cell* player_cell = selected->getCurCell();
  if (player_cell == 0) return;

  Cell* new_cell;

  if (d == dir::UP)
    new_cell = map_ptr->getCell(player_cell->getRow()-1, player_cell->getCol());
  else if (d == dir::DOWN)
    new_cell = map_ptr->getCell(player_cell->getRow()+1, player_cell->getCol());
  else if (d == dir::LEFT)
    new_cell = map_ptr->getCell(player_cell->getRow(), player_cell->getCol()-1);
  else if (d == dir::RIGHT)
    new_cell = map_ptr->getCell(player_cell->getRow(), player_cell->getCol()+1);

  if (new_cell == 0) return;

  player_cell->unit = 0;
  selected->setTile(new_cell);
  new_cell->unit = selected;
}

void InputController::updateCell() {
  eng_ptr->getGameCam()->smoothMove(sf::Vector2f(cur_cell->getCenter()), 0.3f);
  terrainhud_ptr->setTile(cur_cell->getTerrain());
}

sf::Vector2i InputController::getCurrentCenter() {
  if (cur_cell == 0) {
    cout << "WARNING: current cell is null - InputController" << endl;
    return sf::Vector2i(0,0);
  }

  return cur_cell->getCenter();
}

void InputController::render() {
  win_ptr->draw(tilehighlight);
}
