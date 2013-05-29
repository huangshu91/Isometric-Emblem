/*
 * MenuWidget.cpp
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#include "MenuWidget.h"
#include "../Util/Constants.h"

MenuWidget::MenuWidget() {
  visible = false;
}

MenuWidget::~MenuWidget() {
  // TODO Auto-generated destructor stub
}

void MenuWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);
  sf::Vector2i loc(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
  sf::Vector2i base(120,120);
  frame.build(loc, base);

}

void MenuWidget::render() {
  frame.render();
}
