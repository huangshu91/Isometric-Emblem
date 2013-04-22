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
#include "../Util/FormatClock.h"
#include "Camera.h"
#include "ResourceManager.h"

class GameEngine {
public:
  GameEngine();

  void runEngine();

  // Pass a reference to self to all subsystems
  GameEngine* getEngine() { return this; };
  sf::RenderWindow* getWindow() {return (&gameWindow);};
  ResourceManager* getRes() {return (&gameRes);};


private:

  void loadDebug();

  sf::RenderWindow    gameWindow;
  FormatClock         gameClock;
  ResourceManager     gameRes;
  Camera              gameCam;
};


#endif /* GAMEENGINE_H_ */
