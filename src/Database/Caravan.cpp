/*
 * Caravan.cpp
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#include "Caravan.h"
#include "../System/GameEngine.h"
#include "../Entity/DynamicEntity.h"

Caravan::Caravan() {
  // TODO Auto-generated constructor stub
  eng_ptr = 0;
}

Caravan::~Caravan() {
  // TODO Auto-generated destructor stub
}

void Caravan::setup(GameEngine* eng) {
  eng_ptr = eng;
}

void Caravan::addPlayer(DynamicEntity* e) {
  play.push_back(e);
}

void Caravan::removePlayer(DynamicEntity* e) {

}
