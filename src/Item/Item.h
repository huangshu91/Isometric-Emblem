/*
 * Item.h
 *
 *  Created on: May 17, 2013
 *      Author: Maiev
 */

#ifndef ITEM_H_
#define ITEM_H_
#include "../Util/Constants.h"
#include "../Util/UtilValues.h"
#include <string>

class DynamicEntity;

class Item {
public:
  Item();
  virtual ~Item();

private:
  DynamicEntity* parent;

  StatModifier  item_stats;

  item::Type  base_type;
  std::string      item_name;
};

#endif /* ITEM_H_ */
