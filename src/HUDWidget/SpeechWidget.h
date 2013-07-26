/*
 * SpeechWidget.h
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#ifndef SPEECHWIDGET_H_
#define SPEECHWIDGET_H_

#include "GUIWidget.h"
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
  GUIFrame frame;

  //placeholder for portrait;
  sf::Texture   tex;
  sf::Text      name;

  std::vector<sf::Sprite> actors;
  sf::Sprite* speaker;

  int t_rate;
};

#endif /* SPEECHWIDGET_H_ */
