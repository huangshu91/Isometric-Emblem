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
#include "Camera.h"
#include "ResourceManager.h"
#include "HUDManager.h"

class GameState;
class PlayState;

class GameEngine {
public:
  GameEngine();

  void runEngine();

  // Pass a reference to self to all subsystems
  GameEngine* getEngine() { return this; };
  sf::RenderWindow* getWindow() {return (&gameWindow);};
  ResourceManager* getRes() {return (&gameRes);};
  Camera* getGameCam() { return &gameCam; };
  HUDManager* getHUD() { return &gameHUD; };

  PlayState* getPlayState() { return pstate; };

private:

  void loadDebug();
  void ChangeState(gamestate::Statetype newstate);

  gamestate::Statetype stateId;
  std::vector<GameState*> states;

  sf::RenderWindow    gameWindow;
  FormatClock         gameClock;
  ResourceManager     gameRes;
  HUDManager          gameHUD;
  Camera              gameCam;

  PlayState* pstate;
};


#endif /* GAMEENGINE_H_ */
