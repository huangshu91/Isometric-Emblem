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
#include "../HUDWidget/TerrainMenu.h"
#include "../HUDWidget/PhaseWidget.h"
#include "../HUDWidget/StatusWidget.h"
#include "../HUDWidget/EXPWidget.h"
#include "../HUDWidget/MenuWidget.h"
#include "../HUDWIdget/SpeechWidget.h"
#include "../HUDWidget/TextWidget.h"

class GUIFrame;
class GameEngine;
class GUIWidget;

class HUDManager {
public:
  HUDManager();
  virtual ~HUDManager();

  void setup(GameEngine* eng);

  void addWidget(std::string key, GUIWidget* obj);
  void removeWidget(std::string key);
  GUIWidget* getWidget(std::string key);

  TerrainMenu* getTerrainHUD() { return &terrain_hud; };
  PhaseWidget* getPhaseHUD() { return &phase_hud; };
  StatusWidget* getStatusHUD(dir::Direction d);
  EXPWidget* getEXPHUD() { return &exp_hud; };
  MenuWidget* getMenuHUD() { return &menu_hud_unit; };
  MenuWidget* getGenHUD() { return &menu_hud_gen; };
  SpeechWidget* getSpeechHUD() { return &speech_hud; };

  //void update();
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::vector<GUIWidget*> widgets;
  std::map<std::string, GUIWidget*> map;

  TerrainMenu   terrain_hud;
  PhaseWidget   phase_hud;
  StatusWidget  status_hudr;
  StatusWidget  status_hudl;
  EXPWidget     exp_hud;
  SpeechWidget  speech_hud;

  MenuWidget    menu_hud_unit;
  MenuWidget    menu_hud_gen;
  MenuWidget    menu_hud_item;
};

#endif /* HUDMANAGER_H_ */
