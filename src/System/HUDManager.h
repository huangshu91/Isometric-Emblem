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
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::vector<GUIWidget*> widgets;
  std::map<std::string, GUIWidget*> map;
};

#endif /* HUDMANAGER_H_ */
