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
#include "DatabaseTypes.h"
#include "../Util/UtilValues.h"
#include "../Util/Constants.h"
#include "../Levelmap/Terrain.h"

class GameEngine;
class Logger;

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
  ConsumeDef getConsume(std::string c);

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

  std::vector<std::string> consume_names;
  std::map<std::string, ConsumeDef> consume_db;

  std::vector<std::string> eq_names;

  void LoadClasses();
  void LinkClasses();
  void LoadTiles();
  void LoadChapterInfo();
  void LoadConvo();
  void LoadItems();
    void LoadConsumable(std::string con_path);
    void LoadEquipment(std::string eq_path);

  Convo LoadAct(std::string convo_path);
};

#endif /* DATABASE_H_ */
