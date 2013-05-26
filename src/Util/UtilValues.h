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

struct StatPack {
  int hp;
  int max_hp;
  int str;
  int dex;
  int agi;
  int def;
  int res;
  int lck;
  int con;
  int cha;

  StatPack() {
    hp = 0;
    max_hp = 0;
    str = 0;
    dex = 0;
    agi = 0;
    def = 0;
    res = 0;
    lck = 0;
    con = 0;
    cha = 0;
  }

  StatPack(int h, int ma, int s, int de, int a,
      int d, int r, int l, int co, int ch) {
    hp = h;
    max_hp = ma;
    str = s;
    dex = de;
    agi = a;
    res = r;
    def = d;
    lck = l;
    con = co;
    cha = ch;
  }
};


#endif /* UNITVALUES_H_ */
