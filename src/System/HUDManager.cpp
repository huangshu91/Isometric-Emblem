/*
 * HUDManager.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: Maiev
 */

#include "HUDManager.h"
#include "GameEngine.h"
#include "../Interface/GUIWidget.h"
using namespace std;

HUDManager::HUDManager() { }

void HUDManager::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();

  terrain_hud.setup(eng);
  phase_hud.setup(eng);
  addWidget(TERRAIN_MENU, &terrain_hud);
  addWidget(PHASE_HUD, &phase_hud);
}

HUDManager::~HUDManager() {
  // TODO Auto-generated destructor stub
}

void HUDManager::addWidget(string key, GUIWidget* obj) {
  if (map.count(key) > 0) return;

  widgets.push_back(obj);
  map.insert(make_pair(key, obj));
}

GUIWidget* HUDManager::getWidget(string key) {
  if (map.count(key) < 1) {
    return 0;
  }

  return map.find(key)->second;
}

void HUDManager::render() {
  win_ptr->setView(win_ptr->getDefaultView());
  for (int i = 0, j = widgets.size(); i < j; i++) {
    widgets[i]->render();
  }
}


