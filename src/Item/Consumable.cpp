/*
 * Consumable.cpp
 *
 *  Created on: May 25, 2013
 *      Author: Maiev
 */

#include "Consumable.h"

Consumable::Consumable(std::string iden) : Item(iden) {
  durability = 0;
  cdurability = 0;
}

Consumable::~Consumable() {
  // TODO Auto-generated destructor stub
}

