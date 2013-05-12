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
#include "../Gamestate/PlayState.h"
#include "../Util/UtilFunc.h"
#include "../Levelmap/Map.h"
#include "../Levelmap/Cell.h"
#include <iostream>
#include <cstdlib>

InputController::InputController(GameEngine* eng) : eng_ptr(eng) {
  win_ptr = eng_ptr->getWindow();
  eng->getRes()->addResource(TILE_HIGH_KEY, TILE_HIGH);
  tilehighlight.setTexture(*(eng->getRes()->getResource(TILE_HIGH_KEY)));
  terrainhud_ptr = eng_ptr->getHUD()->getTerrainHUD();
  map_ptr = 0;
  cur_cell = 0;
  selected = 0;
  state = inputstate::FREE;

  inputtimer.resetClock();
}

InputController::~InputController() {
  // TODO Auto-generated destructor stub
}

void InputController::setMap(Map* mp) {
  map_ptr = mp;
}

bool InputController::setCurrentCell(int x, int y) {
  Cell* c = map_ptr->getCell(x, y);
  inputtimer.resetClock();

  if (state == inputstate::MOVE
      && cellDist(selected->getCurCell(), c)
          > selected->getRange(range::MOVE)) {
    return false;
  }

  if (state == inputstate::ATTACK
      && cellDist(selected->getCurCell(), c)
          > selected->getRange(range::ATTACK)) {
    return false;
  }

  if (c != 0) {
    cur_cell = c;
    tilehighlight.setPosition(sf::Vector2f(cur_cell->getLoc()));
    return true;
  }
  return false;
}

void InputController::update() {
  // move the cursor highlight
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow() - 1, cur_cell->getCol()))
      updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol() - 1))
      updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow() + 1, cur_cell->getCol()))
      updateCell();
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol() + 1))
      updateCell();
  }

  // select the current cell
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    selectCell();
  }

  // for now use this to end turn/change phase. debugging purposes
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    eng_ptr->getPlayState()->changePhase(gamestate::ENEMY);
  }
}

void InputController::selectCell() {
  inputtimer.resetClock();
  // a unit was NOT previously selected already

  if (state == inputstate::FREE) {
    selected = cur_cell->unit;
    map_ptr->toggleRangeOn(selected, range::COMBINED);
    state = inputstate::MOVE;
    return;
  }

  if (state == inputstate::MOVE) {
    if (!moveUnit(cur_cell->getRow(), cur_cell->getCol()))
      return;
    map_ptr->toggleRangeOff();
    state = inputstate::ACTION;
    bool canAttack = map_ptr->inDistance(selected, unit::ENEMY);

    // for now go straight to attack if possible, in future use a menu with the action "attack"
    if (canAttack) {
      map_ptr->toggleRangeOn(selected, range::ATTACK);
      state = inputstate::ATTACK;
      return;
    } else {
      finishSelect();
      return;
    }
  }

  if (state == inputstate::ATTACK) {
    // end move, dont attack
    if (cur_cell == selected->getCurCell()) {
      finishSelect();
      return;
    }

    if (cur_cell->unit != 0 && cur_cell->unit->getControl() == unit::ENEMY) {
      // check readme for TODO here
      selected->attackUnit(cur_cell->unit);
      finishSelect();
      return;
    }
  }
}

void InputController::finishSelect() {
  map_ptr->toggleRangeOff();
  state = inputstate::FREE;
  selected->can_move = false;
  selected = 0;
}

bool InputController::moveUnit(int x, int y) {
  Cell* unit_cell = selected->getCurCell();

  if (unit_cell == 0)
    return false;
  Cell* to_cell = map_ptr->getCell(x, y);

  if (unit_cell == to_cell)
    return true;

  if (to_cell == 0 || to_cell->unit != 0)
    return false;

  unit_cell->unit = 0;
  selected->setTile(to_cell);
  to_cell->unit = selected;

  return true;
}

void InputController::moveUnit(dir::Direction d) {
  inputtimer.resetClock();
  if (selected == 0)
    return;

  Cell* player_cell = selected->getCurCell();
  if (player_cell == 0)
    return;

  Cell* new_cell;

  if (d == dir::UP)
    new_cell = map_ptr->getCell(player_cell->getRow() - 1,
        player_cell->getCol());
  else if (d == dir::DOWN)
    new_cell = map_ptr->getCell(player_cell->getRow() + 1,
        player_cell->getCol());
  else if (d == dir::LEFT)
    new_cell = map_ptr->getCell(player_cell->getRow(),
        player_cell->getCol() - 1);
  else if (d == dir::RIGHT)
    new_cell = map_ptr->getCell(player_cell->getRow(),
        player_cell->getCol() + 1);

  if (new_cell == 0)
    return;

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
    return sf::Vector2i(0, 0);
  }

  return cur_cell->getCenter();
}

void InputController::render() {
  win_ptr->draw(tilehighlight);
}
