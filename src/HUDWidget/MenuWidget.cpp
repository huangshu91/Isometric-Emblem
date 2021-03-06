/*
 * MenuWidget.cpp
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#include "MenuWidget.h"
#include "../System/GameEngine.h"
#include "../Util/Constants.h"
#include "../Gamestate/PlayState.h"
#include <cmath>
using namespace std;

MenuWidget::MenuWidget() {
  num_opt = 0;
  MENU_SIZE = sf::Vector2i(0,0);
  selected = 0;
  parent = 0;
  anc = anchor::UNDEF;
  menu_id = "";
  has_focus = false;
}

MenuWidget::~MenuWidget() {
  // TODO Auto-generated destructor stub
}

void MenuWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);

  eng->getRes()->addResource(MENU_CURSOR_KEY, MENU_CURSOR);
  menu_cursor.setTexture(*(eng->getRes()->getResource(MENU_CURSOR_KEY)));
  menu_cursor.setOrigin(menu_cursor.getLocalBounds().width, 0);
}

// loc is topleft, not center.  This is because the menu size is
// variable so center position does not make sense.  Instead use
// topleft for positioning relative to other widgets.
void MenuWidget::build(sf::Vector2i loc, vector<string> opt, anchor::Region a) {
  sf::Vector2i size(0,0);
  sf::Vector2i tx_size(0,0);
  choices.clear();
  c_text.clear();
  num_opt = opt.size();

  orig = loc;

  for (auto t : opt) {
    sf::Text tx;
    tx.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
    tx.setCharacterSize(VISITOR_SIZE);
    tx.setColor(sf::Color::Black);
    tx.setString(t);

    if (tx.getLocalBounds().width > tx_size.x) {
      tx_size.x = tx.getLocalBounds().width;
      tx_size.y = tx.getLocalBounds().height;
    }

    tx.setOrigin(tx.getLocalBounds().width/2, 0);
    c_text.push_back(tx);
    choices.push_back(t);
  }

  // add side borders
  tx_size.x += 2*FONT_SIZE;
  // number of options
  tx_size.y *= num_opt;
  // padding between options
  tx_size.y += (num_opt-1)*(3*MENU_PADDING);
  // add top and bottom borders
  tx_size.y += 2*FONT_SIZE;

  MENU_SIZE.x = ceil(tx_size.x/(float)FRAME_CELL);
  MENU_SIZE.x *= FRAME_CELL;
  MENU_SIZE.y = ceil(tx_size.y/(float)FRAME_CELL);
  MENU_SIZE.y *= FRAME_CELL;
  CENTER = loc;
  setAnchor(a);

  frame.build(CENTER, MENU_SIZE);

  sf::Vector2i topmid = frame.getLoc();
  topmid.y -= frame.getSize().y/2;

  c_text[0].setPosition(CENTER.x, topmid.y + FONT_SIZE);
  for (int i = 1, j = c_text.size(); i < j; i++) {
    c_text[i].setPosition(CENTER.x,
        c_text[i-1].getPosition().y + FONT_SIZE + 2*MENU_PADDING);
  }

  select(0);
}

// only use this menu if menu was already built with full params
void MenuWidget::build(vector<string> opt) {
  if (anc == anchor::UNDEF) return;
  build(orig, opt, anc);
}

// get child menuwidget that matches string s
MenuWidget* MenuWidget::getChild(string s) {
  for (auto mw : children) {
    if (mw->getMenuId().compare(s) == 0) {
      return mw;
    }
  }
  return 0;
}

void MenuWidget::setAnchor(anchor::Region a) {
  anc = a;
  switch (a) {
  case anchor::TOPLEFT:
    CENTER.x += MENU_SIZE.x/2;
    CENTER.y += MENU_SIZE.y/2;
    break;
  case anchor::TOPRIGHT:
    CENTER.x -= MENU_SIZE.x/2;
    CENTER.y += MENU_SIZE.y/2;
    break;
  case anchor::BOTLEFT:
    CENTER.x += MENU_SIZE.x/2;
    CENTER.y -= MENU_SIZE.y/2;
    break;
  case anchor::BOTRIGHT:
    CENTER.x -= MENU_SIZE.x/2;
    CENTER.y -= MENU_SIZE.y/2;
    break;
  case anchor::CENTER:
    break;
  default:
    break;
  }
}

void MenuWidget::select(int s) {
  if (s < 0) s = num_opt-1;
  if (s > num_opt-1) s = 0;

  menu_cursor.setPosition(c_text[s].getPosition().x - c_text[s].getLocalBounds().width/2,
      c_text[s].getPosition().y);

  c_text[selected].setColor(sf::Color::Black);
  selected = s;
  c_text[s].setColor(sf::Color::Green);
}

// don't need to check if child already exists because they are only
// added from a single place and relationships are set from the start.
void MenuWidget::addChild(MenuWidget* mw) {
  children.push_back(mw);
  mw->parent = this;
}

void MenuWidget::enable() {
  GUIWidget::enable();
  select(0);
}

void MenuWidget::render() {
  if (!visible) return;
  frame.render();
  for (auto t : c_text) {
    win_ptr->draw(t);
  }
  if (has_focus) win_ptr->draw(menu_cursor);
}
