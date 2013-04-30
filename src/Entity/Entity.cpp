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
}

Entity::~Entity() {
  // TODO Auto-generated destructor stub
}

