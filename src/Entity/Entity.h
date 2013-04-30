/*
 * Entity.h
 *
 *  Created on: Apr 30, 2013
 *      Author: Maiev
 */

#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>

class GameEngine;

class Entity {
public:
  Entity(GameEngine* eng);
  virtual ~Entity();

  virtual void render() = 0;

private:
  GameEngine* eng_ptr;
  std::string name;
};

#endif /* ENTITY_H_ */
