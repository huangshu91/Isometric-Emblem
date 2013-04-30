/*
 * DynamicEntity.h
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_
#include "Entity.h"

class GameEngine;

class DynamicEntity : public Entity {
public:
  DynamicEntity(GameEngine* eng);
  virtual ~DynamicEntity();

  void render();

private:

};

#endif /* DYNAMICENTITY_H_ */
