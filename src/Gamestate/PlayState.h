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
#include "../Entity/BattleManager.h"

class Map;
class InputController;
class AIController;
class GameEngine;

class PlayState: public GameState {
public:
  PlayState(GameEngine* eng);
  ~PlayState();

  void render();
  void update();
  void setup();

  void changePhase(gamestate::Playphase next);
  gamestate::Playphase getPhase() { return phase; };
  void finishTransition();

private:
  Map* level;
  InputController* input;
  AIController* ai;
  BattleManager* bm;

  gamestate::Playphase phase;
  gamestate::Playphase turn;
  bool wait;
};

#endif /* PLAYSTATE_H_ */
