/*
 * DatabaseTest.cpp
 *
 *  Created on: May 26, 2013
 *      Author: Maiev
 */

#include <string>
#include <map>
#include <iostream>
#include "DatabaseTest.h"
using namespace std;

void testConvo(vector<string> convs, map<string, Convo> db) {
  cout << "test start" << endl;
  for (auto i : convs) {
    Convo c = db.find(i)->second;
    cout << c.chars << endl;
    for (auto j : c.char_keys) {
      cout << j << endl;
    }
    cout << c.pages << endl;
    for (auto k : c.dialogue) {
      cout << k.char_key << endl;
      for (auto l : k.line) {
        cout << l << endl;
      }
      cout << endl;
    }
  }
  cout << "------------" << endl;
}

void testChap(vector<string> chap, map<string, ChapDef> db) {
  cout << "test start" << endl;
  for (auto i : chap) {
    ChapDef cd = db.find(i)->second;
    cout << cd.id << endl;
    cout << cd.chap_name << endl;
    cout << cd.map_def << endl;
  }
  cout << "-------------" << endl;
}

void testClasses(vector<string> classes, map<string, UnitClass> db) {
  cout << "test start" << endl;
  for (int i = 0, j = classes.size(); i < j; i++) {
    cout << classes[i] << endl;
    UnitClass cur_class = db.find(classes[i])->second;
    cout << classes[i] << " - " << cur_class.tier << endl;

    for (int k = 0, l = cur_class.promote.size(); k < l; k++) {
      cout << cur_class.promote[k].class_name << endl;
    }

    cout << "-------------" << endl;
  }
}

void testTiles(vector<string> tiles, map<string, TileDef> db) {
  cout << "test start" << endl;
  for (auto i : tiles) {
    cout << i << endl;
    TileDef td = db.find(i)->second;

    cout << td.tile_name << endl;
    cout << td.base_key << endl;
    cout << td.add_key.size() << endl;
  }

  cout << "--------------" << endl;
}
