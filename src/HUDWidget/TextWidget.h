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
  void reset();

  void setText(std::vector<std::string> s);
  bool isFinished() { return finished; };

  void update();

  void render();

  sf::Vector2i getMenuSize() { return MENU_SIZE; };

private:
  GUIFrame frame;

  sf::Vector2i MENU_SIZE;
  sf::Vector2i CENTER;

  float t_rate;
  FormatClock timer;
  bool finished;

  unsigned int line_num;
  unsigned int char_pos;
  std::string cur_line;
  std::string full_line;
  std::vector<std::string> full_text;
  sf::Sprite cont_button;
  sf::Text page;
};

#endif /* TEXTWIDGET_H_ */
