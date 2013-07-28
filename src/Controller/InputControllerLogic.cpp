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

void InputController::update() {
  //if the window does not have focus, do not accept input
  if (eng_ptr->hasFocus() == false) return;

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
         if(setCurrentCell(tx,ty)){updateCell(1.3f);}
  	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
  	         {

  	         		selectCell();
  	         }
  /*
  sf::Vector2i pixelPos = sf::Mouse::getPosition(*win_ptr);
  pixelPos.x *= eng_ptr->getGameCam()->getZoom();
  pixelPos.y *= eng_ptr->getGameCam()->getZoom();
  pixelPos.x += eng_ptr->getGameCam()->GetLocation().x;
  pixelPos.y += eng_ptr->getGameCam()->GetLocation().y;
  int tx = ceil((pixelPos.x+2*pixelPos.y-30-30)/60);
  int ty = ceil((-pixelPos.x+2*pixelPos.y+30-30)/60);
  if(setCurrentCell(ty, tx) && inputtimer.getElapsedTime() > INPUT_DELAY)
  {
  updateCell();
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
      updateCell(0.3f);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()-1);
    }
    else if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol() - 1))
      updateCell(0.3f);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()+1);
    }
    else if (setCurrentCell(cur_cell->getRow() + 1, cur_cell->getCol()))
      updateCell(0.3f);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
      && inputtimer.getElapsedTime() > INPUT_DELAY) {
    if (state == inputstate::MENU) {
      inputtimer.resetClock();
      base_menu->select(base_menu->getChoice()+1);
    }
    else if (setCurrentCell(cur_cell->getRow(), cur_cell->getCol() + 1))
      updateCell(0.3f);
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

  /*
  if (cur_menu->getChoiceName().compare(menu::CHOICE_TEXT[menu::ITEM])) {

  }
  */
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
    else {
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
    bool canAttack = map_ptr->inDistance(selected, unit::ENEMY);
    map_ptr->toggleRangeOn(selected, range::ATTACK);

    state = inputstate::MENU;
    if (!canAttack) base_menu->disableChoice(menu::ATTACK);
    base_menu->enable();
    return;

    // for now go straight to attack if possible, in future use a menu with the action "attack"
    if (canAttack) {
      map_ptr->toggleRangeOn(selected, range::ATTACK);
      state = inputstate::ATTACK;
      return;
    } else {
      finishSelect();
      return;
    }
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
  base_menu->resetMenu();
  //eng_ptr->getPlayState()->changePhase(playstate::MENU_UNIT);
  selected = 0;
}
