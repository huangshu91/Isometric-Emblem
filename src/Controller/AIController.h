/*
 * AIController.h
 *
 *  Created on: May 12, 2013
 *      Author: Maiev
 */

#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_
#include "../Util/FormatClock.h"
#include "../Util/Constants.h"

class GameEngine;
class DynamicEntity;
class Map;
class Cell;

class AIController {
public:
  AIController(GameEngine* eng);
  virtual ~AIController();

  void setMap(Map* mp);
  void moveUnit();

  void update();

private:
  GameEngine* eng_ptr;

  DynamicEntity* selected;

  Map* map_ptr;
  FormatClock delaytimer;

  inputstate::Phase state;

  void moveTo(Cell* c);
};

#endif /* AICONTROLLER_H_ */
