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
#include "../Gamestate/PlayState.h"
#include "../Database/Database.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

Map::Map(GameEngine* eng) : eng_ptr(eng), row(0), col(0) {
  range_on = false;
  eng_ptr->getRes()->addResource(RANGE_MOVE_KEY, RANGE_MOVE);
  eng_ptr->getRes()->addResource(RANGE_ATTACK_KEY, RANGE_ATTACK);
  eng_ptr->getRes()->addResource(TILE_KEY, TILE_ROCK);
}

void Map::loadMap(string id) {
  ChapDef cd = eng_ptr->getDatabase()->getChap(id);
  if (!cd.chap_name.compare("NONE")) {
    eng_ptr->getLog()->e("Could not load map: "+id);
    return;
  }
  map_name = cd.chap_name;
  map_id = cd.id;
  ifstream file(cd.map_def.c_str());
  if (file.is_open()) {
    file >> row;
    file >> col;
    map<char, string> symbol;
    int int_tmp;
    file >> int_tmp;

    for (int i = 0; i < int_tmp; i++) {
      char sym;
      string key;
      file >> sym;
      file >> key;
      symbol.insert(make_pair(sym,key));
    }

    for (int i = 0; i < row; i++) {
      vector<Cell> row;
      for (int j = 0; j < col; j++) {
        char ch;
        file >> ch;
        Cell c(eng_ptr, getMap(), i, j);
        c.setType(symbol.find(ch)->second);
        row.push_back(c);
      }
      board.push_back(row);
    }

    file.close();
  }
}

void Map::setDimensions(int x, int y) {
  row = x;
  col = y;

  for (int i = 0; i < row; i++) {
    vector<Cell> row;
    for (int j = 0; j < col; j++) {
      row.push_back(Cell(eng_ptr, getMap(), i, j));
      row[j].setType("Plain");
    }
    board.push_back(row);
  }

  board[2][2].setType("Grass");
  board[5][3].setType("Pond");
  board[8][3].setType("Forest");
}

// offsets and tiles are currently hardcoded, get from file
// also what units are in map, resources for those units/etc
void Map::setupEntity() {
  eng_ptr->getRes()->addResource(UNIT_ARMOR_KEY, UNIT_ARMOR);
  eng_ptr->getRes()->addResource(UNIT_ARMOR_RED_KEY, UNIT_ARMOR_RED);

  DynamicEntity* u = new DynamicEntity(eng_ptr, UNIT_ARMOR_KEY);
  u->setOffset(6, -4);
  u->setTile(getCell(3, 5), this);
  getCell(3, 5)->unit = u;
  u->buildUnit(60,60,10,10,10,10,10,10,5,20, unit::PLAYER);
  u->damage = 10;
  units.push_back(u);
  player_units.push_back(u);

  u = new DynamicEntity(eng_ptr, UNIT_ARMOR_RED_KEY);
  u->setOffset(6, -4);
  u->setTile(getCell(9, 1), this);
  getCell(9, 1)->unit = u;
  units.push_back(u);
  enemy_units.push_back(u);

  u = new DynamicEntity(eng_ptr, UNIT_ARMOR_RED_KEY);
  u->setOffset(6, -4);
  u->setTile(getCell(4, 0), this);
  getCell(4, 0)->unit = u;
  units.push_back(u);
  enemy_units.push_back(u);
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

void Map::resetUnits() {
  for (int i = 0, j = units.size(); i < j; i++) {
    units[i]->newTurn();
  }
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

void Map::removeUnit(DynamicEntity* unit, unit::Control utype) {
  unit->getCurCell()->unit = 0;

  switch (utype) {
  case unit::PLAYER:
    for (int i = 0, j = player_units.size(); i < j; i++) {
      if (player_units[i] == unit) {
        player_units.erase(player_units.begin()+i);
      }
    }
    break;

  case unit::ENEMY:
    for (int i = 0, j = enemy_units.size(); i < j; i++) {
      if (enemy_units[i] == unit) {
        enemy_units.erase(enemy_units.begin()+i);
      }
    }
    break;

  case unit::ALLIED:

    break;

  default:
    break;
  }

  for (int i = 0, j = units.size(); i < j; i++) {
    if (units[i] == unit) {
      units.erase(units.begin()+i);
    }
  }

  dead.push_back(unit);
}

void Map::render() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j].render();
      //board[i][j].renderAdd();
    }
  }

  if (range_on) renderRange();
}

void Map::renderAdd() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j].renderAdd();
    }
  }
}

void Map::renderUnits() {
  for (int i = 0, j = units.size(); i < j; i++) {
    units[i]->render();
  }
}

bool sortUnits(DynamicEntity* x, DynamicEntity* y) {
  if (x->getCurCell()->getRow() < y->getCurCell()->getRow()) {
    return true;
  }
  else if (x->getCurCell()->getRow() > y->getCurCell()->getRow()) {
    return false;
  }
  else { //same row, check cols
    if (x->getCurCell()->getCol() < y->getCurCell()->getCol()) {
      return true;
    }

    else if (x->getCurCell()->getCol() > y->getCurCell()->getCol()) {
      return false;
    }
  }
  return false; //should not reach here
}

void Map::checkLoss() {
  // if main char is dead or no units left.
  if (player_units.empty()) {
    eng_ptr->getPlayState()->changePhase(gamestate::LOSS);
  }
}

void Map::sortForeground() {
  sort(units.begin(), units.end(), sortUnits);
}

void Map::renderRange() {
  sf::RenderWindow* rw = eng_ptr->getWindow();
  for (int i = 0, j = rangetile.size(); i < j; i++) {
    rw->draw(rangetile[i]);
  }
}
