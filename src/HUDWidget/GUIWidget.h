/*
 * GUIWidget.h
 *
 *  Created on: Apr 27, 2013
 *      Author: Maiev
 */

#ifndef GUIWIDGET_H_
#define GUIWIDGET_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameEngine;

class GUIWidget {
public:
  GUIWidget();
  virtual ~GUIWidget();

  void setup(GameEngine* eng);

  virtual void enable() { visible = true; };
  virtual void disable() { visible = false; };

  virtual void render() = 0;

protected:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  bool visible;
};

#endif /* GUIWIDGET_H_ */
