/*
 * Terrain.cpp
 *
 *  Created on: Apr 28, 2013
 *      Author: Maiev
 */

#include "Terrain.h"

Terrain::Terrain() {
  type = "NONE";
  def = 0;
  avd = 0;
  atk = 0;
  mv_dec = 0;
}

Terrain::Terrain(std::string t, int de, int av, int at, int mv) {
  type = t;
  def = de;
  avd = av;
  atk = at;
  mv_dec = mv;
}
