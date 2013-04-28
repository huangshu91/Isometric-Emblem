/*
 * Terrain.cpp
 *
 *  Created on: Apr 28, 2013
 *      Author: Maiev
 */

#include "Terrain.h"

Terrain Terrain::NONE = Terrain();

Terrain::Terrain() {
  type = terraintype::NONE;
  def = 0;
  avd = 0;
  atk = 0;
}

Terrain::Terrain(terraintype::Area t, int de, int av, int at) {
  type = t;
  def = de;
  avd = av;
  atk = at;
}
