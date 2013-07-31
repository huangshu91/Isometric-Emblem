/*
 * SpeechWidget.h
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#ifndef SPEECHWIDGET_H_
#define SPEECHWIDGET_H_

#include "GUIWidget.h"
#include "TextWidget.h"
#include "../Interface/GUIFrame.h"
#include "../Util/Constants.h"
#include "../Database/Database.h"

struct Speaker {
  std::string name;
  sf::Sprite sp;
};

class SpeechWidget: public GUIWidget {
public:
  SpeechWidget();
  virtual ~SpeechWidget();

  void setup(GameEngine* eng);
  void build();

  void loadConvo(std::string conv);
  void nextPage();

  void update();
  void render();

  static sf::Vector2i MENU_SIZE;
  static sf::Vector2i CHAR_POS[6];

private:
  TextWidget  text_hud;

  std::vector<Speaker> actors;
  Speaker cur_speak;

  float t_rate;
  int cur_page;

  sf::Vector2i MENU_LOC;

  Convo conv;
};

#endif /* SPEECHWIDGET_H_ */
