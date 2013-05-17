/*
 * DynamicEntity.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#include "DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Levelmap/Cell.h"
#include "../Levelmap/Map.h"
#include "../Util/UnitValues.h"
#include "../Gamestate/PlayState.h"

DynamicEntity::DynamicEntity(GameEngine* eng, string n) : Entity(eng, n) {
  name = n;
  move_range = UNIT_MOVE;
  attack_range = UNIT_ATTACK;
  control = unit::ENEMY;
  class_type = unit::NONE;
  can_move = true;
  finished_move = false;

  map_ptr = 0;
  tile_ptr = 0;

  health = 30;
  cur_hp = 30;
  damage = 5;
}

DynamicEntity::~DynamicEntity() {
  // TODO Auto-generated destructor stub
}

void DynamicEntity::setTile(Cell* t, Map* map) {
  tile_ptr = t;
  map_ptr = map;
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

void DynamicEntity::setControl(unit::Control c) {
  control = c;
}

void DynamicEntity::attackUnit(DynamicEntity* unit) {
  // resolve attacks here
  unit->cur_hp -= damage;
  if (unit->cur_hp <= 0) {
    unit->cur_hp = 0;
    unitDeath(unit);
  }
  cur_hp -= unit->damage;
  if (cur_hp <= 0) {
    cur_hp = 0;
    unitDeath(this);
  }
  unit->cur_hp -= damage;
  if (unit->cur_hp <= 0) {
    unit->cur_hp = 0;
    unitDeath(unit);
  }
}

void DynamicEntity::unitDeath(DynamicEntity* unit) {
  map_ptr->removeUnit(unit, unit->getControl());
  eng_ptr->getPlayState()->changePhase(gamestate::UNITDEATH);
}

// for now reset finished_move. in future this is where poison and other
// turn based effects are applied.
void DynamicEntity::newTurn() {
  finished_move = false;
}

void DynamicEntity::endTurn() {
  can_move = false;
  finished_move = true;
}
