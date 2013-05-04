/*
 * UtilFunc.h
 *
 *  Created on: May 4, 2013
 *      Author: Maiev
 */

#ifndef UTILFUNC_H_
#define UTILFUNC_H_
#include <string>
#include <sstream>
using namespace std;

class Cell;

template <typename T>
string numberToString(T number) {
  ostringstream ss;
  ss << number;
  return ss.str();
}

int cellDist(Cell* c1, Cell* c2);

#endif /* UTILFUNC_H_ */
