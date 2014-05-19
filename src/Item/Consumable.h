/*
 * Consumable.h
 *
 *  Created on: May 25, 2013
 *      Author: Maiev
 */

#ifndef CONSUMABLE_H_
#define CONSUMABLE_H_

#include "Item.h"

class Consumable: public Item {
public:
  Consumable(std::string iden = "UNDEF");
  virtual ~Consumable();

private:
  int durability;
  int cdurability;
};

#endif /* CONSUMABLE_H_ */
