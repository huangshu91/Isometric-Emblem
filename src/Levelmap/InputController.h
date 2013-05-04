/*
 * InputController.h
 *
 *  Created on: Apr 22, 2013
 *      Author: Maiev
 */

#ifndef INPUTCONTROLLER_H_
#define INPUTCONTROLLER_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Util/FormatClock.h"
#include "../Util/Constants.h"

class GameEngine;
class Map;
class Cell;
class TerrainMenu;
class DynamicEntity;

class InputController {
public:
  InputController(GameEngine* eng);
  virtual ~InputController();

  void setMap(Map* mp);
  // true if changed, false if same
  bool setCurrentCell(int x, int y);
  void moveUnit(dir::Direction d);
  // true if unit was moved, false if same
  bool moveUnit(int x, int y);
  void selectCell();
  sf::Vector2i getCurrentCenter();

  void update();
  void render();

private:
  void updateCell();

  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  Map* map_ptr;
  Cell* cur_cell;
  DynamicEntity* selected;
  FormatClock inputtimer;
  inputstate::Phase state;

  sf::Sprite tilehighlight;

  TerrainMenu* terrainhud_ptr;
};

#endif /* INPUTCONTROLLER_H_ */
