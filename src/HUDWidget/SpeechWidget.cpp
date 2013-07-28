/*
 * SpeechWidget.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#include "SpeechWidget.h"
#include "../System/GameEngine.h"
#include <string>

sf::Vector2i SpeechWidget::MENU_SIZE = sf::Vector2i(920, 160);


SpeechWidget::SpeechWidget() {
  t_rate = TEXT_RATE;
  speaker = 0;
}

SpeechWidget::~SpeechWidget() {
  // TODO Auto-generated destructor stub
}

void SpeechWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  text_hud.setup(eng);

  text_hud.build(sf::Vector2i(WINDOW_WIDTH/2, WINDOW_HEIGHT - (MENU_SIZE.y/2+20)), MENU_SIZE);
  build();
  text_hud.enable();
  enable();
}

void SpeechWidget::build() {

  //cout << diag.getLocalBounds().top << " : " << diag.getLocalBounds().left << " : " << diag.getLocalBounds().height << " : " << diag.getLocalBounds().width << endl;

  //sf::View v = win_ptr->getView();
  //cout << v.getViewport().left << " : " << v.getViewport().top << endl;
}

void SpeechWidget::update() {

}

void SpeechWidget::render() {
  if (!visible) return;

  sf::View v = win_ptr->getView();
  sf::RectangleShape rs(sf::Vector2f(960,300));
  rs.setPosition(v.getViewport().left, v.getViewport().top);
  rs.setFillColor(sf::Color(0,0,0,100));
  win_ptr->draw(rs);

  text_hud.render();
}
