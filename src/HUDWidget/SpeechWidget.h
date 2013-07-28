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

class SpeechWidget: public GUIWidget {
public:
  SpeechWidget();
  virtual ~SpeechWidget();

  void setup(GameEngine* eng);
  void build();

  void update();
  void render();

  static sf::Vector2i MENU_SIZE;

private:
  //placeholder for portrait;
  sf::Texture   port;
  sf::Text      name;

  TextWidget  text_hud;

  std::vector<sf::Sprite> actors;
  sf::Sprite* speaker;

  int t_rate;

  std::string text;
  sf::Text diag;
};

#endif /* SPEECHWIDGET_H_ */
