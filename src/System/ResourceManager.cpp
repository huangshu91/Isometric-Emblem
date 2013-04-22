/*
 * ResourceManager.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#include "ResourceManager.h"
using namespace std;

ResourceManager::ResourceManager() {
}

// See header
ResourceManager::~ResourceManager() {
  map<string, sf::Texture*>::iterator it;

  for ( it=resources.begin() ; it != resources.end(); it++ ) {
    delete (*it).second;
  }
}

bool ResourceManager::addResource(string key, string path) {
  if (resources.count(key) > 0) {
    return true;
  }
  sf::Texture* temp = new sf::Texture();
  bool ret = temp->loadFromFile(path);

  if (ret == false) {
    delete temp;
    return false;
  }

  else {
    resources.insert(make_pair(key, temp));
  }

  return true;
}

sf::Texture* ResourceManager::getResource(string key) {
  if (resources.count(key) < 1) {
    return NULL;
  }

  return resources.find(key)->second;
}
