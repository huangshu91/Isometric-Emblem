/*
 * FriendlyFire.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#include <SFML/Graphics.hpp>
#include "System/GameEngine.h"
#include "stdlib.h"
#include "time.h"

int main()
{
  srand(time(0));
  GameEngine gEng;
  gEng.runEngine();

  return 0;
}
