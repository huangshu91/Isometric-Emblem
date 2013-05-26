/*
 * Database.cpp
 *
 *  Created on: May 19, 2013
 *      Author: Maiev
 */

#include "Database.h"
#include "../Util/Logger.h"
#include "../System/GameEngine.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void testClasses(vector<string> classes, map<string, UnitClass*> db) {
  cout << "test start" << endl;
  for (int i = 0, j = classes.size(); i < j; i++) {
    cout << classes[i] << endl;
    UnitClass* cur_class = db.find(classes[i])->second;

    cout << cur_class->tier << " - " << cur_class->res_path << endl;

    for (int k = 0, l = cur_class->promote.size(); k < l; k++) {
      cout << cur_class->promote[k]->class_name << endl;
    }

    cout << "-------------" << endl;
  }
}

Database::Database() {
  eng_ptr = 0;
  log_ptr = 0;
}

Database::~Database() {
  // TODO Auto-generated destructor stub
}

void Database::setup(GameEngine* eng) {
  eng_ptr = eng;
  log_ptr = eng->getLog();

  log_ptr->i("Loading db files: ");
  log_ptr->i("Loading classes: ");

  LoadClasses();

  log_ptr->i("Classes loaded.");
  log_ptr->i("Linking Classes: ");

  LinkClasses();
  //testClasses(class_names, class_db);

  log_ptr->i("Finished Linking Classes.");

  log_ptr->i("Finished loading db files.");

}

// file io
void Database::LoadClasses() {
  ifstream file(DB_CLASS.c_str());
  if (file.is_open()) {
    int num_class = 0;
    file >> num_class;
    int int_temp;
    string str_temp;

    for (int i = 0; i < num_class; i++) {
      UnitClass* newclass = new UnitClass();
      file >> str_temp;  // class name
      file >> int_temp;  // class tier

      newclass->class_name = str_temp;
      newclass->tier = int_temp;
      class_names.push_back(str_temp);

      file >> str_temp;  // res path

      newclass->res_path = str_temp;

      file >> int_temp;
      newclass->base_stat.max_hp = int_temp;
      file >> int_temp;
      newclass->base_stat.str = int_temp;
      file >> int_temp;
      newclass->base_stat.dex = int_temp;
      file >> int_temp;
      newclass->base_stat.agi = int_temp;
      file >> int_temp;
      newclass->base_stat.def = int_temp;
      file >> int_temp;
      newclass->base_stat.res = int_temp;
      file >> int_temp;
      newclass->base_stat.lck = int_temp;

      file >> int_temp;  // promote char path
      for (int i = 0, j = int_temp; i < j; i++) {
        file >> str_temp;  // promote class name;
        newclass->promote_string.push_back(str_temp);
      }

      file >> int_temp;
      newclass->growth.max_hp = int_temp;
      file >> int_temp;
      newclass->growth.str = int_temp;
      file >> int_temp;
      newclass->growth.dex = int_temp;
      file >> int_temp;
      newclass->growth.agi = int_temp;
      file >> int_temp;
      newclass->growth.def = int_temp;
      file >> int_temp;
      newclass->growth.res = int_temp;
      file >> int_temp;
      newclass->growth.lck = int_temp;

      class_db.insert(
          make_pair(newclass->class_name, newclass));
    }

  } else {
    log_ptr->e("Could not load classes!");
  }
}

void Database::LinkClasses() {
  for (int i = 0, j = class_names.size(); i < j; i++) {
    string class_n = class_names[i];
    UnitClass* cur_class = class_db.find(class_n)->second;

    for (int k = 0, l = cur_class->promote_string.size(); k < l; k++) {
      UnitClass* promote = class_db.find(cur_class->promote_string[k])->second;
      cur_class->promote.push_back(promote);
    }
  }
}


void Database::LoadTiles() {

}
