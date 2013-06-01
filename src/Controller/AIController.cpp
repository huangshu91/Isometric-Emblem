/*
 * AIController.cpp
 *
 *  Created on: May 12, 2013
 *      Author: Maiev
 */

#include "AIController.h"
#include "../Entity/DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Levelmap/Map.h"
#include "../Levelmap/Cell.h"
#include "../Gamestate/PlayState.h"
#include "../Util/UtilFunc.h"
#include "../HUDWidget/TerrainMenu.h"
#include "../HUDWidget/StatusWidget.h"
#include <iostream>
using namespace std;

AIController::AIController(GameEngine* eng) : eng_ptr(eng) {
  map_ptr = 0;
  selected = 0;
  state = inputstate::FREE;
  terrainhud_ptr = eng_ptr->getHUD()->getTerrainHUD();
  statushudr_ptr = eng_ptr->getHUD()->getStatusHUD(dir::RIGHT);
  statushudl_ptr = eng_ptr->getHUD()->getStatusHUD(dir::LEFT);

  delaytimer.resetClock();
}

AIController::~AIController() {
  // TODO Auto-generated destructor stub
}

void AIController::setMap(Map* mp) {
  map_ptr = mp;
}

void AIController::update() {
  //bool finished = true;

  if (delaytimer.getElapsedTime() < 0.5f) return;

  std::vector<DynamicEntity*> units = map_ptr->getEnemyUnits();
  for (int i = 0, j = units.size(); i < j; i++) {
    if (units[i]->finished_move == false) {
      delaytimer.resetClock();
      selected = units[i];
      moveUnit();
      return;
    }
  }

  eng_ptr->getPlayState()->changePhase(playstate::NEWTURN);
}

void AIController::moveUnit() {
  std::vector<DynamicEntity*> play_unit = map_ptr->getPlayerUnits();

  // no player units left, finish turn
  if (play_unit.empty()) {
    endUnit();
    return;
  }

  queue<Cell*> full_path = map_ptr->getPath(selected, range::MOVE);
  queue<Cell*> path;

  for (int i = 0, j = full_path.size(); i < j; i++) {
    if (full_path.front()->unit == 0) {
      path.push(full_path.front());
    }
    full_path.pop();
  }

  DynamicEntity* target;
  int dist = 999;
  for (int i = 0, j = play_unit.size(); i < j; i++) {
    int d = cellDist(selected->getCurCell(), play_unit[i]->getCurCell());
    if (d < dist) {
      target = play_unit[i];
      dist = d;
    }
  }

  Cell* to_cell = 0;
  dist = 999;
  for (int i = 0, j = path.size(); i < j; i++) {
    int d = cellDist(target->getCurCell(), path.front());
    if (d == selected->getRange(range::ATTACK)) {
      to_cell = path.front();
      break;
    }

    if (d < dist) {
      dist = d;
      to_cell = path.front();
    }
    path.pop();
  }

  if (cellDist(target->getCurCell(), selected->getCurCell()) ==
      selected->getRange(range::ATTACK) || to_cell == 0) {
    to_cell = selected->getCurCell();
  }

  moveTo(to_cell);

  if (cellDist(target->getCurCell(), to_cell) == selected->getRange(range::ATTACK)) {
    selected->attackUnit(target);
  }

  endUnit();
}

void AIController::moveTo(Cell* c) {
  if (c == selected->getCurCell()) {
    return;
  }

  selected->getCurCell()->unit = 0;
  selected->setTile(c, map_ptr);
  c->unit = selected;
}

void AIController::endUnit() {
  selected->endTurn();
  selected = 0;
  map_ptr->sortForeground();
}
