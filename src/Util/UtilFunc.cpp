/*
 * UtilFunc.cpp
 *
 *  Created on: May 4, 2013
 *      Author: Maiev
 */
#include "UtilFunc.h"
#include "../Levelmap/Cell.h"
#include "../System/Camera.h"

int cellDist(Cell* c1, Cell* c2) {
  int d1 = abs(c1->getRow() - c2->getRow());
  int d2 = abs(c1->getCol() - c2->getCol());
  return d1+d2;
}

sf::Vector2i localToGlobal(sf::Vector2i loc, Camera* cam) {
  sf::Vector2i topleft = sf::Vector2i(cam->GetLocation());
  sf::Vector2i ret = topleft+loc;
  return ret;
}

sf::Vector2i globalToLocal(sf::Vector2i glo, Camera* cam) {
  sf::Vector2i topleft = sf::Vector2i(cam->GetLocation());
  sf::Vector2i ret = glo-topleft;
  return ret;
}
