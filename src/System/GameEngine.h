/*
 * GameEngine.h
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Util/FormatClock.h"
#include "../Util/Constants.h"
#include "../Util/Logger.h"
#include "../Database/Database.h"
#include "../Entity/BattleManager.h"
#include "../Database/Caravan.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "HUDManager.h"
#include "EffectManager.h"

class GameState;
class PlayState;

class GameEngine {
public:
  GameEngine();

  void runEngine();
  void cleanup();

  // Pass a reference to self to all subsystems
  GameEngine* getEngine() { return this; };
  sf::RenderWindow* getWindow() {return (&gameWindow);};
  ResourceManager* getRes() {return (&gameRes);};
  Camera* getGameCam() { return &gameCam; };
  HUDManager* getHUD() { return &gameHUD; };
  Logger* getLog() { return &gameLog; };
  Database* getDatabase() { return &gameData; };
  BattleManager* getBattle() { return &gameBat; };
  EffectManager* getEffect() { return &gameEffect; };

  Caravan* getCaravan() { return &caravan; };

  PlayState* getPlayState() { return pstate; };

  bool hasFocus() { return focus; };

private:
  void loadDebug();
  void changeState(gamestate::Statetype newstate);
  void takeScreenshot();
  void changeZoom(int fac);

  gamestate::Statetype stateId;
  std::vector<GameState*> states;

  sf::RenderWindow    gameWindow;
  FormatClock         gameClock;
  ResourceManager     gameRes;
  HUDManager          gameHUD;
  Camera              gameCam;
  Logger              gameLog;
  Database            gameData;
  BattleManager       gameBat;
  EffectManager       gameEffect;

  Caravan             caravan;

  PlayState* pstate;

  bool focus;
  int zoom_amt;

  FormatClock timer;
};


#endif /* GAMEENGINE_H_ */
