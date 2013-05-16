/*
 * DynamicEntity.h
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_
#include <string>
#include "Entity.h"
#include "../Util/Constants.h"

class GameEngine;
class Cell;

class DynamicEntity : public Entity {
public:
  DynamicEntity(GameEngine* eng, string n = "");
  virtual ~DynamicEntity();

  void setTile(Cell* t);
  Cell* getCurCell() { return tile_ptr; };
  int getRange(range::RangeType state);
  unit::Control getControl() { return control; };
  void setControl(unit::Control);

  void attackUnit(DynamicEntity* unit);

  void render();

  bool can_move;
  bool finished_move;

  void newTurn();
  void endTurn();

private:
  unit::Class class_type;
  unit::Control control;

  Cell* tile_ptr;

  // these will be based on various factors in future
  int move_range;
  int attack_range;

  int cur_hp;
  int damage;

  int health;
  int strength;
  int dexterity;
  int agility;
  int defense;
  int resist;
  int luck;
};

#endif /* DYNAMICENTITY_H_ */
