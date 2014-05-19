/*
 * DatabaseTypes.h
 *
 *  Created on: May 18, 2014
 *      Author: Maiev
 */

#ifndef DATABASETYPES_H_
#define DATABASETYPES_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Util/UtilValues.h"
#include "../Util/Constants.h"
#include "../Levelmap/Terrain.h"

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
  std::vector<std::string> line;
  int         num_line;
};

struct Convo {
  int chars;
  int pages;
  std::vector<std::string> char_keys;
  std::vector<int> char_pos;
  std::vector<Page> dialogue;
};

struct ConsumeDef {
  std::string name;
  std::string desc;
  int value;
  int heal;
  int quant;
};

#endif /* DATABASETYPES_H_ */
