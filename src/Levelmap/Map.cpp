/*
 * Map.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#include "../Util/Constants.h"
#include "../Util/UtilFunc.h"
#include "../Entity/DynamicEntity.h"
#include "../System/GameEngine.h"
#include "Map.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

Map::Map(GameEngine* eng) :
    eng_ptr(eng), row(0), col(0) {
  range_on = false;
  eng_ptr->getRes()->addResource(RANGE_MOVE_KEY, RANGE_MOVE);
  eng_ptr->getRes()->addResource(RANGE_ATTACK_KEY, RANGE_ATTACK);
}

void Map::setDimensions(int x, int y) {
  row = x;
  col = y;

  for (int i = 0; i < row; i++) {
    vector<Cell> row;
    for (int j = 0; j < col; j++) {
      row.push_back(Cell(eng_ptr, getMap(), i, j));
    }
    board.push_back(row);
  }
}

// offsets and tiles are currently hardcoded, get from file
void Map::setupEntity() {
  DynamicEntity* u = new DynamicEntity(eng_ptr, SPRITE_KEY);
  u->setOffset(6, -4);
  u->setTile(getCell(3, 3));
  getCell(3, 3)->unit = u;
  units.push_back(u);

  u = new DynamicEntity(eng_ptr, SPRITE_KEY);
  u->setOffset(6, -4);
  u->setTile(getCell(5, 1));
  getCell(5, 1)->unit = u;
  units.push_back(u);
}

Map::~Map() {
  // TODO Auto-generated destructor stub
}

void Map::toggleRangeOn(DynamicEntity* e, range::RangeType type) {
  if (e == 0)
    return;
  // select a new unit
  if (range_on == true) {
    toggleRangeOff();
  }

  queue<Cell*> q = getPath(e, type);
  while (!q.empty()) {
    Cell* c = q.front();

    if (type == range::ATTACK) {
      markCell(c, RANGE_ATTACK_KEY);
    }

    if (type == range::COMBINED) {
      if (cellDist(c, e->getCurCell()) > e->getRange(range::MOVE))
        markCell(c, RANGE_ATTACK_KEY);
      else
        markCell(c, RANGE_MOVE_KEY);
    }

    if (type == range::MOVE) {
      markCell(c, RANGE_MOVE_KEY);
    }

    q.pop();
  }

  range_on = true;
}

bool Map::inDistance(DynamicEntity* e, unit::Control utype) {
  queue<Cell*> q = getPath(e, range::ATTACK);
  while (!q.empty()) {
    Cell* c = q.front();
    if (c->unit != 0 && c->unit != e && c->unit->getControl() == utype)
      return true;
    q.pop();
  }
  return false;
}

queue<Cell*> Map::getPath(DynamicEntity* e, range::RangeType type) {
  queue<Cell*> path;
  queue<Cell*> ret;
  map<Cell*, int> traveled;
  path.push(e->getCurCell());
  Cell* origin = e->getCurCell();
  traveled.insert(pair<Cell*, int>(e->getCurCell(), 1));
  for (;;) {
    Cell* cur_cell = path.front();
    path.pop();
    Cell* check_cell;

    ret.push(cur_cell);

    if ((check_cell = getCell(cur_cell->getRow(), cur_cell->getCol() - 1))) {
      if (!traveled.count(check_cell)
          && cellDist(origin, check_cell) <= e->getRange(type)) {
        path.push(check_cell);
        traveled.insert(pair<Cell*, int>(check_cell, 1));
      }
    }

    if ((check_cell = getCell(cur_cell->getRow(), cur_cell->getCol() + 1))) {
      if (!traveled.count(check_cell)
          && cellDist(origin, check_cell) <= e->getRange(type)) {
        path.push(check_cell);
        traveled.insert(pair<Cell*, int>(check_cell, 1));
      }
    }

    if ((check_cell = getCell(cur_cell->getRow() - 1, cur_cell->getCol()))) {
      if (!traveled.count(check_cell)
          && cellDist(origin, check_cell) <= e->getRange(type)) {
        path.push(check_cell);
        traveled.insert(pair<Cell*, int>(check_cell, 1));
      }
    }

    if ((check_cell = getCell(cur_cell->getRow() + 1, cur_cell->getCol()))) {
      if (!traveled.count(check_cell)
          && cellDist(origin, check_cell) <= e->getRange(type)) {
        path.push(check_cell);
        traveled.insert(pair<Cell*, int>(check_cell, 1));
      }
    }

    if (path.empty()) {
      break;
    }
  }

  return ret;
}

void Map::toggleRangeOff() {
  range_on = false;
  rangetile.clear();
}

void Map::markCell(Cell* c, string key) {
  sf::Texture* tex = eng_ptr->getRes()->getResource(key);
  sf::Sprite s(*tex);

  s.setPosition(sf::Vector2f(c->getLoc()));
  rangetile.push_back(s);
}

Cell* Map::getCell(int x, int y) {
  if (x < 0 || x >= row || y < 0 || y >= col)
    return 0;

  return &(board[x][y]);
}

void Map::render() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j].render();
    }
  }

  if (range_on)
    renderRange();
}

void Map::renderUnits() {
  for (int i = 0, j = units.size(); i < j; i++) {
    units[i]->render();
  }
}

void Map::sortForeground() {

}

void Map::renderRange() {
  sf::RenderWindow* rw = eng_ptr->getWindow();
  for (int i = 0, j = rangetile.size(); i < j; i++) {
    rw->draw(rangetile[i]);
  }
}
