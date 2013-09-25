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
class StatusWidget;
class DynamicEntity;
class MenuController;
class MenuWidget;

class InputController {
public:
  InputController(GameEngine* eng);
  virtual ~InputController();

  void setMap(Map* mp);
  // true if changed, false if same
  bool setCurrentCell(int x, int y);
  void selectCell();
  void selectMenu();
  void updateCell(float time = KEY_PAN_SENS);
  sf::Vector2i getCurrentCenter();
  DynamicEntity* getSelected() { return selected; };
  void returnDelay() { inputtimer.resetClock(); };

  void reset();
  void finishSelect();

  void setup(GameEngine* eng);
  void update();
  void render();

  void buildMenu(menu::Type t);

private:
  void backMenu();

  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  Map* map_ptr;
  Cell* cur_cell;
  DynamicEntity* selected;
  FormatClock inputtimer;
  inputstate::Phase state;

  sf::Sprite tilehighlight;

  TerrainMenu* terrainhud_ptr;
  StatusWidget* statushudr_ptr;
  StatusWidget* statushudl_ptr;
  MenuWidget* base_menu;
  MenuWidget* cur_menu;

  sf::Vector2i prev_loc;
};

#endif /* INPUTCONTROLLER_H_ */
