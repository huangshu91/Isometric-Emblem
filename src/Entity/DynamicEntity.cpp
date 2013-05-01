/*
 * DynamicEntity.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#include "DynamicEntity.h"
#include "../System/GameEngine.h"

DynamicEntity::DynamicEntity(GameEngine* eng, string n) : Entity(eng) {
  name = n;
  sprite.setTexture(*(eng->getRes()->getResource(SPRITE_KEY)));
}

DynamicEntity::~DynamicEntity() {
  // TODO Auto-generated destructor stub
}

void DynamicEntity::render() {
  win_ptr->draw(sprite);
}
