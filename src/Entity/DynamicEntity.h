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
  StatPack mods;
  StatPack base;

  void buildUnit(StatPack s, unit::Control c);
  void buildUnit(int hp, int max, int s, int dee,
      int a, int d, int r, int l, int co, int ch, unit::Control c);

  // modify these later to give calculated values
  int getPow() { return damage; };
  int getDef() { return total.def; };

  // return true if unit died
  bool takeDamage(int d);
  void unitDeath();
  int gainEXP(DynamicEntity* e);
  void levelUp();

  //temporary
  int damage;
  int level;
  int exp;

private:
  unit::Class class_type;
  unit::Control control;

  Map* map_ptr;
  Cell* tile_ptr;

  // these will be based on various factors in future
  int move_range;
  int attack_range;
};

#endif /* DYNAMICENTITY_H_ */
