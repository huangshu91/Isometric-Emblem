/*
 * InputControllerMenu.cpp
 *
 *  Created on: Sep 19, 2013
 *      Author: Maiev
 */
#include "InputController.h"
#include "../HUDWidget/MenuWidget.h"
#include "../System/GameEngine.h"
#include "../Levelmap/Map.h"
#include "../Util/ConvoKey.h"
#include "../Gamestate/PlayState.h"
#include <vector>
#include <string>
using namespace std;

void InputController::selectMenu() {
  inputtimer.resetClock();

  if (!cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::END])) {
    cur_menu->disable();
    finishSelect();
  }

  if (!cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::ATTACK])) {
    state = inputstate::ATTACK;
    base_menu->disable();
  }

  if (!cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::ITEMS])) {
    statushudr_ptr->disable();
    statushudl_ptr->disable();
    eng_ptr->getHUD()->getSpeechHUD()->loadConvo(STATUS_CONVO);
    eng_ptr->getPlayState()->changePhase(playstate::CONVO);
    cur_menu->disable();
    finishSelect();
  }

  if (!cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::SHOP])) {
  }
}

void InputController::buildMenu(menu::Type t) {
  switch (t) {
  case menu::UNIT : {
    vector<string> coms;

    if (map_ptr->inDistance(selected, unit::ENEMY)) {
      coms.push_back(menu::CHOICE_TEXT[menu::ATTACK]);
    }
    coms.push_back(menu::CHOICE_TEXT[menu::ITEMS]);
    coms.push_back(menu::CHOICE_TEXT[menu::END]);
    base_menu->build(coms);
    base_menu->enable();
    cur_menu = base_menu;
  } break;
  case menu::ITEM : {


  } break;

  default:
    break;
  }


}
