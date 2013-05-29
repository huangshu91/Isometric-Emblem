/*
 * StatusWidget.cpp
 *
 *  Created on: May 15, 2013
 *      Author: Maiev
 */

#include "StatusWidget.h"
#include "../Entity/DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Util/Constants.h"
#include "../Util/UtilFunc.h"
#include <string>

sf::Vector2i StatusWidget::MENU_SIZE = sf::Vector2i(280, 120);

StatusWidget::StatusWidget() {
  cur_ent = 0;
  visible = false;
}

StatusWidget::~StatusWidget() {
  // TODO Auto-generated destructor stub
}

void StatusWidget::setup(GameEngine* eng, dir::Direction d) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);

  sf::Vector2i loc(0,0);
  if (d == dir::RIGHT) {
    loc.x = WINDOW_WIDTH;
    loc.x -= MENU_SIZE.x/2 + GUI_PADDING;
  } else {
    loc.x += MENU_SIZE.x/2 + GUI_PADDING;
  }
  loc.y += MENU_SIZE.y/2 + GUI_PADDING;
  frame.build(loc, MENU_SIZE);

  tex.loadFromFile(PORTRAIT_ICON);
  icon.setTexture(tex);
  sf::Vector2i topleft = frame.getLoc() - frame.getSize()/2;
  icon.setPosition(topleft.x + 15, topleft.y +15);

  name.setFont(*(eng_ptr->getRes()->getFont(DEFAULT_FONT_KEY)));
  hp.setFont(*(eng_ptr->getRes()->getFont(DEFAULT_FONT_KEY)));
  name.setCharacterSize(LABEL_SIZE);
  hp.setCharacterSize(FONT_SIZE);
  name.setString("TEST");
  hp.setString("60/60 HP");

  name.setOrigin(name.getLocalBounds().width/2, name.getLocalBounds().height/2);
  hp.setOrigin(hp.getLocalBounds().width/2, hp.getLocalBounds().height/2);

  sf::Vector2i topright = frame.getLoc();
  topright.x += frame.getSize().x/2;
  topright.y -= frame.getSize().y/2;
  name.setPosition(topright.x, topright.y);

  name.setPosition(topright.x - (MENU_SIZE.x-120)/2, topright.y + (MENU_SIZE.y)/4);
  hp.setPosition(topright.x - (MENU_SIZE.x-120)/2, topright.y + 2*(MENU_SIZE.y)/4);
}

void StatusWidget::updateChar(DynamicEntity* e) {
  cur_ent = e;
  update();
}

void StatusWidget::update() {
  if (cur_ent == 0) return;
  name.setColor(sf::Color::Black);
  name.setString(cur_ent->name);
  name.setOrigin(name.getLocalBounds().width/2, name.getLocalBounds().height/2);
  string hpstring;
  hpstring += numberToString(cur_ent->total.hp);
  hpstring += "/";
  hpstring += numberToString(cur_ent->total.max_hp);
  hpstring += " HP";
  hp.setColor(sf::Color::Black);
  hp.setString(hpstring);
  hp.setOrigin(hp.getLocalBounds().width/2, hp.getLocalBounds().height/2);
}

// eventually have in and out animations for visibility
void StatusWidget::setVisible(bool vis) {
  //animation based on previous visibility
  // if (visible == vis) do something

  visible = vis;
}

void StatusWidget::render() {
  if (!visible) return;

  update();
  frame.render();
  win_ptr->draw(icon);
  win_ptr->draw(name);
  win_ptr->draw(hp);
}

