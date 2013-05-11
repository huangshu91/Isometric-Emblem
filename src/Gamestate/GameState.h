/*
 * GameState.h
 *
 *  Created on: Jun 24, 2012
 *      Author: Maiev
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Util/Constants.h"

class GameEngine;

class GameState {
public:
  GameState(GameEngine* eng);
  virtual void render() = 0;
  virtual void update() = 0;
  //virtual void setup() = 0;
  virtual ~GameState() {};

  gamestate::Statetype getId() { return stateId; };

protected:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  gamestate::Statetype stateId;
};

#endif /* GAMESTATE_H_ */
