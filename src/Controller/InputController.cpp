/*
 * InputController.cpp
 *
 *  Created on: Apr 22, 2013
 *      Author: Maiev
 */

#include "InputController.h"
#include "../System/GameEngine.h"
#include "../HUDWidget/TerrainMenu.h"
#include "../HUDWidget/MenuWidget.h"
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
  statushudr_ptr = eng_ptr->getHUD()->getStatusHUD(dir::RIGHT);
  statushudl_ptr = eng_ptr->getHUD()->getStatusHUD(dir::LEFT);
  map_ptr = 0;
  cur_cell = 0;
  selected = 0;
  base_menu = 0;
  cur_menu = 0;
  state = inputstate::FREE;

  inputtimer.resetClock();
}

InputController::~InputController() {
  // TODO Auto-generated destructor stub
}

void InputController::setup(GameEngine* eng) {
  eng_ptr = eng;
}

void InputController::setMap(Map* mp) {
  map_ptr = mp;
}

void InputController::reset() {
  state = inputstate::FREE;
  selected = 0;
}

bool InputController::setCurrentCell(int x, int y) {
  Cell* c = map_ptr->getCell(x, y);
  inputtimer.resetClock();

  if (state == inputstate::MOVE
      && cellDist(selected->getCurCell(), c) > selected->getRange(range::MOVE)
      && selected->getControl() == unit::PLAYER) {
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
  //if the window does not have focus, do not accept input
  if (eng_ptr->hasFocus() == false) return;

  /*
  sf::Vector2i pixelPos = sf::Mouse::getPosition(*win_ptr);
  pixelPos.x *= eng_ptr->getGameCam()->getZoom();
  pixelPos.y *= eng_ptr->getGameCam()->getZoom();
  pixelPos.x += eng_ptr->getGameCam()->GetLocation().x;
  pixelPos.y += eng_ptr->getGameCam()->GetLocation().y;
  int tx = ceil((pixelPos.x+2*pixelPos.y-30-30)/60);
  int ty = ceil((-pixelPos.x+2*pixelPos.y+30-30)/60);
  if(setCurrentCell(ty, tx) && inputtimer.getElapsedTime() > INPUT_DELAY)
  {
  updateCell();
  }
  */

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

    //eng_ptr->getPlayState()->changePhase(playstate::MENU);
    eng_ptr->getPlayState()->changePhase(playstate::ENEMY);
  }
}

void InputController::selectCell() {
  inputtimer.resetClock();
  // a unit was NOT previously selected already

  if (state == inputstate::FREE) {
    if (cur_cell->unit) {//&& cur_cell->unit->can_move) {
      selected = cur_cell->unit;
      map_ptr->toggleRangeOn(selected, range::COMBINED);
      state = inputstate::MOVE;
      return;
    }
    else {
      //eng_ptr->getPlayState()->changePhase(playstate::MENU_STAT);
    }
  }

  if (state == inputstate::MOVE) {
    if (selected->getControl() != unit::PLAYER) {
      finishSelect();
      return;
    }

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
  //eng_ptr->getPlayState()->changePhase(playstate::MENU_UNIT);
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
  selected->setTile(to_cell, map_ptr);
  to_cell->unit = selected;

  map_ptr->sortForeground();
  return true;
}

void InputController::updateCell() {
  // consider if selected == 0, this means that if someone is selected,
  // the statuswidgets are locked.
  if (cur_cell->unit != 0) {// && selected == 0) {
    if (cur_cell->unit->getControl() == unit::PLAYER) {
      statushudr_ptr->updateChar(cur_cell->unit);
      statushudr_ptr->setVisible(true);
    }
    else if (cur_cell->unit->getControl() == unit::ENEMY) {
      statushudl_ptr->updateChar(cur_cell->unit);
      statushudl_ptr->setVisible(true);
    }
  }

  else if (selected != 0) {
    if (selected->getControl() == unit::PLAYER)
      statushudr_ptr->setVisible(true);
    if (selected->getControl() == unit::ENEMY)
      statushudl_ptr->setVisible(true);
  } else {
    statushudr_ptr->setVisible(false);
    statushudl_ptr->setVisible(false);
  }

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
  if (eng_ptr->getPlayState()->getPhase() == playstate::PLAYER)
  win_ptr->draw(tilehighlight);
}
