/*
 * MapState.h
 *
 *  Created on: Apr 23, 2013
 *      Author: Maiev
 */

#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "../System/GameState.h"

class GameEngine;

class MapState : public GameState {
public:
  MapState(GameEngine* eng);
  virtual ~MapState();

private:
  GameEngine* eng_ptr;
};

#endif /* MAPSTATE_H_ */
