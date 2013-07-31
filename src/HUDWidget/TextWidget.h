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
#include "../Util/FormatClock.h"
#include <vector>
#include <string>

class TextWidget: public GUIWidget {
public:
  TextWidget();
  virtual ~TextWidget();

  void setup(GameEngine* eng);
  void build(sf::Vector2i loc, sf::Vector2i size);

  void setText(std::vector<std::string> text);

  void update();

  void render();

  sf::Vector2i getMenuSize() { return MENU_SIZE; };

private:
  GUIFrame frame;

  sf::Vector2i MENU_SIZE;
  sf::Vector2i CENTER;

  int t_rate;
  FormatClock timer;

  sf::Sprite icon;
  sf::Text name;
  std::vector<sf::Text> text;
};

#endif /* TEXTWIDGET_H_ */
