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

class InputController {
public:
  InputController(GameEngine* eng);
  virtual ~InputController();

  void setMap(Map* mp) { map_ptr = mp; };
  void setCurrentCell(int x, int y);

  void update();
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  Map* map_ptr;
  Cell* cur_cell;
  FormatClock inputtimer;

  sf::Sprite tilehighlight;


};

#endif /* INPUTCONTROLLER_H_ */
