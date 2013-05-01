/*
 * DynamicEntity.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#include "DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Levelmap/Cell.h"

DynamicEntity::DynamicEntity(GameEngine* eng, string n) : Entity(eng) {
  name = n;
  sprite.setTexture(*(eng->getRes()->getResource(SPRITE_KEY)));
  sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height);
}

DynamicEntity::~DynamicEntity() {
  // TODO Auto-generated destructor stub
}

void DynamicEntity::setTile(Cell* t) {
  tile_ptr = t;
  sprite.setOrigin(sprite.getOrigin().x + sprite_offset.x, sprite.getOrigin().y + sprite_offset.y);
  sprite.setPosition(sf::Vector2f(t->getCenter()));
}

void DynamicEntity::render() {
  win_ptr->draw(sprite);
}
