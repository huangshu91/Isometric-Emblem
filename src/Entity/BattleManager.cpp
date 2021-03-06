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
#include "../System/EffectManager.h"
#include "../Util/Globals.h"
#include "../Util/UtilFunc.h"

BattleManager::BattleManager() {
  eng_ptr = 0;
  atk = 0;
  def = 0;
  parent = 0;
  stat = FIRST;
  hit = false;
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
  hit = false;

  parent->changePhase(playstate::FIGHT);
  stat = FIRST;
}


void BattleManager::update() {
  if (stat == FIRST) {
    if (!DelayClock.setTimer(0.1)) return;
    stat = SECOND;

    battle();
    DynamicEntity* swap = atk;
    atk = def;
    def = swap;

  } else if (stat == SECOND) {

    if (!DelayClock.setTimer(0.5)) return;
    //stat = THIRD;
    parent->changePhase(playstate::FINISHFIGHT);

    battle();
    Result r = (hit == true) ? HIT : MISS;

    if (atk->getControl() == unit::PLAYER) {
      int val = atk->gainEXP(def, r);
      eng_ptr->getHUD()->getEXPHUD()->updateChar(atk, atk->exp-val, atk->exp);
    }
    else if (def->getControl() == unit::PLAYER) {
      int val = def->gainEXP(atk, r);
      eng_ptr->getHUD()->getEXPHUD()->updateChar(def, def->exp-val, def->exp);
    }

    hit = false;
  }

  eng_ptr->getGameCam()->shakeMove(SHAKE_INTENSITY);
}

void BattleManager::battle() {
  int power = atk->getPow();
  int defense = def->getDef();
  int damage = power-defense;

  bool tookDmg = def->takeDamage(power-defense);

  effect::param opt;
  opt.s = numberToString(damage);
  opt.disappear = true;
  opt.fade = true;
  opt.lifetime = 1;
  opt.loc = def->getLoc();
  eng_ptr->getEffect()->addEffect(effect::TEXT, opt);

  if (def->total.hp == 0) {
    if (atk->getControl() == unit::PLAYER) {
      int val = atk->gainEXP(def, Result::KILL);
      eng_ptr->getHUD()->getEXPHUD()->updateChar(atk, atk->exp-val, atk->exp);
    }
    def->unitDeath();
  }
  hit = (tookDmg && atk->getControl() == unit::PLAYER) ? true : hit;
}

void BattleManager::render() {

}
