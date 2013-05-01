/*
 * GUIDisplay.cpp
 *
 *  Created on: Apr 26, 2013
 *      Author: Maiev
 */
#include "GUIDisplay.h"
#include "../Util/Constants.h"
#include "../System/GameEngine.h"
#include <iostream>
using namespace std;

GUIDisplay::GUIDisplay() {
  // TODO Auto-generated constructor stub

}

GUIDisplay::~GUIDisplay() {
  // TODO Auto-generated destructor stub
}

// consider adding a size argument to update
void GUIDisplay::setText(vector<string> args) {
  for (int i = 0, j = args.size(); i < j; i++) {
    sf::Text t(args[i], *(eng_ptr->getRes()->getFont(DEFAULT_FONT_KEY)));
    t.setCharacterSize(FONT_SIZE);
    sf::Vector2i pos = getLoc() - (getSize()/2);
    pos += sf::Vector2i(FONT_SIZE, FONT_SIZE);
    t.setPosition(pos.x, pos.y + i*2*FONT_SIZE);
    draw_text.push_back(t);
  }
}

void GUIDisplay::render() {
  GUIFrame::render();
  for (int i = 0, j = draw_text.size(); i < j; i++) {
    win_ptr->draw(draw_text[i]);
  }
}
