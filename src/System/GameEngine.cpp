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
  gameRes.addResource(TILE_HIGH_KEY, TILE_HIGH);
}


void GameEngine::runEngine() {
  Map testboard(getEngine());
  testboard.setDimensions(3,6);
  InputController input(getEngine());
  input.setMap(&testboard);
  input.setCurrentCell(1,3);
  gameCam.setCenter(sf::Vector2f(input.getCurrentCenter()));
  gameCam.zoomCamera(0.9f);

  GUIFrame frame;
  frame.setup(getEngine());
  frame.build(sf::Vector2i(100,100), sf::Vector2i(120,120));

  GUIDisplay display;
  display.setup(getEngine());
  display.build(sf::Vector2i(100,300), sf::Vector2i(120,120));
  vector<string> tempv;
  tempv.push_back("test1");
  tempv.push_back("longertest");
  tempv.push_back("test3");
  display.setText(tempv);

  gameHUD.addWidget(HUD_MENU, &frame);
  gameHUD.addWidget("test", &display);

  sf::Text t("testing text", sf::Font::getDefaultFont(), FONT_SIZE);
  t.setPosition(300,300);

  while (gameWindow.isOpen()) {
    sf::Event ev;

    while (gameWindow.pollEvent(ev)) {
          if (ev.type == sf::Event::Closed)
            gameWindow.close();
          input.update();
    }

    gameWindow.clear(WINDOW_COLOR);
    //input.update();
    gameCam.update();

    gameWindow.setView(*(gameCam.GetView()));

    testboard.render();
    input.render();

    gameHUD.render();


    //gameWindow.draw(t);
    gameWindow.display();
  }

}
