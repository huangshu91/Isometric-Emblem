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
  Entity(GameEngine* eng, std::string n);
  virtual ~Entity();

  std::string name;

  void setOffset(sf::Vector2i off);
  void setOffset(int x, int y);
  virtual void render() = 0;

protected:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  sf::Sprite  sprite;

  sf::Vector2i sprite_offset;
};

#endif /* ENTITY_H_ */
