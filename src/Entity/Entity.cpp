/*
 * Entity.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#include "Entity.h"
#include "../System/GameEngine.h"

Entity::Entity(GameEngine* eng, std::string n) : eng_ptr(eng) {
  // TODO Auto-generated constructor stub
  name = "UNINITIALZIED";
  win_ptr = eng_ptr->getWindow();
  sprite_offset.x = 0;
  sprite_offset.y = 0;

  sprite.setTexture(*(eng->getRes()->getResource(n)));
  sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height);
}

Entity::~Entity() {
  // TODO Auto-generated destructor stub
}

void Entity::setOffset(sf::Vector2i off) {
  sprite_offset = off;
  sprite.setOrigin(sprite.getOrigin().x + sprite_offset.x, sprite.getOrigin().y + sprite_offset.y);
}

void Entity::setOffset(int x, int y) {
  sprite_offset.x = x;
  sprite_offset.y = y;
  sprite.setOrigin(sprite.getOrigin().x + sprite_offset.x, sprite.getOrigin().y + sprite_offset.y);
}
