/*
 * GameEngine.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#include "GameEngine.h"
#include "../Util/Constants.h"
using namespace std;

GameEngine::GameEngine() {
  _gameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLOR_DEPTH),
                     GAME_LABEL + " " + VERSION_NUM);
}


