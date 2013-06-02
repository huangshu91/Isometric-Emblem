/*
 * Map_Construction.cpp
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#include "../System/GameEngine.h"
#include "../Util/Constants.h"
#include "../Database/Database.h"
#include "../Entity/DynamicEntity.h"
#include "../Gamestate/PlayState.h"
#include "Map.h"
using namespace std;

Map::Map(GameEngine* eng) : eng_ptr(eng), row(0), col(0) {
  range_on = false;
  eng_ptr->getRes()->addResource(RANGE_MOVE_KEY, RANGE_MOVE);
  eng_ptr->getRes()->addResource(RANGE_ATTACK_KEY, RANGE_ATTACK);
  eng_ptr->getRes()->addResource(TILE_KEY, TILE_BASE);
  cycle.setup(eng);
}

void Map::loadMap(string id) {
  ChapDef cd = eng_ptr->getDatabase()->getChap(id);
  if (!cd.chap_name.compare("NONE")) {
    eng_ptr->getLog()->e("Could not load map: "+id);
    return;
  }
  map_name = cd.chap_name;
  map_id = id;
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
      vector<Cell> r;
      for (int j = 0; j < col; j++) {
        char ch;
        file >> ch;
        Cell c(eng_ptr, getMap(), i, j);
        c.setType(symbol.find(ch)->second);
        r.push_back(c);
      }
      board.push_back(r);
    }

    file >> int_tmp;
    for (int i = 0 ; i < int_tmp; i++) {
      // get enemy entity information
      sf::Vector2i loc;
      file >> loc.x;
      file >> loc.y;
      string str_tmp;
      file >> str_tmp;
      StatPack en;
      file >> en.max_hp;
      file >> en.str;
      file >> en.dex;
      file >> en.agi;
      file >> en.def;
      file >> en.res;
      file >> en.lck;

      createEntity(loc, str_tmp, en);
    }

    file.close();
  }
}

void Map::createEntity(sf::Vector2i loc, string key, StatPack stat) {
  UnitClass c = eng_ptr->getDatabase()->getClass(key);
  DynamicEntity* ent = new DynamicEntity(eng_ptr, key);
  ent->setOffset(c.offset);
  ent->setTile(getCell(loc.x, loc.y), this);
  getCell(loc.x, loc.y)->unit = ent;
  ent->buildUnit(stat);
  units.push_back(ent);
  enemy_units.push_back(ent);
  ent->move_range = c.mv;
}

void Map::setupEntity() {
  eng_ptr->getRes()->addResource(UNIT_ARMOR_KEY, UNIT_ARMOR);
  eng_ptr->getRes()->addResource(UNIT_ARMOR_RED_KEY, UNIT_ARMOR_RED);

  UnitClass c = eng_ptr->getDatabase()->getClass("General");

  if (!map_id.compare("1")) {
    DynamicEntity* u = new DynamicEntity(eng_ptr, c.class_name);
    u->setOffset(c.offset);
    u->setTile(getCell(3, 3), this);
    getCell(3, 3)->unit = u;
    u->buildUnit(60,60,10,10,10,3,10,10,5,20, unit::PLAYER);
    units.push_back(u);
    player_units.push_back(u);
    eng_ptr->getCaravan()->addPlayer(u);
  }
}

Map::~Map() {
  // TODO Auto-generated destructor stub
}

void Map::checkLoss() {
  // if main char is dead or no units left.
  if (player_units.empty()) {
    eng_ptr->getPlayState()->changePhase(playstate::LOSS);
  }
}

void Map::render() {
  cycle.render();
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

void Map::sortForeground() {
  sort(units.begin(), units.end(), sortUnits);
}

void Map::renderRange() {
  sf::RenderWindow* rw = eng_ptr->getWindow();
  for (int i = 0, j = rangetile.size(); i < j; i++) {
    rw->draw(rangetile[i]);
  }
}
