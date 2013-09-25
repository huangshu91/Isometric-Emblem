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
#include "../Effect/Effect.h"

class GameEngine;

class EffectManager {
public:
  EffectManager();
  virtual ~EffectManager();

  void setup(GameEngine* eng);

  void update();
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::vector<Effect> eff_col;

  int num_effects;
};

#endif /* EFFECTMANAGER_H_ */
