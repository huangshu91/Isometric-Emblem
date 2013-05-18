/*
 * Item.cpp
 *
 *  Created on: May 17, 2013
 *      Author: Maiev
 */

#include "Item.h"
#include "../Entity/DynamicEntity.h"

Item::Item() {
  parent = 0;
  base_type = item::UNINIT;
  item_name = "NONE";
}

Item::~Item() {
  // TODO Auto-generated destructor stub
}

