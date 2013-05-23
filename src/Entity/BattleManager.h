/*
 * BattleManager.h
 *
 *  Created on: May 23, 2013
 *      Author: Maiev
 */

#ifndef BATTLEMANAGER_H_
#define BATTLEMANAGER_H_

class GameEngine;
class DynamicEntity;
class PlayState;

class BattleManager {
public:
  BattleManager();
  virtual ~BattleManager();

  void setup(GameEngine* eng, PlayState* p);

  void attackUnit(DynamicEntity* atk, DynamicEntity* def);

  void update();
  void render();

private:
  GameEngine* eng_ptr;
  PlayState* parent;

  int round;
  enum Round { FIRST, SECOND, THIRD, FOURTH };
  Round stat;

  DynamicEntity* atk;
  DynamicEntity* def;
};

#endif /* BATTLEMANAGER_H_ */
