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
}

TextWidget::~TextWidget() {
  // TODO Auto-generated destructor stub
}

void TextWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng);

  sf::Text page;
  page.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
  page.setString("testing testing testing\n\ntesting testing testing\n\ntesting testing testing");
  page.setColor(sf::Color::Black);
  page.setCharacterSize(VISITOR_SIZE);
  text.push_back(page);

}

void TextWidget::setText(vector<string> text) {

}

void TextWidget::build(sf::Vector2i loc, sf::Vector2i size) {
  frame.build(loc, size);
  MENU_SIZE = size;

  sf::Vector2f pos = sf::Vector2f(frame.getLoc());
  pos.x = pos.x - MENU_SIZE.x/2 + 3*VISITOR_SIZE;
  pos.y = pos.y - MENU_SIZE.y/2 + 2*VISITOR_SIZE;

  for (unsigned int i = 0; i < text.size(); i++) {
    text[i].setPosition(pos);
  }
}

void TextWidget::update() {

}

void TextWidget::render() {
  if (!visible) return;

  frame.render();
  for (sf::Text t : text) {
    win_ptr->draw(t);
  }
}
