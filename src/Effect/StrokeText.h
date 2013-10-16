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
#include <vector>

class GameEngine;

class StrokeText: public Effect {
public:
  StrokeText();
  virtual ~StrokeText();

  void update();
  void render();

  void setup(GameEngine* eng, effect::param opt);

private:
  sf::Text text;
  std::vector<sf::Text> stroke;
  std::string s;
};

#endif /* STROKETEXT_H_ */
