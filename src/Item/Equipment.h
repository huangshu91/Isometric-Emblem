/*
 * Equipment.h
 *
 *  Created on: May 25, 2013
 *      Author: Maiev
 */

#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include "Item.h"

class Equipment: public Item {
public:
  Equipment(std::string iden = "UNDFEF");
  virtual ~Equipment();

private:
  int durability;
};

#endif /* EQUIPMENT_H_ */
