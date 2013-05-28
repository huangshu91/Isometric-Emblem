/*
 * Database.cpp
 *
 *  Created on: May 19, 2013
 *      Author: Maiev
 */

#include "Database.h"
#include "DatabaseTest.h"
#include "../Util/Logger.h"
#include "../System/GameEngine.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

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
  log_ptr->i("Loading tiles: ");

  LoadTiles();
  //testTiles(tile_names, tile_db);

  log_ptr->i("Tiles loaded.");
  log_ptr->i("Loading Chapter Information: ");

  LoadChapterInfo();
  //testChap(chapter_id, chap_db);

  log_ptr->i("Finished Loading ChapterInfo.");

  log_ptr->i("Finished loading db files.");

}

void Database::LoadChapterInfo() {
  ifstream file(DB_CHAP.c_str());
  if (file.is_open()) {
    int num_chap = 0;
    file >> num_chap;
    string str_tmp;

    for (int i = 0; i < num_chap; i++) {
      ChapDef newchap;

      file >> str_tmp;
      newchap.id = str_tmp;
      chapter_id.push_back(str_tmp);

      // twice because of \n character left in stream
      getline(file, str_tmp);
      getline(file, str_tmp);
      newchap.chap_name = str_tmp;

      file >> str_tmp;
      newchap.map_def = str_tmp;

      chap_db.insert(make_pair(newchap.id, newchap));
    }
    file.close();
  } else {
    log_ptr->e("Could not load chapters!");
  }
}

void Database::LoadClasses() {
  ifstream file(DB_CLASS.c_str());
  if (file.is_open()) {
    int num_class = 0;
    file >> num_class;
    int int_temp;
    string str_temp;

    for (int i = 0; i < num_class; i++) {
      UnitClass newclass;
      file >> str_temp;  // class name
      file >> int_temp;  // class tier

      newclass.class_name = str_temp;
      newclass.tier = int_temp;
      class_names.push_back(str_temp);

      file >> str_temp;  // res path
      eng_ptr->getRes()->addResource(newclass.class_name, str_temp);

      file >> int_temp;
      newclass.offset.x = int_temp;
      file >> int_temp;
      newclass.offset.y = int_temp;

      file >> int_temp;
      newclass.max_stat.max_hp = int_temp;
      file >> int_temp;
      newclass.max_stat.str = int_temp;
      file >> int_temp;
      newclass.max_stat.dex = int_temp;
      file >> int_temp;
      newclass.max_stat.agi = int_temp;
      file >> int_temp;
      newclass.max_stat.def = int_temp;
      file >> int_temp;
      newclass.max_stat.res = int_temp;
      file >> int_temp;
      newclass.max_stat.lck = int_temp;

      file >> int_temp;
      for (int i = 0, j = int_temp; i < j; i++) {
        file >> str_temp;  // promote class name;
        newclass.promote_string.push_back(str_temp);
      }

      file >> int_temp;
      newclass.growth.max_hp = int_temp;
      file >> int_temp;
      newclass.growth.str = int_temp;
      file >> int_temp;
      newclass.growth.dex = int_temp;
      file >> int_temp;
      newclass.growth.agi = int_temp;
      file >> int_temp;
      newclass.growth.def = int_temp;
      file >> int_temp;
      newclass.growth.res = int_temp;
      file >> int_temp;
      newclass.growth.lck = int_temp;

      class_db.insert(
          make_pair(newclass.class_name, newclass));
    }
    file.close();
  } else {
    log_ptr->e("Could not load classes!");
  }
}

void Database::LinkClasses() {
  for (int i = 0, j = class_names.size(); i < j; i++) {
    string class_n = class_names[i];
    UnitClass cur_class = class_db.find(class_n)->second;

    for (int k = 0, l = cur_class.promote_string.size(); k < l; k++) {
      UnitClass promote = class_db.find(cur_class.promote_string[k])->second;
      cur_class.promote.push_back(promote);
    }
  }
}

void Database::LoadTiles() {
  ifstream file(DB_TILE.c_str());
  if (file.is_open()) {
    int num_res = 0;
    file >> num_res;
    int int_tmp;
    string str_tmp;

    for (int i = 0; i < num_res; i++) {
      string res_path;
      file >> str_tmp;
      file >> res_path;
      eng_ptr->getRes()->addResource(str_tmp, res_path);
    }

    int num_tile = 0;
    file >> num_tile;

    for (int i = 0; i < num_tile; i++) {
      file >> str_tmp;
      TileDef newTile;

      tile_names.push_back(str_tmp);
      newTile.tile_name = str_tmp;

      file >> str_tmp;

      newTile.base_key = str_tmp;

      file >> int_tmp;

      // tile adds
      for (int j = 0; j < int_tmp; j++) {
        file >> str_tmp;
        newTile.add_key.push_back(str_tmp);
      }

      newTile.ter.type = newTile.tile_name;
      file >> int_tmp;
      newTile.ter.def = int_tmp;
      file >> int_tmp;
      newTile.ter.avd = int_tmp;
      file >> int_tmp;
      newTile.ter.atk = int_tmp;
      file >> int_tmp;
      newTile.ter.mv_dec = int_tmp;

      tile_db.insert(make_pair(newTile.tile_name, newTile));
    }
    file.close();
  } else {
    log_ptr->e("Could not load tiles!");
  }
}

UnitClass Database::getClass(string c) {
  if (class_db.count(c) == 0) {
    UnitClass tmp;
    tmp.class_name = "NONE";
    return tmp;
  }

  return class_db.find(c)->second;
}

ChapDef Database::getChap(string c) {
  if (chap_db.count(c) == 0) {
    ChapDef tmp;
    tmp.chap_name = "NONE";
    return tmp;
  }

  return chap_db.find(c)->second;
}

TileDef Database::getTile(string t) {
  if (tile_db.count(t) == 0) {
    TileDef tmp;
    tmp.tile_name = "NONE";
    return tmp;
  }

  return tile_db.find(t)->second;
}
