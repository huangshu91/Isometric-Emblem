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
    buildMenu(menu::ITEM);
    base_menu->has_focus = false;
    cur_menu = base_menu->getChild(MENU_HUD_ITEM);
    cur_menu->enable();
    cur_menu->has_focus = true;
  }

  if (!cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::SHOP])) {
  }

  if (!cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::DEBUG])) {
    statushudr_ptr->disable();
    statushudl_ptr->disable();
    eng_ptr->getHUD()->getSpeechHUD()->loadConvo(STATUS_CONVO);
    eng_ptr->getPlayState()->changePhase(playstate::CONVO);
    cur_menu->disable();
    finishSelect();
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

    if (DEBUG) coms.push_back(menu::CHOICE_TEXT[menu::DEBUG]);
    base_menu->build(coms);
    base_menu->enable();
    cur_menu = base_menu;
    cur_menu->has_focus = true;
  } break;
  case menu::ITEM : {

  } break;

  default:
    break;
  }
}

void InputController::backMenu() {
  if (cur_menu->getMenuId().compare(MENU_HUD_UNIT) == 0) {
    state = inputstate::MOVE;
    base_menu->disable();
    map_ptr->moveUnit(selected, prev_loc.x, prev_loc.y);
    map_ptr->toggleRangeOn(selected, range::COMBINED);
  }

  else if (cur_menu->getMenuId().compare(MENU_HUD_ITEM) == 0) {
    cur_menu->has_focus = false;
    cur_menu->disable();
    base_menu->has_focus = true;
    cur_menu = base_menu;

  }
}


