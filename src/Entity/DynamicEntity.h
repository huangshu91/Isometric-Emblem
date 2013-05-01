/*
 * DynamicEntity.h
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_
#include <string>
#include "Entity.h"
#include "../Util/Constants.h"

class GameEngine;

class DynamicEntity : public Entity {
public:
  DynamicEntity(GameEngine* eng, string n = "");
  virtual ~DynamicEntity();

  void render();

private:
  unit::Class classtype;
};

#endif /* DYNAMICENTITY_H_ */
