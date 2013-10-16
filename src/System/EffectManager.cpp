/*
 * EffectManager.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: Maiev
 */

#include "EffectManager.h"
#include "GameEngine.h"
#include "../Effect/StrokeText.h"
using namespace std;

EffectManager::EffectManager() {
  eng_ptr = 0;
  win_ptr = 0;
  num_effects = 0;
  currentEffect = 0;
}

EffectManager::~EffectManager() {
  // TODO Auto-generated destructor stub
}

void EffectManager::setup(GameEngine* eng) {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();
}

void EffectManager::update() {
  auto it = text_col.begin();
  while (it != text_col.end()) {
    (*it).update();
    if ((*it).ended()) {
      it = text_col.erase(it);
      num_effects--;
    }
    else it++;
  }
}

void EffectManager::render() {
  for (auto it = text_col.begin(); it != text_col.end(); it++) {
    (*it).render();
  }

}

void EffectManager::addEffect(effect::Object o, effect::param opt) {
  switch (o) {
  case effect::TEXT: {
    StrokeText st;
    st.setup(eng_ptr, opt);
    text_col.push_back(st);
    currentEffect = &(text_col.back());
    break;
  }
  default:
    break;
  }
  num_effects++;
}

void EffectManager::addEffect(effect::Type t) {

}
