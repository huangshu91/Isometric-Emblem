/*
 * StrokeText.h
 *
 *  Created on: Sep 27, 2013
 *      Author: Maiev
 */

#ifndef STROKETEXT_H_
#define STROKETEXT_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Effect/Effect.h"
#include <string>

class GameEngine;

#include "Effect.h"

class StrokeText: public Effect {
public:
  StrokeText();
  virtual ~StrokeText();

  void update();
  void render();

  void setup(GameEngine* eng, sf::Vector2f loc, std::string s);

private:
  sf::Text text;
  std::string s;
};

#endif /* STROKETEXT_H_ */
