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
class TerrainMenu;
class StatusWidget;

class AIController {
public:
  AIController(GameEngine* eng);
  virtual ~AIController();

  void setMap(Map* mp);
  void moveUnit();
  void endUnit();

  void update();

private:
  GameEngine* eng_ptr;

  DynamicEntity* selected;

  Map* map_ptr;
  FormatClock delaytimer;

  inputstate::Phase state;

  void moveTo(Cell* c);

  TerrainMenu* terrainhud_ptr;
  StatusWidget* statushudr_ptr;
  StatusWidget* statushudl_ptr;
};

#endif /* AICONTROLLER_H_ */
