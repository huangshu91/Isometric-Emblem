/*
 * StrokeText.cpp
 *
 *  Created on: Sep 27, 2013
 *      Author: Maiev
 */

#include "StrokeText.h"
#include "../System/GameEngine.h"
#include <math.h>
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

  text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
  text.setPosition(opt.loc);

  sf::Text s;
  int stroke_size = text.getCharacterSize()/8;

  s.setFont(*(eng_ptr->getRes()->getFont(VISITOR_FONT_KEY)));
  s.setCharacterSize(VISITOR_SIZE);
  s.setColor(sf::Color::White);
  s.setString(opt.s);

  s.setOrigin(s.getLocalBounds().width/2, s.getLocalBounds().height/2);
  s.setPosition(opt.loc.x-stroke_size, opt.loc.y-stroke_size);

  stroke.push_back(s);

  s.setPosition(opt.loc.x+stroke_size, opt.loc.y-stroke_size);

  stroke.push_back(s);

  s.setPosition(opt.loc.x-stroke_size, opt.loc.y+stroke_size);

  stroke.push_back(s);

  s.setPosition(opt.loc.x+stroke_size, opt.loc.y+stroke_size);

  stroke.push_back(s);

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

    for (unsigned int i = 0; i < stroke.size(); i++) {
      sf::Color c2 = stroke[i].getColor();
      c2.a = 255-255*(timer.getElapsedTime()/config.lifetime);
      stroke[i].setColor(c2);
    }
  }

  if (config.bounce) {


  }
}

void StrokeText::render() {
  for (auto it : stroke) {
    win_ptr->draw(it);
  }
  win_ptr->draw(text);
  string s = text.getString();
}
