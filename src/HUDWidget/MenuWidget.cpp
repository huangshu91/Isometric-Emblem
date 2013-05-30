/*
 * MenuWidget.cpp
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#include "MenuWidget.h"
#include "../System/GameEngine.h"
#include "../Util/Constants.h"
#include <cmath>
using namespace std;

MenuWidget::MenuWidget() {
  visible = false;
  num_opt = 0;
  MENU_SIZE = sf::Vector2i(0,0);
  selected = 0;
}

MenuWidget::~MenuWidget() {
  // TODO Auto-generated destructor stub
}

void MenuWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);
}

void MenuWidget::build(sf::Vector2i loc, vector<string> opt) {
  sf::Vector2i size(0,0);
  sf::Vector2i tx_size(0,0);
  num_opt = opt.size();

  for (auto t : opt) {
    sf::Text tx;
    tx.setFont(*(eng_ptr->getRes()->getFont(DEFAULT_FONT_KEY)));
    tx.setCharacterSize(VISITOR_SIZE);
    tx.setColor(sf::Color::Black);
    tx.setString(t);

    if (tx.getLocalBounds().width > tx_size.x) {
      tx_size.x = tx.getLocalBounds().width;
      tx_size.y = tx.getLocalBounds().height;
    }

    tx.setOrigin(tx.getLocalBounds().width/2, 0);
    c_text.push_back(tx);
  }

  // add side borders
  tx_size.x += 2*FONT_SIZE;
  // number of options
  tx_size.y *= num_opt;
  // padding between options
  tx_size.y += (num_opt-1)*(2*MENU_PADDING);
  // add top and bottom borders
  tx_size.y += 2*FONT_SIZE;

  MENU_SIZE.x = ceil(tx_size.x/(float)FRAME_CELL);
  MENU_SIZE.x *= FRAME_CELL;
  MENU_SIZE.y = ceil(tx_size.y/(float)FRAME_CELL);
  MENU_SIZE.y *= FRAME_CELL;
  CENTER = loc;

  frame.build(loc, MENU_SIZE);

  sf::Vector2i topmid = frame.getLoc();
  topmid.y -= frame.getSize().y/2;

  c_text[0].setPosition(loc.x, topmid.y + FONT_SIZE);
  for (int i = 1, j = c_text.size(); i < j; i++) {
    c_text[i].setPosition(loc.x, c_text[i-1].getPosition().y + FONT_SIZE + 2*MENU_PADDING);
  }
}

void MenuWidget::select(int s) {
  if (s < 0 || s > num_opt) return;

  c_text[s].setColor(sf::Color::Green);
}

void MenuWidget::enable() {
  visible = true;
}

void MenuWidget::disable() {
  visible = false;
}

void MenuWidget::render() {
  frame.render();
  for (auto t : c_text) {
    win_ptr->draw(t);
  }
}
