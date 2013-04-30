/*
 * Terrain.cpp
 *
 *  Created on: Apr 28, 2013
 *      Author: Maiev
 */

#include "Terrain.h"

Terrain Terrain::NONE = Terrain();
Terrain Terrain::PLAIN = Terrain(terraintype::PLAIN, 1, 10, 0, 0);
Terrain Terrain::MOUNTAIN = Terrain(terraintype::MOUNTAIN, 2, 20, 1, 0);
Terrain Terrain::CLIFF = Terrain(terraintype::CLIFF, 1, 10, 2, 0);
Terrain Terrain::SEA = Terrain(terraintype::SEA, 0, 0, 0, 2);
Terrain Terrain::FOREST = Terrain(terraintype::FOREST, 1, 20, 0, 1);

Terrain::Terrain() {
  type = terraintype::NONE;
  def = 0;
  avd = 0;
  atk = 0;
  mv_dec = 0;
}

Terrain::Terrain(terraintype::Area t, int de, int av, int at, int mv) {
  type = t;
  def = de;
  avd = av;
  atk = at;
  mv_dec = mv;
}
