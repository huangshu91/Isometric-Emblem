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

class Database {
public:
  Database();
  virtual ~Database();

  void setup(GameEngine* eng);

private:
  GameEngine* eng_ptr;
  Logger* log_ptr;

  std::vector<std::string> class_names;
  std::map<std::string, UnitClass*> class_db;

  std::map<terraintype::Area, std::vector<sf::Sprite> > tile_adds;

  void LoadClasses();
  void LinkClasses();

  void LoadTiles();
};

#endif /* DATABASE_H_ */
