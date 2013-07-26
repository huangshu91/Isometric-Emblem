/*
 * PhaseWidget.h
 *
 *  Created on: May 12, 2013
 *      Author: Maiev
 */

#ifndef PHASEWIDGET_H_
#define PHASEWIDGET_H_

#include <SFML/Graphics.hpp>
#include "GUIWidget.h"
#include "../Util/Constants.h"
#include "../Util/FormatClock.h"

class GameEngine;

class PhaseWidget : public GUIWidget {
public:
  PhaseWidget();
  virtual ~PhaseWidget();

  void setup(GameEngine* eng);
  void changePhase(playstate::Phase p);
  void render();

private:
  playstate::Phase phase;

  sf::Sprite player_sprite;
  sf::Sprite enemy_sprite;

  FormatClock timer;
};

#endif /* PHASEWIDGET_H_ */
