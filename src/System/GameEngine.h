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

class GameEngine {
public:
  GameEngine();

  void runEngine();

  // Pass a reference to self to all children
  GameEngine* getEngine() { return this; };

private:

  sf::RenderWindow _gameWindow;
};


#endif /* GAMEENGINE_H_ */
