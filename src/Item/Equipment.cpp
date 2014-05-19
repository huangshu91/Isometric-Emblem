/*
 * Equipment.cpp
 *
 *  Created on: May 25, 2013
 *      Author: Maiev
 */

#include "Equipment.h"

Equipment::Equipment(std::string iden) : Item(iden) {
  durability = 0;
  cdurability = 0;
}

Equipment::~Equipment() {
  // TODO Auto-generated destructor stub
}

