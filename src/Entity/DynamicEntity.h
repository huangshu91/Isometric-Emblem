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
#include "../Util/UtilValues.h"

class GameEngine;
class Cell;
class Map;

class DynamicEntity : public Entity {
public:
  DynamicEntity(GameEngine* eng, string n = "");
  virtual ~DynamicEntity();

  void setTile(Cell* t, Map* map);
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

  StatPack total;

  // modify these later to give calculated values
  int getPow() { return damage; };
  int getDef() { return total.def; };

  void takeDamage(int d);

  //temporary
  int damage;

private:
  unit::Class class_type;
  unit::Control control;

  StatPack mods;
  StatPack base;

  Map* map_ptr;
  Cell* tile_ptr;

  // these will be based on various factors in future
  int move_range;
  int attack_range;

  void unitDeath(DynamicEntity* unit);
};

#endif /* DYNAMICENTITY_H_ */
