/*
 * TextWidget.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#include "TextWidget.h"
#include "../System/GameEngine.h"
#include <vector>
#include <string>
using namespace std;

TextWidget::TextWidget() {
  t_rate = TEXT_RATE;
  full_text = "testing testing testing\n\ntesting testing testing\n\ntesting testing testing";
  cur_text = "";
  char_pos = 0;
  timer.resetClock();
  finished = false;
}

TextWidget::~TextWidget() {
  // TODO Auto-generated destructor stub
}

void TextWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng);

  page.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
  page.setString(cur_text);
  page.setColor(sf::Color::Black);
  page.setCharacterSize(VISITOR_SIZE);

}

void TextWidget::setText(vector<string> text) {

}

void TextWidget::build(sf::Vector2i loc, sf::Vector2i size) {
  frame.build(loc, size);
  MENU_SIZE = size;

  sf::Vector2f pos = sf::Vector2f(frame.getLoc());
  pos.x = pos.x - MENU_SIZE.x/2 + 3*VISITOR_SIZE;
  pos.y = pos.y - MENU_SIZE.y/2 + 2*VISITOR_SIZE;

  page.setPosition(pos);
}

void TextWidget::update() {
  if (timer.getElapsedTime() > t_rate && finished == false) {
    cur_text += full_text[char_pos];
    char_pos++;
    if (char_pos >= full_text.length()) finished = true;
    page.setString(cur_text);
    timer.resetClock();
  }
}

void TextWidget::render() {
  if (!visible) return;

  frame.render();
  update();
  win_ptr->draw(page);
}
