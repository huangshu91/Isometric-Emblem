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
#include "../Interface/GUIFrame.h"
using namespace std;

GameEngine::GameEngine() {
  gameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLOR_DEPTH),
                     GAME_LABEL + " " + VERSION_NUM);
  gameWindow.setFramerateLimit(60);
  //gameWindow.setMouseCursorVisible(false);
  //gameWindow.setVerticalSyncEnabled(true);
  focus = true;

  loadDebug();

  gameData.setup(getEngine());
  gameCam.setup(getWindow());
  gameHUD.setup(getEngine());
  gameEffect.setup(getEngine());

  caravan.setup(getEngine());

  pstate = new PlayState(getEngine());
  pstate->setup();

  gameBat.setup(getEngine(), getPlayState());

  zoom_amt = 0;
}

void GameEngine::cleanup() {
  gameLog.close();
}

void GameEngine::loadDebug() {
  gameRes.addFont(DEFAULT_FONT_KEY, DEFAULT_FONT);
  gameRes.addFont(VISITOR_FONT_KEY, VISITOR_FONT);
}

void GameEngine::runEngine() {
  gameRes.addResource("test", "res/Units/unit_dummy.png");
  sf::Sprite testsprite(*(gameRes.getResource("test")));
  testsprite.setOrigin(testsprite.getLocalBounds().width/2, testsprite.getLocalBounds().height/2);
  testsprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

  //GUIFrame frame;
  //frame.setup(getEngine());
  //frame.build(sf::Vector2i(WINDOW_WIDTH/2, WINDOW_HEIGHT - 80), sf::Vector2i(920,120));

  while (gameWindow.isOpen()) {
    sf::Event ev;
    while (gameWindow.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed) {
        cleanup();
        gameWindow.close();
        return;
      }
      if (ev.type == sf::Event::LostFocus) focus = false;
      if (ev.type == sf::Event::GainedFocus) focus = true;

      if (ev.type == sf::Event::KeyPressed) {
        if (ev.key.code == sf::Keyboard::F1) takeScreenshot();
        if (ev.key.code == sf::Keyboard::Escape) {
          cleanup();
          gameWindow.close();
          return;
        }
      }
      if (ev.type == sf::Event::MouseWheelMoved) changeZoom(ev.mouseWheel.delta);
    }
    gameWindow.clear(WINDOW_COLOR);
    gameWindow.setView(*(getGameCam()->GetView()));
    pstate->update();
    pstate->render();

    //gameWindow.draw(testsprite);
    //frame.render();

    gameWindow.display();
  }
}

void GameEngine::takeScreenshot() {
  gameLog.i("Screenshot taken.");
  sf::Image im = gameWindow.capture();
  im.saveToFile(SS_PATH+"ss_"+gameClock.getFormatTime()+".png");
}

void GameEngine::changeZoom(int fac) {
  //zoom in
  cout << fac << endl;
  if (fac > 0) {
    if (zoom_amt < MAX_ZOOM) {
      getGameCam()->zoomCamera(ZOOM_FACTOR);
      zoom_amt++;
    }
  }
  // zoom out
  else if (fac < 0) {
    if (zoom_amt > MIN_ZOOM) {
      getGameCam()->zoomCamera(1/ZOOM_FACTOR);
      zoom_amt--;
    }
  }
}
