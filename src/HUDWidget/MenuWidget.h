/*
 * MenuWidget.h
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#ifndef MENUWIDGET_H_
#define MENUWIDGET_H_
#include "../Interface/GUIFrame.h"
#include "GUIWidget.h"

class MenuWidget: public GUIWidget {
public:
  MenuWidget();
  virtual ~MenuWidget();

  void setup(GameEngine* eng);

  void render();

private:
  GUIFrame frame;

  sf::Vector2i MENU_SIZE;

  bool visible;
};

#endif /* MENUWIDGET_H_ */
