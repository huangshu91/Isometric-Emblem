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
#include "../Util/FormatClock.h"
#include "../Entity/BattleManager.h"
#include "../Controller/MenuController.h"
#include "../Controller/SkitController.h"

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

  void changePhase(playstate::Phase next);
  playstate::Phase getPhase() { return phase; };
  void finishTransition();

private:
  void checkZoom();

  Map* level;
  InputController* input;
  AIController* ai;
  BattleManager* bm;
  MenuController mc;
  SkitController sc;

  playstate::Phase phase;
  playstate::Phase turn;
  bool wait;

  int round_num;
};

#endif /* PLAYSTATE_H_ */
