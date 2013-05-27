/*
 * EXPWidget.h
 *
 *  Created on: May 25, 2013
 *      Author: Maiev
 */

#ifndef EXPWIDGET_H_
#define EXPWIDGET_H_

#include "GUIWidget.h"
#include "../Interface/GUIFrame.h"
#include "../Interface/GUIProgressBar.h"
#include "../Util/FormatClock.h"

class GameEngine;
class DynamicEntity;

class EXPWidget: public GUIWidget {
public:
  EXPWidget();
  virtual ~EXPWidget();

  void setup(GameEngine* eng);
  void updateChar(DynamicEntity* e, int from, int to);
  void setVisible(bool vis);
  DynamicEntity* getCurEnt() { return unit; };

  void render();
  void update();

private:
  GUIFrame frame;
  GUIProgressBar expbar;
  FormatClock timer;

  static sf::Vector2i MENU_SIZE;

  sf::Text label;
  sf::Text val;

  int start;
  int end;
  int cur;
  bool incFlag;
  DynamicEntity* unit;

  bool visible;
};

#endif /* EXPWIDGET_H_ */
