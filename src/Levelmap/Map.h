/*
 * Map.h
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#ifndef MAP_H_
#define MAP_H_
#include "Cell.h"
#include <vector>

class DynamicEntity;
class GameEngine;

class Map {
public:
  Map(GameEngine* eng);
  ~Map();

  void setDimensions(int x, int y);
  //eventually load entities from file
  void setupEntity();

  Map* getMap() { return this; };
  Cell* getCell(int x, int y);

  // this is only temporary unit we set up a system for multiple units
  DynamicEntity* getUnit() { return player; };
  int getRow() { return row; };
  int getCol() { return col; };

  void render();
  void renderUnits();

private:
  GameEngine* eng_ptr;

  std::vector<std::vector<Cell> > board;

  // dimensions of the map, row = x, col = y
  int row;
  int col;

  DynamicEntity* player;
};

#endif /* MAP_H_ */
