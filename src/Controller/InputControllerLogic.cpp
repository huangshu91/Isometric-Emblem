/*
 * InputControllerLogic.cpp
 *
 *  Created on: July 26, 2013
 *      Author: Maiev
 */

#include "InputController.h"
#include "../Levelmap/Map.h"
#include "../Levelmap/Cell.h"
#include "../Entity/DynamicEntity.h"
#include "../Util/UtilFunc.h"
#include "../System/GameEngine.h"
#include "../HUDWidget/MenuWidget.h"
#include "../Gamestate/PlayState.h"
#include "../Util/ConvoKey.h"

void InputController::update() {
  //if the window does not have focus, do not accept input

  if (eng_ptr->hasFocus() == false) return;

  /*
  sf::Vector2i pixelPos = sf::Mouse::getPosition(*win_ptr);
  pixelPos.x *= eng_ptr->getGameCam()->getZoom();
  pixelPos.y *= eng_ptr->getGameCam()->getZoom();
  pixelPos.x += eng_ptr->getGameCam()->GetLocation().x;
  pixelPos.y += eng_ptr->getGameCam()->GetLocation().y;
  sf::Vector2f worldPos = win_ptr->mapPixelToCoords(pixelPos);
  worldPos.x /= 30; //TSIZE_X/2
  worldPos.y /= 15; //TSIZE_Y/4
  int tx = ((worldPos.y - worldPos.x)/2)+0.5;
  int ty = ((worldPos.x + worldPos.y)/2)-0.5;
  if(setCurrentCell(tx,ty)){updateCell(2.0f);}
  if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    selectCell();
  }
  */

  // move the cursor highlight
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()-1);
    }
    else if (setCurrentCell(cur_cell->getRow() - 1, cur_cell->getCol()))
      updateCell(KEY_PAN_SENS);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()-1);
    }
    else if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol() - 1))
      updateCell(KEY_PAN_SENS);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()+1);
    }
    else if (setCurrentCell(cur_cell->getRow() + 1, cur_cell->getCol()))
      updateCell(KEY_PAN_SENS);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()+1);
    }
    else if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol() + 1))
      updateCell(KEY_PAN_SENS);
  }

  // select the current cell
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) selectMenu();
    else selectCell();
  }

  // cancel previous action. does nothing if not in menu
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      state = inputstate::MOVE;
      base_menu->disable();
      map_ptr->moveUnit(selected, prev_loc.x, prev_loc.y);
      map_ptr->toggleRangeOn(selected, range::COMBINED);
    }
    else if (state == inputstate::MOVE) {
      inputtimer.resetClock();
      state = inputstate::FREE;
      map_ptr->toggleRangeOff();
      selected = 0;
    }
    else if (state == inputstate::ATTACK) {
      inputtimer.resetClock();
      base_menu->enable();
      state = inputstate::MENU;
    }
  }
}

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

bool InputController::setCurrentCell(int x, int y) {
  Cell* c = map_ptr->getCell(x, y);
  inputtimer.resetClock();

  if (state == inputstate::MOVE
      && cellDist(selected->getCurCell(), c) > selected->getRange(range::MOVE)
      && selected->getControl() == unit::PLAYER) {
    return false;
  }

  if (state == inputstate::ATTACK
      && cellDist(selected->getCurCell(), c)
          > selected->getRange(range::ATTACK)) {
    return false;
  }

  if (c != 0) {
    cur_cell = c;
    tilehighlight.setPosition(sf::Vector2f(cur_cell->getLoc()));
    return true;
  }
  return false;
}

void InputController::selectCell() {
  inputtimer.resetClock();
  // a unit was NOT previously selected already

  if (state == inputstate::FREE) {
    if (cur_cell->unit) {//&& cur_cell->unit->can_move) {
      selected = cur_cell->unit;
      map_ptr->toggleRangeOn(selected, range::COMBINED);
      state = inputstate::MOVE;
      return;
    }
    else { // select a cell with no unit, open general menu
      eng_ptr->getPlayState()->changePhase(playstate::MENU);
    }
  }

  if (state == inputstate::MOVE) {
    if (selected->getControl() != unit::PLAYER) {
      finishSelect();
      return;
    }

    prev_loc.x = selected->getCurCell()->getRow();
    prev_loc.y = selected->getCurCell()->getCol();
    if (!map_ptr->moveUnit(selected, cur_cell->getRow(), cur_cell->getCol()))
      return;
    map_ptr->toggleRangeOff();
    state = inputstate::ACTION;
    //bool canAttack = map_ptr->inDistance(selected, unit::ENEMY);
    map_ptr->toggleRangeOn(selected, range::ATTACK);

    state = inputstate::MENU;
    buildMenu(menu::UNIT);
    //base_menu->enable();
    return;
  }

  if (state == inputstate::ATTACK) {
    // end move, dont attack
    /*
    if (cur_cell == selected->getCurCell()) {
      finishSelect();
      return;
    }
    */
    if (cur_cell->unit != 0 && cur_cell->unit->getControl() == unit::ENEMY) {
      selected->attackUnit(cur_cell->unit);
      finishSelect();
      return;
    }
  }
}

void InputController::finishSelect() {
  map_ptr->toggleRangeOff();
  state = inputstate::FREE;
  selected->can_move = false;
  selected = 0;
}
