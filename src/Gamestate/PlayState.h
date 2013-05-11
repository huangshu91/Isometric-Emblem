/*
 * PlayState.h
 *
 *  Created on: May 11, 2013
 *      Author: Maiev
 */

#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Map;
class InputController;
class GameEngine;

class PlayState: public GameState {
public:
  PlayState(GameEngine* eng);
  ~PlayState();

  void render();
  void update();
  void setup();

private:
  Map* level;
  InputController* input;
};

#endif /* PLAYSTATE_H_ */
