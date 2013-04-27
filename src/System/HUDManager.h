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

class HUDManager {
public:
  HUDManager();
  virtual ~HUDManager();

  void setup(GameEngine* eng);

  void addWidget(std::string key, GUIFrame* obj);
  GUIFrame* getWidget(std::string key);
  void render();

private:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::vector<GUIFrame*> widgets;
  std::map<std::string, GUIFrame*> map;
};

#endif /* HUDMANAGER_H_ */
