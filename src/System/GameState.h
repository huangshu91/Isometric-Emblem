/*
 * GameState.h
 *
 *  Created on: Jun 24, 2012
 *      Author: Maiev
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include "../Util/Constants.h"

class GameState {
public:
  virtual void HandleEvent(sf::Event ev) = 0;
  virtual void RenderScreen() = 0;
  virtual void Update() = 0;
  virtual ~GameState() {};

  state::GameStateTypes stateId;
};

#endif /* GAMESTATE_H_ */
