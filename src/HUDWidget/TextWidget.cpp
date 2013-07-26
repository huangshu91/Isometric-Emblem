/*
 * TextWidget.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#include "TextWidget.h"
#include "../System/GameEngine.h"
using namespace std;

TextWidget::TextWidget() {

}

TextWidget::~TextWidget() {
  // TODO Auto-generated destructor stub
}

void TextWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);

}

void TextWidget::render() {
  if (!visible) return;

}
