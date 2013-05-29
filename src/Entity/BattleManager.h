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

  enum Result { HIT, MISS, KILL };

private:
  GameEngine* eng_ptr;
  PlayState* parent;

  void battle();

  enum Round { FIRST, SECOND, THIRD, FOURTH };
  Round stat;

  DynamicEntity* atk;
  DynamicEntity* def;
  bool           hit;
};

#endif /* BATTLEMANAGER_H_ */
