/*
 * Database.h
 *
 *  Created on: May 19, 2013
 *      Author: Maiev
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <vector>
#include <string>
#include <map>
#include "../Util/UtilValues.h"
#include "../Util/Constants.h"
#include "../Levelmap/Terrain.h"

class GameEngine;
class Logger;

struct UnitClass {
  std::string class_name;
  std::string res_path;
  int         tier;
  StatPack    base_stat;
  StatPack    growth;
  std::vector<std::string> promote_string;
  std::vector<UnitClass*> promote;
};

struct TileDef {
  std::string tile_name;
  std::string base_key;
  std::vector<std::string> add_key;
  Terrain ter;
};

class Database {
public:
  Database();
  virtual ~Database();

  void setup(GameEngine* eng);

  TileDef getTile(std::string t);

private:
  GameEngine* eng_ptr;
  Logger* log_ptr;

  std::vector<std::string> class_names;
  std::map<std::string, UnitClass*> class_db;

  std::map<terraintype::Area, std::vector<std::string> > tile_adds;
  std::map<terraintype::Area, Terrain> terrain_db;

  std::vector<std::string> tile_names;
  std::map<std::string, TileDef> tile_db;

  void LoadClasses();
  void LinkClasses();
  void LoadTiles();
};

#endif /* DATABASE_H_ */
