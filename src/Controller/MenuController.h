/*
 * MenuController.h
 *
 *  Created on: May 30, 2013
 *      Author: Maiev
 */

#ifndef MENUCONTROLLER_H_
#define MENUCONTROLLER_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Util/Constants.h"
#include "../Util/FormatClock.h"

class GameEngine;
class DynamicEntity;
class MenuWidget;
class InputController;

class MenuController {
public:
  MenuController();
  virtual ~MenuController();

  void setup(GameEngine* eng, InputController* ic);

  void update();
  void render();

  void enable(DynamicEntity* e, menucon::Type t);
  void action();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  MenuWidget* base_menu;
  MenuWidget* cur_menu;

  InputController* unitcon;

  sf::Sprite cursor;
  FormatClock timer;
  DynamicEntity* selected;

  menucon::Type focus;
};

#endif /* MENUCONTROLLER_H_ */
