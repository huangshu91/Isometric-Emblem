/*
 * Map.h
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#ifndef MAP_H_
#define MAP_H_
#include "../Util/Constants.h"
#include "../Util/UtilValues.h"
#include "DayCycle.h"
#include "Cell.h"
#include <string>
#include <queue>
#include <vector>

class DynamicEntity;
class GameEngine;

class Map {
public:
  Map(GameEngine* eng);
  ~Map();

  void loadMap(std::string id);
  void setupEntity();
  void createEntity(sf::Vector2i loc, std::string key, StatPack stat);

  Map* getMap() { return this; };
  Cell* getCell(int x, int y);

  int getRow() { return row; };
  int getCol() { return col; };

  std::queue<Cell*> getPath(DynamicEntity* e, range::RangeType type);
  void toggleRangeOn(DynamicEntity* e, range::RangeType type);
  void toggleRangeOff();
  void markCell(Cell* c, std::string key);

  bool inDistance(DynamicEntity* e, unit::Control utype);
  void newTurn();
  void checkLoss();
  void removeUnit(DynamicEntity* unit, unit::Control utype);

  void render();
  void renderAdd();
  void renderUnits();
  void renderRange();
  void sortForeground();

  std::vector<DynamicEntity*> getPlayerUnits() { return player_units; };
  std::vector<DynamicEntity*> getEnemyUnits() { return enemy_units; };

private:
  GameEngine* eng_ptr;

  std::vector<std::vector<Cell> > board;

  std::vector<sf::Sprite> rangetile;
  bool range_on;

  std::string map_name;
  std::string map_id;
  // dimensions of the map, row = x, col = y
  int row;
  int col;
  DayCycle  cycle;

  std::vector<DynamicEntity*> player_units;
  std::vector<DynamicEntity*> enemy_units;
  std::vector<DynamicEntity*> units;

  std::vector<DynamicEntity*> dead;
};

#endif /* MAP_H_ */
