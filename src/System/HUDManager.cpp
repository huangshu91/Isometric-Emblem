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
  //menu_hud_unit.setup(eng);
  menu_hud_gen.setup(eng);
  speech_hud.setup(eng);
  addWidget(STATUS_HUDL, &status_hudl);
  addWidget(STATUS_HUDR, &status_hudr);
  addWidget(TERRAIN_MENU, &terrain_hud);
  addWidget(PHASE_HUD, &phase_hud);
  addWidget(EXP_HUD, &exp_hud);
  //addWidget(MENU_HUD_UNIT, &menu_hud_unit);
  addWidget(MENU_HUD_GEN, &menu_hud_gen);
  addWidget(SPEECH_HUD, &speech_hud);

  sf::Vector2i loc(0,0);
  /*
  vector<string> unit;
  for (int i = 0; i < menu::NUM_UNIT_CHOICE; i++) {
    unit.push_back(menu::CHOICE_TEXT[i]);
  }
  loc.x = WINDOW_WIDTH - GUI_PADDING;
  loc.y = status_hudr.MENU_SIZE.y + 2*GUI_PADDING;
  menu_hud_unit.build(loc, unit, anchor::TOPRIGHT);
  */

  vector<string> gen;
  for (int i = 0; i < menu::NUM_GEN_CHOICE; i++) {
    gen.push_back(menu::GEN_TEXT[i]);
  }
  loc = sf::Vector2i(0,0);
  loc.x = WINDOW_WIDTH - GUI_PADDING;
  loc.y = status_hudr.MENU_SIZE.y + 2*GUI_PADDING;
  menu_hud_gen.build(loc, gen, anchor::TOPRIGHT);

  terrain_hud.enable();
}

HUDManager::~HUDManager() {
  // TODO Auto-generated destructor stub
}

void HUDManager::addWidget(string key, GUIWidget* obj) {
  if (map.count(key) > 0) return;

  widgets.push_back(obj);
  map.insert(make_pair(key, obj));
}

void HUDManager::removeWidget(string key) {
  GUIWidget* wp = getWidget(key);
  if (wp == 0) return;

  auto m_it = map.find(key);
  map.erase(m_it);
  for (auto it = widgets.begin(); it != widgets.end(); it++) {
    if (*it == wp) {
      widgets.erase(it);
      return;
    }
  }
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

