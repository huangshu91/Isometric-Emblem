/*
 * PhaseWidget.cpp
 *
 *  Created on: May 12, 2013
 *      Author: Maiev
 */

#include "PhaseWidget.h"
#include "../System/GameEngine.h"

PhaseWidget::PhaseWidget() {
  phase = gamestate::PLAYER;
  visible = false;

  timer.resetClock();
}

PhaseWidget::~PhaseWidget() {
  // TODO Auto-generated destructor stub
}

void PhaseWidget::setup(GameEngine* eng) {



}
