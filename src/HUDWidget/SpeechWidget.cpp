/*
 * SpeechWidget.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#include "SpeechWidget.h"
#include "../System/GameEngine.h"
#include <string>

sf::Vector2i SpeechWidget::MENU_SIZE = sf::Vector2i(920, 120);


SpeechWidget::SpeechWidget() {
  t_rate = TEXT_RATE;
  speaker = 0;
  text = "testing testing testing testing testing testing testing tesitng testng testing testing";
}

SpeechWidget::~SpeechWidget() {
  // TODO Auto-generated destructor stub
}

void SpeechWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);

  frame.build(sf::Vector2i(WINDOW_WIDTH/2, WINDOW_HEIGHT - 80), MENU_SIZE);
  build();
  enable();
}

void SpeechWidget::build() {
  diag.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
  diag.setString(text);
  diag.setColor(sf::Color::Black);
  diag.setCharacterSize(VISITOR_SIZE);
  diag.setPosition(sf::Vector2f(frame.getLoc()));
}

void SpeechWidget::update() {

}

void SpeechWidget::render() {
  if (!visible) return;

  frame.render();
  win_ptr->draw(diag);
}
