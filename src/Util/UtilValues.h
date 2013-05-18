/*
 * UnitValues.h
 *
 *  Created on: May 4, 2013
 *      Author: Maiev
 */

#ifndef UNITVALUES_H_
#define UNITVALUES_H_

const int UNIT_MOVE = 2;
const int UNIT_ATTACK = 1;

struct StatModifier {
  int health;
  int str;
  int dex;
  int agi;
  int def;
  int res;
  int lck;

  StatModifier() {
    health = 0;
    str = 0;
    dex = 0;
    agi = 0;
    def = 0;
    res = 0;
    lck = 0;
  }
};


#endif /* UNITVALUES_H_ */
