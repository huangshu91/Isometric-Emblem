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
#include <iostream>
#include <vector>
#include <string>

class GameEngine;
class Map;
class DynamicEntity;

class Cell {
public:
  Cell(GameEngine* eng, Map* map_ptr, int r, int c);
  virtual ~Cell();

  void setType(std::string type);

  sf::Vector2i getCenter() { return center; }
  sf::Vector2i getLoc() { return sf::Vector2i(base.getPosition()); };
  sf::Vector2i getCoords() { return sf::Vector2i(row, col); }
  int getRow() { return row; };
  int getCol() { return col; };
  Terrain getTerrain() { return area_type; };

  void render();

  friend std::ostream& operator<<(std::ostream& out, const Cell& c);
  friend std::ostream& operator<<(std::ostream& out, const Cell* c);

  DynamicEntity* unit;

private:
  GameEngine* eng_ptr;

  Map* map_ptr;

  sf::Sprite base;
  std::vector<sf::Sprite> add;

  int row;
  int col;

  sf::Vector2i half_size;
  sf::Vector2i center;

  Terrain area_type;
};

#endif /* CELL_H_ */
