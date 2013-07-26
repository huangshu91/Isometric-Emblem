/*
 * EXPWidget.cpp
 *
 *  Created on: May 25, 2013
 *      Author: Maiev
 */

#include "EXPWidget.h"
#include "../System/GameEngine.h"
#include "../Entity/DynamicEntity.h"
#include "../Util/Constants.h"
#include "../Util/UtilFunc.h"
#include <string>
#include <iostream>

sf::Vector2i EXPWidget::MENU_SIZE = sf::Vector2i(440, 80);

EXPWidget::EXPWidget() {
  start = 0;
  end = 0;
  cur = 0;
  incFlag = false;

  unit = 0;
}

EXPWidget::~EXPWidget() {
  // TODO Auto-generated destructor stub
}

void EXPWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);
  sf::Vector2i loc(WINDOW_WIDTH/2, WINDOW_HEIGHT);
  loc.y -= MENU_SIZE.y/2 + GUI_PADDING;
  frame.build(loc, MENU_SIZE);

  label.setFont(*(eng_ptr->getRes()->getFont(DEFAULT_FONT_KEY)));
  val.setFont(*(eng_ptr->getRes()->getFont(DEFAULT_FONT_KEY)));
  label.setCharacterSize(LABEL_SIZE);
  val.setCharacterSize(LABEL_SIZE);

  label.setString("EXP");
  val.setString("00");

  sf::Vector2i topleft = frame.getLoc();
  topleft.x -= frame.getSize().x/2;
  topleft.y -= frame.getSize().y/2;
  label.setPosition(topleft.x, topleft.y);
  label.move(20,15);
  label.setColor(sf::Color::Black);

  val.setPosition(topleft.x, topleft.y);
  val.setOrigin(val.getLocalBounds().width/2, val.getLocalBounds().height/2);
  val.move(20+label.getLocalBounds().width/2,45);
  val.setColor(sf::Color::Black);

  expbar.setup(eng_ptr);
  sf::Vector2i size(332, 15);
  sf::Vector2i locexp(78+topleft.x+size.x/2, frame.getLoc().y);
  expbar.build(locexp, size);
  expbar.setProg(10);
}

void EXPWidget::updateChar(DynamicEntity* e, int from, int to) {
  unit = e;
  start = from;
  cur = from;
  end = to;

  enable();
  timer.resetClock();

  expbar.growProg(from, to);

  val.setString(numberToString(from));
  incFlag = true;
}

void EXPWidget::update() {
  if (incFlag == false) return;
  cur += EXP_RATE;
  if (cur > end) {
    cur = end;
    incFlag = false;
  }
  if (cur == 100) unit->levelUp();

  val.setString(numberToString(cur));
}

void EXPWidget::render() {
  if (!visible) return;

  update();
  frame.render();
  expbar.update();
  expbar.render();
  win_ptr->draw(label);
  win_ptr->draw(val);

  if (timer.getElapsedTime() > EXP_DUR) disable();
}
