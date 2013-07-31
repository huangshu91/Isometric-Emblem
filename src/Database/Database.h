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
  sf::Vector2i offset;
  int         tier;
  StatPack    max_stat;
  StatPack    growth;
  std::vector<std::string> promote_string;
  std::vector<UnitClass> promote;
  int         mv;
};

struct TileDef {
  std::string tile_name;
  std::string base_key;
  std::vector<std::string> add_key;
  Terrain ter;
};

struct ChapDef {
  std::string id;
  std::string chap_name;
  std::string map_def;
};

struct Page {
  std::string char_key;
  std::string line;
};

struct Convo {
  int chars;
  int pages;
  std::vector<std::string> char_keys;
  std::vector<int> char_pos;
  std::vector<Page> dialogue;
};

class Database {
public:
  Database();
  virtual ~Database();

  void setup(GameEngine* eng);

  //UnitClass
  TileDef getTile(std::string t);
  ChapDef getChap(std::string c);
  UnitClass getClass(std::string c);
  Convo getConvo(std::string c);

private:
  GameEngine* eng_ptr;
  Logger* log_ptr;

  std::vector<std::string> class_names;
  std::map<std::string, UnitClass> class_db;

  std::vector<std::string> tile_names;
  std::map<std::string, TileDef> tile_db;

  std::vector<std::string> chapter_id;
  std::map<std::string, ChapDef> chap_db;

  std::vector<std::string> convo_names;
  std::map<std::string, Convo> convo_db;

  void LoadClasses();
  void LinkClasses();
  void LoadTiles();
  void LoadChapterInfo();
  void LoadConvo();

  Convo LoadAct(std::string convo_path);
};

#endif /* DATABASE_H_ */
