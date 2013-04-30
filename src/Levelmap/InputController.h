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
#include "../Util/FormatCLock.h"

class GameEngine;
class Map;
class Cell;
class TerrainMenu;

class InputController {
public:
  InputController(GameEngine* eng);
  virtual ~InputController();

  void setMap(Map* mp) { map_ptr = mp; };
  // true if changed, false if same
  bool setCurrentCell(int x, int y);
  sf::Vector2i getCurrentCenter();

  void update();
  void render();

private:
  void updateCell();

  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  Map* map_ptr;
  Cell* cur_cell;
  FormatClock inputtimer;

  sf::Sprite tilehighlight;

  TerrainMenu* terrainhud_ptr;
};

#endif /* INPUTCONTROLLER_H_ */
