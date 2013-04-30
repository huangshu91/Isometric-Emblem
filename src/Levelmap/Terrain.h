/*
 * Terrain.h
 *
 *  Created on: Apr 28, 2013
 *      Author: Maiev
 */

#ifndef TERRAIN_H_
#define TERRAIN_H_
#include "../Util/Constants.h"

class Terrain {
public:
  Terrain();
  Terrain(terraintype::Area t, int de, int av, int at, int mv);
  virtual ~Terrain() {};

  terraintype::Area   type;
  int           def;
  int           avd;
  int           atk;
  int           mv_dec;

  static Terrain NONE;
  static Terrain PLAIN;
  static Terrain MOUNTAIN;
  static Terrain CLIFF;
  static Terrain SEA;
  static Terrain FOREST;
};

#endif /* TERRAIN_H_ */
