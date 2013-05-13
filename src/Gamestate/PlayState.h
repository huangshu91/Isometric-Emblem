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
#include "../Util/Constants.h"

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

  gamestate::Playphase phase;
  void changePhase(gamestate::Playphase next);
  void finishTransition();

private:
  Map* level;
  InputController* input;

  bool wait;
};

#endif /* PLAYSTATE_H_ */
