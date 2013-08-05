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
  full_line = "";
  cur_line = "";
  char_pos = 0;
  line_num = 0;
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
  page.setString(cur_line);
  page.setColor(sf::Color::Black);
  page.setCharacterSize(VISITOR_SIZE);
}

void TextWidget::reset() {
  full_text = "";
  cur_line = "";
  char_pos = 0;
  line_num = 0;
  timer.resetClock();
  finished = false;
}

void TextWidget::setText(vector<string> s) {
  finished = false;
  line_num = 0;
  cur_line = "";
  full_line = s[line_num];
  full_text = s;
  page.setString(cur_line);
  char_pos = 0;
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
    cur_line += full_line[char_pos];
    char_pos++;
    if (char_pos >= full_line.length()) {
      line_num++;
      if (line_num < full_text.size()) {
        cur_line += "\n\n";
        full_line = full_text[line_num];
        char_pos = 0;
      }
      if (line_num >= full_text.size()) {
        finished = true;
      }
    }
    page.setString(cur_line);
    timer.resetClock();
  }
}

void TextWidget::render() {
  if (!visible) return;

  frame.render();
  //update();
  win_ptr->draw(page);
}
