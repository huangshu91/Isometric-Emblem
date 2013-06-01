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

class GameEngine;
class DynamicEntity;

class MenuController {
public:
  MenuController();
  virtual ~MenuController();

  void setup(GameEngine* eng);

  void update();
  void render();

  void enable(DynamicEntity* e, menucon::Type t);

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  sf::Sprite cursor;

  DynamicEntity* selected;

  menucon::Type focus;
};

#endif /* MENUCONTROLLER_H_ */
