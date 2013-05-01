/*
 * GameEngine.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#include "GameEngine.h"
#include "../Util/Constants.h"
#include "../Levelmap/Map.h"
#include "../Levelmap/InputController.h"
#include "../Interface/GUIDisplay.h"
#include "../Interface/TerrainMenu.h"
#include "../Entity/DynamicEntity.h"
#include <iostream>
using namespace std;

GameEngine::GameEngine() {
  gameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLOR_DEPTH),
                     GAME_LABEL + " " + VERSION_NUM);

  gameWindow.setFramerateLimit(60);
  gameWindow.setVerticalSyncEnabled(true);

  loadDebug();

  gameCam.setup(getWindow());
  gameHUD.setup(getEngine());
}

void GameEngine::loadDebug() {
  gameRes.addResource(TILE_KEY, TILE_ROCK);
  gameRes.addResource(SPRITE_KEY, TEMP_SPRITE);
  gameRes.addFont(DEFAULT_FONT_KEY, DEFAULT_FONT);
}


void GameEngine::runEngine() {
  Map testboard(getEngine());
  testboard.setDimensions(3,6);
  testboard.setupEntity();
  InputController input(getEngine());
  input.setMap(&testboard);
  input.setCurrentCell(1,3);
  gameCam.setCenter(sf::Vector2f(input.getCurrentCenter()));
  gameCam.zoomCamera(0.8f);

  while (gameWindow.isOpen()) {
    sf::Event ev;

    while (gameWindow.pollEvent(ev)) {
          if (ev.type == sf::Event::Closed)
            gameWindow.close();
    }

    gameWindow.clear(WINDOW_COLOR);
    input.update();
    gameCam.update();

    gameWindow.setView(*(gameCam.GetView()));

    testboard.render();
    input.render();
    testboard.renderUnits();

    gameHUD.render();

    gameWindow.display();
  }

}
