/*
 * TerrainMenu.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Maiev
 */

#include "TerrainMenu.h"
#include "../Util/Constants.h"
#include <iostream>
using namespace std;

sf::Vector2i TerrainMenu::MENU_SIZE = sf::Vector2i(120,120);

TerrainMenu::TerrainMenu() {
}

TerrainMenu::~TerrainMenu() {
  // TODO Auto-generated destructor stub
}

void TerrainMenu::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  frame.setup(eng_ptr);
  sf::Vector2i loc(0, WINDOW_HEIGHT);
  loc.x += MENU_SIZE.x;
  loc.y -= MENU_SIZE.y;
  frame.build(loc, MENU_SIZE);

  label.setString("Terrain");
  label.setCharacterSize(LABEL_SIZE);
  label.setOrigin(label.getLocalBounds().width/2, label.getLocalBounds().height/2);
  sf::Vector2f pos(frame.getLoc().x, frame.getLoc().y - (MENU_SIZE.y/2) + 2*FONT_SIZE);
  label.setPosition(pos);

  def_text.setString("DEF");
  def_text.setCharacterSize(FONT_SIZE);
  avd_text.setString("AVD");
  avd_text.setCharacterSize(FONT_SIZE);
  atk_text.setString("ATK");
  atk_text.setCharacterSize(FONT_SIZE);

  pos = sf::Vector2f(frame.getLoc().x -
      frame.getSize().x/2 + FONT_SIZE, label.getPosition().y + LABEL_SIZE);


  def_text.setPosition(pos);
  pos.y += FONT_SIZE +4;

  avd_text.setPosition(pos);
  pos.y += FONT_SIZE +4;

  atk_text.setPosition(pos);

  def_val.setString("0");
  def_val.setCharacterSize(FONT_SIZE);
  def_val.setOrigin(def_val.getLocalBounds().width, 0);
  avd_val.setString("0");
  avd_val.setCharacterSize(FONT_SIZE);
  avd_val.setOrigin(avd_val.getLocalBounds().width, 0);
  atk_val.setString("0");
  atk_val.setCharacterSize(FONT_SIZE);
  atk_val.setOrigin(atk_val.getLocalBounds().width, 0);

  def_val.setPosition(frame.getLoc().x +
      frame.getSize().x/2 - FONT_SIZE, def_text.getPosition().y );
  avd_val.setPosition(frame.getLoc().x +
      frame.getSize().x/2 - FONT_SIZE, avd_text.getPosition().y );
  atk_val.setPosition(frame.getLoc().x +
      frame.getSize().x/2 - FONT_SIZE, atk_text.getPosition().y );
}

void TerrainMenu::render() {
  frame.render();
  win_ptr->draw(label);
  win_ptr->draw(def_text);
  win_ptr->draw(avd_text);
  win_ptr->draw(atk_text);

  win_ptr->draw(def_val);
  win_ptr->draw(avd_val);
  win_ptr->draw(atk_val);
}

void TerrainMenu::setTile() {


}
