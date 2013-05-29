/*
 * UtilFunc.h
 *
 *  Created on: May 4, 2013
 *      Author: Maiev
 */

#ifndef UTILFUNC_H_
#define UTILFUNC_H_
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
using namespace std;

class Cell;
class Camera;

template <typename T>
string numberToString(T number) {
  ostringstream ss;
  ss << number;
  return ss.str();
}

int cellDist(Cell* c1, Cell* c2);

sf::Vector2i localToGlobal(sf::Vector2i loc, Camera* cam);
sf::Vector2i globalToLocal(sf::Vector2i glo, Camera* cam);

#endif /* UTILFUNC_H_ */
