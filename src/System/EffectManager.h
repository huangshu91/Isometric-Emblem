/*
 * EffectManager.h
 *
 *  Created on: Aug 25, 2013
 *      Author: Maiev
 */
#ifndef EFFECTMANAGER_H_
#define EFFECTMANAGER_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "../Effect/Effect.h"
#include "../Effect/StrokeText.h"
#include "../Util/Constants.h"

class GameEngine;

class EffectManager {
public:
  EffectManager();
  virtual ~EffectManager();

  void setup(GameEngine* eng);

  void update();
  void render();

  void addEffect(effect::Object o, effect::param opt);
  void addEffect(effect::Type t);

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::list<StrokeText> text_col;

  Effect* currentEffect;

  int num_effects;
};

#endif /* EFFECTMANAGER_H_ */
