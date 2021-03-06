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
#include "../Database/Database.h"
#include "../Util/Constants.h"
#include "../Util/UtilValues.h"
#include "../Entity/BattleManager.h"
#include "../Item/Item.h"
#include "../Item/ItemBag.h"

class GameEngine;
class Cell;
class Map;

class DynamicEntity : public Entity {
public:
  DynamicEntity(GameEngine* eng, std::string n);
  virtual ~DynamicEntity();

  void setTile(Cell* t, Map* map);
  sf::Vector2f getLoc();
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

  void buildUnit(StatPack s, unit::Control c = unit::ENEMY);
  void buildUnit(int hp, int max, int s, int dee, int a, int d,
      int r, int l, int co, int ch, unit::Control c = unit::ENEMY);
  void addItem(Item it);

  // modify these later to give calculated values
  int getPow();
  int getDef();

  // return true if unit took damage
  bool takeDamage(int d);
  void unitDeath();
  int gainEXP(DynamicEntity* e, BattleManager::Result r);
  void levelUp();

  int level;
  int exp;
  int move_range;
  int attack_range;

  std::vector<Item> inventory;

  // for debug use
  friend std::ostream& operator<<(std::ostream& out, const DynamicEntity* e);

private:
  unit::Class class_type;
  unit::Control control;

  Map* map_ptr;
  Cell* tile_ptr;

  ItemBag inven;
};

#endif /* DYNAMICENTITY_H_ */
