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

void StrokeText::setup(GameEngine* eng, effect::param opt) {
  Effect::setup(eng, opt);

  text.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
  text.setCharacterSize(VISITOR_SIZE);
  text.setColor(sf::Color::Black);
  text.setString(opt.s);

  text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height);
  text.setPosition(opt.loc);

  //int STROKE_SIZE = VISITOR_SIZE/6;
  timer.resetClock();
}

void StrokeText::update() {
  if (config.disappear && timer.getElapsedTime() >= config.lifetime) {
    end = true;
  }

  if (config.fade) {
    sf::Color c = text.getColor();
    c.a = 255-255*(timer.getElapsedTime()/config.lifetime);
    text.setColor(c);
  }
}

void StrokeText::render() {
  win_ptr->draw(text);
}
