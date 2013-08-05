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
#include "../Util/FormatClock.h"

class GameEngine;
class SpeechWidget;

class SkitController {
public:
  SkitController();
  virtual ~SkitController();

  void setup(GameEngine* eng);
  void enable();

  void update();
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  FormatClock timer;

  SpeechWidget* sw_ptr;
  TextWidget* tw_ptr;
};

#endif /* SKITCONTROLLER_H_ */
