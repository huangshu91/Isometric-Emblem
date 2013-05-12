/*
 * TerrainMenu.h
 *
 *  Created on: Apr 27, 2013
 *      Author: Maiev
 */

#ifndef TERRAINMENU_H_
#define TERRAINMENU_H_
#include "../Levelmap/Terrain.h"

#include "GUIFrame.h"
#include "GUIWidget.h"

class TerrainMenu: public GUIWidget {
public:
  TerrainMenu();
  virtual ~TerrainMenu();

  void setup(GameEngine* eng);

  void render();

  void setTile(Terrain t);

private:
  GUIFrame frame;

  static sf::Vector2i MENU_SIZE;

  sf::Text label;
  sf::Text def_text;
  sf::Text avd_text;
  sf::Text atk_text;

  sf::Text def_val;
  sf::Text avd_val;
  sf::Text atk_val;

};

#endif /* TERRAINMENU_H_ */
