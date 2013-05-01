/*
 * Entity.h
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class GameEngine;

class Entity {
public:
  Entity(GameEngine* eng);
  virtual ~Entity();

  virtual void render() = 0;

protected:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::string name;
  sf::Sprite  sprite;
};

#endif /* ENTITY_H_ */
