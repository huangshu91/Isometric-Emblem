/*
 * GUIProgressBar.h
 *
 *  Created on: May 24, 2013
 *      Author: Maiev
 */

#ifndef GUIPROGRESSBAR_H_
#define GUIPROGRESSBAR_H_

#include <SFML/Graphics.hpp>
#include "GUIWidget.h"

class GameEngine;

class GUIProgressBar : public GUIWidget {
public:
  GUIProgressBar();
  virtual ~GUIProgressBar();

  void setup(GameEngine* eng);
  void build(sf::Vector2i loc, sf::Vector2i s, sf::Color f = sf::Color(51, 227, 32));

  void setProg(int val);
  void growProg(int from, int to);

  void render();

private:
  sf::Vector2i size;
  sf::Vector2i pos;

  sf::RectangleShape full_bar;
  sf::RectangleShape fill_bar;

};

#endif /* GUIPROGRESSBAR_H_ */
