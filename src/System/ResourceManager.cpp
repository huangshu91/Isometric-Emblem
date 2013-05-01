/*
 * ResourceManager.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#include "ResourceManager.h"
#include <iostream>
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
    return 0;
  }
  return resources.find(key)->second;
}

bool ResourceManager::addFont(string key, string path) {
  if (fonts.count(key) > 0) {
    return true;
  }
  sf::Font* temp = new sf::Font();

  if (temp->loadFromFile(path) == false) {
    delete temp;
    return false;
  }

  else {
    fonts.insert(make_pair(key, temp));
  }

  cout << "test" << endl;
  return true;
}

sf::Font* ResourceManager::getFont(string key) {
  if (fonts.count(key) < 1) {
    return 0;
  }
  return fonts.find(key)->second;
}
