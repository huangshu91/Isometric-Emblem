/*
 * Terrain.h
 *
 *  Created on: Apr 28, 2013
 *      Author: Maiev
 */

#ifndef TERRAIN_H_
#define TERRAIN_H_
#include "../Util/Constants.h"
#include <string>

class Terrain {
public:
  Terrain();
  Terrain(std::string t, int de, int av, int at, int mv);
  virtual ~Terrain() {};

  std::string   type;
  int           def;
  int           avd;
  int           atk;
  int           mv_dec;
};

#endif /* TERRAIN_H_ */
