/*
 * HUDManager.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: Maiev
 */

#include "HUDManager.h"
#include "GameEngine.h"
#include "../Interface/GUIFrame.h"
#include "../Interface/GUIWidget.h"
using namespace std;

HUDManager::HUDManager() {

}

void HUDManager::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();
}

HUDManager::~HUDManager() {
  // TODO Auto-generated destructor stub
}

void HUDManager::addWidget(string key, GUIFrame* obj) {
  if (map.count(key) > 0) return;

  widgets.push_back(obj);
  map.insert(make_pair(key, obj));
}

GUIFrame* HUDManager::getWidget(string key) {
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


