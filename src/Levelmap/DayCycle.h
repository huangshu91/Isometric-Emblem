/*
 * DayCycle.h
 *
 *  Created on: Jun 2, 2013
 *      Author: Maiev
 */

#ifndef DAYCYCLE_H_
#define DAYCYCLE_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameEngine;

class DayCycle {
public:
  DayCycle();
  virtual ~DayCycle();

  void update();
  void setup(GameEngine* eng);
  void render();

  int getTime() { return time*6; };

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  int time;

  static sf::Color bgcolor[4];
};

#endif /* DAYCYCLE_H_ */
