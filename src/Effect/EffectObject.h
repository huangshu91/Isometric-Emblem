/*
 * Effect.h
 *
 *  Created on: Sep 24, 2013
 *      Author: Maiev
 */

#ifndef EFFECT_H_
#define EFFECT_H_
#include "../Util/FormatClock.h"
#include "../Util/Constants.h"

class GameEngine;

class Effect {
public:
  Effect();
  virtual ~Effect();

  void setup(GameEngine* eng);

  virtual void update() = 0;
  virtual void render() = 0;

  bool ended() { return false; };

protected:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  effect::Object type;
  FormatClock   timer;

  bool bounce;
  bool fade;
};

#endif /* EFFECT_H_ */
