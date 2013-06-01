/*
 * Cell.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#include "Cell.h"
#include "../Util/Constants.h"
#include "../System/GameEngine.h"
#include "../Entity/DynamicEntity.h"
#include "../Database/Database.h"
#include <algorithm>
#include <string>
#include <vector>

Cell::Cell(GameEngine* eng, Map* map, int r, int c)
: eng_ptr(eng), map_ptr(map), row(r), col(c) {

  base.setTexture(*(eng_ptr->getRes()->getResource(TILE_KEY)));

  half_size.x = (base.getLocalBounds().width)/2;
  half_size.y = (base.getLocalBounds().height)/4;
  // note: do not change this math without drawing out the placements first
  center.x = half_size.x + c*half_size.x - r*half_size.x;
  center.y = half_size.y + c*half_size.y + r*half_size.y;

  base.setPosition(center.x - half_size.x, center.y - half_size.y);

  area_type = Terrain();
  unit = 0;
}

Cell::~Cell() {
  // TODO Auto-generated destructor stub
}

vector<sf::Vector2i> Cell::getVert() {
  vector<sf::Vector2i> ret;
  sf::Vector2i top(center.x, center.y - half_size.y);
  sf::Vector2i bot(center.x, center.y + half_size.y);
  sf::Vector2i left(center.x - half_size.x, center.y);
  sf::Vector2i right(center.x + half_size.x, center.y);

  ret.push_back(top);
  ret.push_back(bot);
  ret.push_back(left);
  ret.push_back(right);

  return ret;
}

void Cell::setType(string type) {
  TileDef td = eng_ptr->getDatabase()->getTile(type);
  if (!td.tile_name.compare("NONE")) {
    eng_ptr->getLog()->e("Could not load tile: "+type);
    return;
  }

  sf::Sprite b(*(eng_ptr->getRes()->getResource(td.base_key)));
  b.setPosition(base.getPosition());
  base = b;

  for (auto a : td.add_key) {
    sf::Sprite tmp(*(eng_ptr->getRes()->getResource(a)));
    tmp.setOrigin(tmp.getLocalBounds().width/2, tmp.getLocalBounds().height);
    sf::Vector2f loc(center.x, center.y+half_size.y);
    tmp.setPosition(loc);
    add.push_back(tmp);
  }

  area_type = td.ter;
}

void Cell::render() {
  eng_ptr->getWindow()->draw(base);

}

void Cell::renderAdd() {
  for (auto i : add) {
    eng_ptr->getWindow()->draw(i);
  }
}

std::ostream& operator<<(std::ostream& out, const Cell& c) {
  out << c.row << ":" << c.col;
  return out;
}

std::ostream& operator<<(std::ostream& out, const Cell* c) {
  out << c->row << ":" << c->col;
  return out;
}
