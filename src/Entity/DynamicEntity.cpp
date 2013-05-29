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
#include "../Util/UtilValues.h"
#include "../Gamestate/PlayState.h"

DynamicEntity::DynamicEntity(GameEngine* eng, string n)
: Entity(eng, n) {
  UnitClass c = eng_ptr->getDatabase()->getClass(n);
  name = n;
  move_range = UNIT_MOVE;
  attack_range = UNIT_ATTACK;
  control = unit::ENEMY;
  class_type = unit::NONE;
  can_move = true;
  finished_move = false;

  map_ptr = 0;
  tile_ptr = 0;

  total.hp = 30;
  total.max_hp = 30;
  level = 1;
  exp = 0;
}

void DynamicEntity::buildUnit(StatPack s, unit::Control c) {
  s.hp = s.max_hp;
  base = s;
  total = s;
  control = c;
}

void DynamicEntity::buildUnit(int hp, int max, int s, int de,
    int a, int d, int r, int l, int co, int ch, unit::Control c){
  StatPack temp(hp, max, s, de, a, d, r, l, co, ch);
  buildUnit(temp, c);
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

int DynamicEntity::getPow() {
  int pow = total.str + tile_ptr->getTerrain().atk;
  // pow += itembonuses
  return pow;
}

int DynamicEntity::getDef() {
  int def = total.def + tile_ptr->getTerrain().def;
  return def;
}

// This needs to be refactored
void DynamicEntity::attackUnit(DynamicEntity* unit) {
  eng_ptr->getBattle()->attackUnit(this, unit);
}

bool DynamicEntity::takeDamage(int d) {
  if (d <= 0) {
   //no damage taken, play sound, etc
    return false;
  }

  total.hp -= d;
  if (total.hp <= 0) {
    total.hp = 0;
  }

  return true;
}

// Formula for exp gain based on unit
int DynamicEntity::gainEXP(DynamicEntity* e, BattleManager::Result r) {
  int amt = 0;
  if (r == BattleManager::Result::KILL) amt = 30;
  else if (r == BattleManager::Result::MISS) amt = 5;
  else if (r == BattleManager::Result::HIT) amt = 10;
  exp = (exp+amt > 100) ? 100 : exp+amt;
  return amt;
}

void DynamicEntity::levelUp() {

}

void DynamicEntity::unitDeath() {
  map_ptr->removeUnit(this, getControl());
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

ostream& operator<<(ostream& out, const DynamicEntity* e) {

  return out;
}
