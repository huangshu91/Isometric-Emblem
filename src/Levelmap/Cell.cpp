/*
 * Cell.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#include "Cell.h"
#include "../Util/Constants.h"
#include "../System/GameEngine.h"

Cell::Cell(GameEngine* eng, Map* map, int r, int c)
: eng_ptr(eng), map_ptr(map), row(r), col(c) {
  tile.setTexture(*(eng->getRes()->getResource(TILE_KEY)));

  half_size.x = (tile.getLocalBounds().width)/2;
  half_size.y = (tile.getLocalBounds().height)/4;

  // note: do not change this math without drawing out the placements first
  // pain in the ass to think about.
  center.x = half_size.x + c*half_size.x - r*half_size.x;
  center.y = half_size.y + c*half_size.y + r*half_size.y;

  tile.setPosition(center.x - half_size.x, center.y - half_size.y);


}

Cell::~Cell() {
  // TODO Auto-generated destructor stub
}

void Cell::render() {
  eng_ptr->getWindow()->draw(tile);


}
