/*
 * BattleManager.cpp
 *
 *  Created on: May 23, 2013
 *      Author: Maiev
 */

#include "BattleManager.h"
#include "DynamicEntity.h"
#include "../System/GameEngine.h"
#include "../Gamestate/PlayState.h"
#include "../Entity/DynamicEntity.h"
#include "../System/Camera.h"

BattleManager::BattleManager() {
  eng_ptr = 0;
  atk = 0;
  def = 0;
  parent = 0;
  round = 0;
}

BattleManager::~BattleManager() {
  // TODO Auto-generated destructor stub
}

void BattleManager::setup(GameEngine* eng, PlayState* p) {
  eng_ptr = eng;
  parent = p;
}

void BattleManager::attackUnit(DynamicEntity* a, DynamicEntity* d) {
  atk = a;
  def = d;

  parent->changePhase(gamestate::FIGHT);
  stat = FIRST;
}


void BattleManager::update() {
  if (stat == FIRST) {
    stat = SECOND;
    int power = atk->getPow();
    int defense = def->getDef();

    def->takeDamage(power-defense);
    DynamicEntity* swap = atk;
    atk = def;
    def = swap;
  } else if (stat == SECOND) {
    //stat = THIRD;
    parent->changePhase(gamestate::FINISHFIGHT);
  }

  eng_ptr->getGameCam()->shakeMove(SHAKE_INTENSITY);
}

void BattleManager::render() {

}
