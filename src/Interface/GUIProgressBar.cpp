/*
 * GUIProgressBar.cpp
 *
 *  Created on: May 24, 2013
 *      Author: Maiev
 */

#include "GUIProgressBar.h"
#include "../System/GameEngine.h"

GUIProgressBar::GUIProgressBar() {

}

GUIProgressBar::~GUIProgressBar() {
  // TODO Auto-generated destructor stub
}

void GUIProgressBar::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
}

void GUIProgressBar::build(sf::Vector2i loc, sf::Vector2i s, sf::Color f) {
  pos = loc;
  size = s;

  full_bar.setSize(sf::Vector2f(size.x, size.y));
  full_bar.setOrigin(size.x/2, size.y/2);
  full_bar.setPosition(sf::Vector2f(loc));
  full_bar.setFillColor(sf::Color(100, 100, 100));
  full_bar.setOutlineThickness(3);
  full_bar.setOutlineColor(sf::Color(65, 60, 0));

  fill_bar.setSize(sf::Vector2f(size.x/4, size.y));
  fill_bar.setOrigin(0, fill_bar.getLocalBounds().height/2);
  fill_bar.setPosition(sf::Vector2f(loc.x-(size.x/2), loc.y));
  fill_bar.setFillColor(f);
}

void GUIProgressBar::setProg(int val) {

}

void GUIProgressBar::growProg(int from, int to) {

}

void GUIProgressBar::render() {
  win_ptr->draw(full_bar);
  win_ptr->draw(fill_bar);
}
