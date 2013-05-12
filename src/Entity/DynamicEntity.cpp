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
  attack_range = UNIT_ATTACK;
  control = unit::ENEMY;
  can_move = true;
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

int DynamicEntity::getRange(range::RangeType state) {
  switch (state) {
  case range::MOVE :
    return move_range;
    break;
  case range::ATTACK :
    return attack_range;
    break;
  case range::COMBINED :
    return move_range+attack_range;
    break;
  case range::AURA :
    return 0;
    break;
  default: return 0;
  }
}

void DynamicEntity::attackUnit(DynamicEntity* unit) {
  // resolve attacks here
}
