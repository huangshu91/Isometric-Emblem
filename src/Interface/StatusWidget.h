/*
 * StatusWidget.h
 *
 *  Created on: May 15, 2013
 *      Author: Maiev
 */

#ifndef STATUSWIDGET_H_
#define STATUSWIDGET_H_

#include "GUIFrame.h"
#include "GUIWidget.h"

#include "GUIWidget.h"

class GameEngine;
class DynamicEntity;

class StatusWidget: public GUIWidget {
public:
  StatusWidget();
  virtual ~StatusWidget();

  void setup(GameEngine* eng);
  void updateChar(DynamicEntity* e);
  void setVisible(bool vis);

  void render();

private:
  GUIFrame frame;
  sf::Sprite icon;

  static sf::Vector2i MENU_SIZE;

  //temporary placeholder for portrait
  sf::Texture tex;
  sf::Text    name;
  sf::Text    hp;

  bool visible;
};

#endif /* STATUSWIDGET_H_ */
