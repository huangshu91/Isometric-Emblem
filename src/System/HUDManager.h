/*
 * HUDManager.h
 *
 *  Created on: Apr 25, 2013
 *      Author: Maiev
 */

#ifndef HUDMANAGER_H_
#define HUDMANAGER_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <map>
#include "../Interface/TerrainMenu.h"

class GUIFrame;
class GameEngine;
class GUIWidget;

class HUDManager {
public:
  HUDManager();
  virtual ~HUDManager();

  void setup(GameEngine* eng);

  void addWidget(std::string key, GUIWidget* obj);
  GUIWidget* getWidget(std::string key);

  TerrainMenu* getTerrainHUD() { return &terrain_hud; };

  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::vector<GUIWidget*> widgets;
  std::map<std::string, GUIWidget*> map;

  TerrainMenu   terrain_hud;
};

#endif /* HUDMANAGER_H_ */
