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

Cell::Cell(GameEngine* eng, Map* map, int r, int c)
: eng_ptr(eng), map_ptr(map), row(r), col(c) {

  base.setTexture(*(eng_ptr->getRes()->getResource(TILE_KEY)));

  half_size.x = (base.getLocalBounds().width)/2;
  half_size.y = (base.getLocalBounds().height)/4;
  // note: do not change this math without drawing out the placements first
  center.x = half_size.x + c*half_size.x - r*half_size.x;
  center.y = half_size.y + c*half_size.y + r*half_size.y;

  base.setPosition(center.x - half_size.x, center.y - half_size.y);

  // use this to draw on top of the base tile.
  sf::Sprite temp(*(eng_ptr->getRes()->getResource(TILE_KEY)));
  temp.setPosition(center.x - half_size.x, center.y - half_size.y);
  add.push_back(temp);

  area_type = Terrain::FOREST;
  unit = 0;
}

Cell::~Cell() {
  // TODO Auto-generated destructor stub
}

void Cell::render() {
  eng_ptr->getWindow()->draw(base);
  for (int i = 0, j = add.size(); i < j; i++) {
    eng_ptr->getWindow()->draw(add[i]);
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
