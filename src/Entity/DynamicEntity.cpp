/*
 * DynamicEntity.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#include "DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Levelmap/Cell.h"
#include "../Util/UnitValues.h"

DynamicEntity::DynamicEntity(GameEngine* eng, string n) : Entity(eng) {
  name = n;
  move_range = UNIT_MOVE;
}

DynamicEntity::~DynamicEntity() {
  // TODO Auto-generated destructor stub
}

void DynamicEntity::setTile(Cell* t) {
  tile_ptr = t;
  sprite.setPosition(sf::Vector2f(t->getCenter()));
}

void DynamicEntity::render() {
  win_ptr->draw(sprite);
}
