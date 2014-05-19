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
  log_ptr->i("Loading Conversations: ");

  LoadConvo();
  //testConvo(convo_names, convo_db);

  log_ptr->i("Finished loading Conversations.");
  log_ptr->i("Loading Items: ");

  LoadItems();

  log_ptr->i("Finished loading Items.");
  log_ptr->i("Finished loading db files.");

}

void Database::LoadItems() {
  ifstream file(DB_ITEMS.c_str());
  if (file.is_open()) {
    string conspath;
    string eqpath;

    file >> conspath;
    file >> eqpath;

    LoadConsumable(conspath);
    //LoadEquipment(eqpath);

    file.close();
  } else {
    log_ptr->e("Could not load Items!");
  }
}

void Database::LoadConsumable(string con_path) {
  ifstream file(con_path.c_str());
  if (file.is_open()) {
    int num_con = 0;
    file >> num_con;

    string field;
    int val;

    for (int i = 0; i < num_con; i++) {
      char start;
      file >> start;
      getline(file, field);
      consume_names.push_back(start+field);

      ConsumeDef c;
      c.name = field;

      file >> val;
      c.value = val;
      file >> val;
      c.heal = val;
      file >> val;
      c.quant = val;

      char end;
      file >> end;
      getline(file, field);
      c.desc = end+field;
    }

    file.close();
  } else {
    log_ptr->e("\tCould not load Consumables!");
  }

  log_ptr->i("\tFinished loading Consumables.");
}

void Database::LoadEquipment(string eq_path) {

  log_ptr->i("\tFinished loading Equipment.");
}

void Database::LoadConvo() {
  ifstream file(DB_CONVO.c_str());
  if (file.is_open()) {
    int num_convo = 0;
    file >> num_convo;

    string convo_key;
    string convo_path;

    for (int i = 0; i < num_convo; i++) {
      file >> convo_key;
      file >> convo_path;

      convo_names.push_back(convo_key);
      Convo c = LoadAct(convo_path);
      convo_db.insert(make_pair(convo_key, c));
    }
    file.close();
  } else {
    log_ptr->e("Could not load conversations!");
  }
}

Convo Database::LoadAct(string convo_path) {
  Convo ret;
  ifstream file(convo_path.c_str());
  if (file.is_open()) {
    int char_num = 0;
    string str_temp;
    string str_temp2;
    int int_temp;

    file >> char_num;
    ret.chars = char_num;
    for (int i = 0; i < char_num; i++) {
      file >> str_temp;
      file >> int_temp;
      file >> str_temp2;

      eng_ptr->getRes()->addResource(str_temp, str_temp2);
      ret.char_keys.push_back(str_temp);
      ret.char_pos.push_back(int_temp);
    }

    int pages = 0;
    file >> pages;
    ret.pages = pages;
    for (int i = 0; i < pages; i++) {
      file >> str_temp;
      file >> int_temp;
      // \n character left in stream
      getline(file, str_temp2);

      Page p_temp;
      p_temp.num_line = int_temp;
      p_temp.char_key = str_temp;

      for (int i = 0; i < int_temp; i++) {
        getline(file, str_temp2);
        p_temp.line.push_back(str_temp2);
      }
      ret.dialogue.push_back(p_temp);
    }
    file.close();
  } else {
    log_ptr->e("Could not load Dialogue - "+convo_path+"!");
  }
  return ret;
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
      newclass.mv = int_temp;

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

Convo Database::getConvo(string c) {
  if (convo_db.count(c) == 0) {
    Convo tmp;
    tmp.chars = 0;
    tmp.pages = 0;
    return tmp;
  }

  return convo_db.find(c)->second;
}

ConsumeDef Database::getConsume(string c) {
  if (consume_db.count(c) == 0) {
    ConsumeDef tmp;
    tmp.name = "NONE";
    tmp.desc = "NONE";
    tmp.value = 0;
    tmp.heal = 0;
    tmp.quant = 0;
    return tmp;
  }

  return consume_db.find(c)->second;
}
