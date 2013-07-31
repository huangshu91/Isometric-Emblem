/*
 * SkitController.h
 *
 *  Created on: Jul 27, 2013
 *      Author: Maiev
 */

#ifndef SKITCONTROLLER_H_
#define SKITCONTROLLER_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameEngine;
class SpeechWidget;

class SkitController {
public:
  SkitController();
  virtual ~SkitController();

  void setup(GameEngine* eng);

  void update();
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  SpeechWidget* sw;
};

#endif /* SKITCONTROLLER_H_ */
