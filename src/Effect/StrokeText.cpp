/*
 * StrokeText.cpp
 *
 *  Created on: Sep 27, 2013
 *      Author: Maiev
 */

#include "StrokeText.h"
#include "../System/GameEngine.h"
using namespace std;

StrokeText::StrokeText() {
  type = effect::TEXT;

}

StrokeText::~StrokeText() {
  // TODO Auto-generated destructor stub
}

void StrokeText::setup(GameEngine* eng, sf::Vector2f loc, string s) {
  Effect::setup(eng);

  text.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
  text.setCharacterSize(VISITOR_SIZE);
  text.setColor(sf::Color::Black);
  text.setString(s);

  text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height);
  text.setPosition(loc);

  int STROKE_SIZE = VISITOR_SIZE/6;
}

void StrokeText::update() {

}

void StrokeText::render() {
  win_ptr->draw(text);
}
