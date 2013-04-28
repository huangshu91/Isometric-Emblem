/*
 * Cell.h
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#ifndef CELL_H_
#define CELL_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Terrain.h"
#include "../Util/Constants.h"

class GameEngine;
class Map;

class Cell {
public:
  Cell(GameEngine* eng, Map* map_ptr, int r, int c);
  virtual ~Cell();

  sf::Vector2i getCenter() { return center; }
  sf::Vector2i getLoc() { return sf::Vector2i(tile.getPosition()); };
  sf::Vector2i getCoords() { return sf::Vector2i(row, col); }
  int getRow() { return row; };
  int getCol() { return col; };

  void render();

private:
  GameEngine* eng_ptr;

  Map* map_ptr;

  sf::Sprite tile;

  int row;
  int col;

  sf::Vector2i half_size;
  sf::Vector2i center;

};

#endif /* CELL_H_ */
