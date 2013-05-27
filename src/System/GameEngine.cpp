/*
 * GameEngine.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#include "GameEngine.h"
#include "../Util/Constants.h"
#include "../Gamestate/PlayState.h"
#include <iostream>

//debug includes
using namespace std;

GameEngine::GameEngine() {
  gameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLOR_DEPTH),
                     GAME_LABEL + " " + VERSION_NUM);

  gameWindow.setFramerateLimit(60);
  //gameWindow.setVerticalSyncEnabled(true);
  focus = true;

  loadDebug();

  gameCam.setup(getWindow());
  gameHUD.setup(getEngine());
  gameData.setup(getEngine());
}

void GameEngine::loadDebug() {
  gameRes.addFont(DEFAULT_FONT_KEY, DEFAULT_FONT);
}

void GameEngine::runEngine() {

  gameRes.addResource(PHASE_PLAYER_KEY, PHASE_PLAYER);
  gameRes.addResource(PHASE_ENEMY_KEY, PHASE_ENEMY);
  sf::Sprite testsprite(*(gameRes.getResource(PHASE_PLAYER_KEY)));
  testsprite.setOrigin(testsprite.getLocalBounds().width/2, testsprite.getLocalBounds().height/2);
  testsprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

  pstate = new PlayState(getEngine());
  pstate->setup();

  gameBat.setup(getEngine(), getPlayState());

  while (gameWindow.isOpen()) {
    sf::Event ev;
    while (gameWindow.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed) gameWindow.close();

      if (ev.type == sf::Event::LostFocus) focus = false;
      if (ev.type == sf::Event::GainedFocus) focus = true;

      if (ev.type == sf::Event::KeyPressed) {
        if (ev.key.code == sf::Keyboard::F1) {
          gameLog.i("Screenshot taken.");
          sf::Image im = gameWindow.capture();
          im.saveToFile(SS_PATH+"ss_"+gameClock.getFormatTime()+".png");
        }
      }
    }
    gameWindow.clear(WINDOW_COLOR);

    pstate->update();
    pstate->render();

    gameWindow.display();
  }

}
