/*
 * HUDManager.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: Maiev
 */

#include "HUDManager.h"
#include "GameEngine.h"
#include "../HUDWidget/GUIWidget.h"
#include "../Util/Constants.h"
using namespace std;

HUDManager::HUDManager() {
  eng_ptr = 0;
  win_ptr = 0;
}

void HUDManager::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();

  terrain_hud.setup(eng);
  phase_hud.setup(eng);
  status_hudr.setup(eng, dir::RIGHT);
  status_hudl.setup(eng, dir::LEFT);
  exp_hud.setup(eng);
  menu_hud.setup(eng);
  addWidget(STATUS_HUDL, &status_hudl);
  addWidget(STATUS_HUDR, &status_hudr);
  addWidget(TERRAIN_MENU, &terrain_hud);
  addWidget(PHASE_HUD, &phase_hud);
  addWidget(EXP_HUD, &exp_hud);
  addWidget(MENU_HUD, &menu_hud);

  vector<string> test;
  test.push_back("ATTACK");
  test.push_back("ITEM");
  test.push_back("WAIT");
  test.push_back("TESTING");
  menu_hud.build(sf::Vector2i(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), test);

  menu_hud.select(1);
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

StatusWidget* HUDManager::getStatusHUD(dir::Direction d) {
  if (d == dir::LEFT) {
    return &status_hudl;
  }

  return &status_hudr;
}

