/*
 * SpeechWidget.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#include "SpeechWidget.h"
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
}

void SpeechWidget::build() {

}

void SpeechWidget::update() {

}

void SpeechWidget::render() {
  if (!visible) return;

  frame.render();
}
