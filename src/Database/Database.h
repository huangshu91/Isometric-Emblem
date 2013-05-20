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

class GameEngine;
class Logger;

struct Class {
  std::string class_name;
  std::string res_path;
  int         tier;
  StatPack    base_stat;
  StatPack    growth;
  std::vector<std::string> promote_string;
  std::vector<Class*> promote;
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
  std::map<std::string, Class*> class_db;

  void LoadClasses();
  void LinkClasses();
};

#endif /* DATABASE_H_ */
