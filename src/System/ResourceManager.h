/*
 * ResourceManager.h
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
using namespace std;

class ResourceManager {
public:
  ResourceManager();

  // This should never be called because the resources should persist
  // until the game is shut down.
  ~ResourceManager();

  // True if image is stored (even if already in, false if not
  bool addResource(string key, string path);
  sf::Texture* getResource(string key);

  bool addFont(string key, string path);
  sf::Font* getFont(string key);

private:
  std::map<string, sf::Texture*> resources;

  std::map<string, sf::Font*> fonts;
};

#endif /* RESOURCEMANAGER_H_ */
