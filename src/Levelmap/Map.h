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

class GameEngine;

class Map {
public:
  Map(GameEngine* eng);
  ~Map();

  void setDimensions(int x, int y);

  Map* getMap() { return this; };
  Cell* getCell(int x, int y);
  int getRow() { return row; };
  int getCol() { return col; };

  void render();

private:
  GameEngine* eng_ptr;

  std::vector<std::vector<Cell> > board;

  // dimensions of the map, row = x, col = y
  int row;
  int col;
};

#endif /* MAP_H_ */
