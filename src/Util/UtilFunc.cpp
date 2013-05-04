/*
 * UtilFunc.cpp
 *
 *  Created on: May 4, 2013
 *      Author: Maiev
 */
#include "UtilFunc.h"
#include "../Levelmap/Cell.h"

int cellDist(Cell* c1, Cell* c2) {
  int d1 = abs(c1->getRow() - c2->getRow());
  int d2 = abs(c1->getCol() - c2->getCol());
  return d1+d2;
}


