/*
 * Entity.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#include "Entity.h"
#include "../System/GameEngine.h"

Entity::Entity(GameEngine* eng) : eng_ptr(eng) {
  // TODO Auto-generated constructor stub
  name = "UNINITIALZIED";
  win_ptr = eng_ptr->getWindow();
  sprite_offset.x = 0;
  sprite_offset.y = 0;
}

Entity::~Entity() {
  // TODO Auto-generated destructor stub
}

void Entity::setOffset(sf::Vector2i off) {
  sprite_offset = off;
}

void Entity::setOffset(int x, int y) {
  sprite_offset.x = x;
  sprite_offset.y = y;
}
