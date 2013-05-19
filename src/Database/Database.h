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

struct Class {
  std::string class_name;
  std::string res_path;
  int         tier;
  StatPack    base_stat;
  StatPack    growth_mod;
  std::vector<std::string> promote_string;
  std::vector<Class*> promote;
};

class Database {
public:
  Database();
  virtual ~Database();

private:
  std::map<std::string, Class> class_db;

  void LoadClasses();
};

#endif /* DATABASE_H_ */
