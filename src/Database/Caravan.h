/*
 * Caravan.h
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#ifndef CARAVAN_H_
#define CARAVAN_H_
#include <vector>

class DynamicEntity;
class GameEngine;

class Caravan {
public:
  Caravan();
  virtual ~Caravan();
  void setup(GameEngine* eng);

  void addPlayer(DynamicEntity* e);
  void removePlayer(DynamicEntity* e);

private:
  GameEngine* eng_ptr;

  std::vector<DynamicEntity*> play;
  std::vector<DynamicEntity*> dead;
};

#endif /* CARAVAN_H_ */
