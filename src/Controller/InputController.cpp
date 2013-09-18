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

  //buildMenu(menu::UNIT);

  //base_menu = eng->getHUD()->getMenuHUD();
  //cur_menu = base_menu;

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

void InputController::updateCell(float time) {
  // consider if selected == 0, this means that if someone is selected,
  // the statuswidgets are locked.
  if (cur_cell->unit != 0) {// && selected == 0) {
    if (cur_cell->unit->getControl() == unit::PLAYER) {
      statushudr_ptr->updateChar(cur_cell->unit);
      statushudr_ptr->enable();
    }
    else if (cur_cell->unit->getControl() == unit::ENEMY) {
      statushudl_ptr->updateChar(cur_cell->unit);
      statushudl_ptr->enable();
    }
  }

  else if (selected != 0) {
    if (selected->getControl() == unit::PLAYER)
      statushudr_ptr->enable();
    if (selected->getControl() == unit::ENEMY)
      statushudl_ptr->enable();
  } else {
    statushudr_ptr->disable();
    statushudl_ptr->disable();
  }

  eng_ptr->getGameCam()->smoothMove(sf::Vector2f(cur_cell->getCenter()), time);
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
