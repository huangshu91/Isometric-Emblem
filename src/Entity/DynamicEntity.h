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
  int getRange() { return move_range; };

  void render();

private:
  unit::Class classtype;

  Cell* tile_ptr;

  int move_range;
};

#endif /* DYNAMICENTITY_H_ */
