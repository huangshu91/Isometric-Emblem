/*
 * GUIWidget.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Maiev
 */

#include "GUIWidget.h"
#include "../System/GameEngine.h"

GUIWidget::GUIWidget() {
  eng_ptr = 0;
  win_ptr = 0;
  visible = false;
}

void GUIWidget::setup(GameEngine* eng)  {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();
}

GUIWidget::~GUIWidget() {
  // TODO Auto-generated destructor stub
}

