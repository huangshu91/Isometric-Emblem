/*
 * TextWidget.h
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#ifndef TEXTWIDGET_H_
#define TEXTWIDGET_H_

#include "GUIWidget.h"
#include "../Interface/GUIFrame.h"
#include "../Util/Constants.h"

class TextWidget: public GUIWidget {
public:
  TextWidget();
  virtual ~TextWidget();

  void setup(GameEngine* eng);
  void build();

  void render();

private:
  GUIFrame frame;

  sf::Vector2i MENU_SIZE;
  sf::Vector2i CENTER;

  sf::Sprite icon;
  sf::Text name;
  std::vector<sf::Text> text;
};

#endif /* TEXTWIDGET_H_ */
