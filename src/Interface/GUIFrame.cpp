/*
 * GUIFrame.cpp
 *
 *  Created on: Apr 24, 2013
 *      Author: Maiev
 */

#include "GUIFrame.h"
#include "../System/ResourceManager.h"
#include "../System/GameEngine.h"
#include "../Util/Constants.h"
#include <SFML/System.hpp>
#include <iostream>
using namespace std;

GUIFrame::GUIFrame() {
  eng_ptr = 0;
  win_ptr = 0;
}

void GUIFrame::setup(GameEngine* eng)  {
  eng_ptr = eng;
  win_ptr = eng_ptr->getWindow();
  eng_ptr->getRes()->addResource(GUI_FRAME_KEY, GUI_FRAME);
}

GUIFrame::~GUIFrame() {
  // TODO Auto-generated destructor stub
}

void GUIFrame::setText(vector<string> args) {
  cout << "error: update called on GUIFrame base class" << endl;
}

void GUIFrame::build(sf::Vector2i loc, sf::Vector2i s) {
  sf::Texture* tex = eng_ptr->getRes()->getResource(GUI_FRAME_KEY);

  size = s;
  center = loc;

  //first row
  sf::Sprite topleft(*tex);
  topleft.setTextureRect(sf::IntRect(0,0,FRAME_CELL, FRAME_CELL));
  topleft.setPosition(0,0);
  draw_tiles.push_back(topleft);
  int edges_len = (size.x - 2*FRAME_CELL)/FRAME_CELL;
  for (int i = 1; i <= edges_len; i++) {
    sf::Sprite tempedge(*tex);
    tempedge.setTextureRect(sf::IntRect(FRAME_CELL, 0, FRAME_CELL, FRAME_CELL));

    tempedge.setPosition(i*FRAME_CELL, 0);
    draw_tiles.push_back(tempedge);
  }
  sf::Sprite topright(*tex);
  topright.setTextureRect(sf::IntRect(FRAME_CELL*2, 0, FRAME_CELL, FRAME_CELL));
  topright.setPosition((edges_len+1)*FRAME_CELL, 0);
  draw_tiles.push_back(topright);

  //center rows
  int edges_height = (size.y - 2*FRAME_CELL)/FRAME_CELL;
  for (int i = 1; i <= edges_height; i++) {
    sf::Sprite temp_leftedge(*tex);
    temp_leftedge.setTextureRect(sf::IntRect(0, FRAME_CELL, FRAME_CELL, FRAME_CELL));
    temp_leftedge.setPosition(0, i*FRAME_CELL);
    draw_tiles.push_back(temp_leftedge);
    for (int j = 1; j <= edges_len; j++) {
      sf::Sprite tempedge(*tex);
      tempedge.setTextureRect(sf::IntRect(FRAME_CELL, FRAME_CELL, FRAME_CELL, FRAME_CELL));

      tempedge.setPosition(j*FRAME_CELL, i*FRAME_CELL);
      draw_tiles.push_back(tempedge);
    }

    sf::Sprite temp_rightedge(*tex);
    temp_rightedge.setTextureRect(sf::IntRect(2*FRAME_CELL, FRAME_CELL, FRAME_CELL, FRAME_CELL));
    temp_rightedge.setPosition((edges_len+1)*(FRAME_CELL), i*FRAME_CELL);
    draw_tiles.push_back(temp_rightedge);
  }

  //last row
  sf::Sprite botleft(*tex);
  botleft.setTextureRect(sf::IntRect(0, FRAME_CELL*2, FRAME_CELL, FRAME_CELL));
  botleft.setPosition(0, (edges_height+1)*FRAME_CELL);
  draw_tiles.push_back(botleft);
  for (int i = 1; i <= edges_len; i++) {
    sf::Sprite tempedge(*tex);
    tempedge.setTextureRect(sf::IntRect(FRAME_CELL, FRAME_CELL*2, FRAME_CELL, FRAME_CELL));

    tempedge.setPosition(i*FRAME_CELL, (edges_height+1)*FRAME_CELL);
    draw_tiles.push_back(tempedge);
  }
  sf::Sprite botright(*tex);
  botright.setTextureRect(sf::IntRect(FRAME_CELL*2, FRAME_CELL*2, FRAME_CELL, FRAME_CELL));
  botright.setPosition((edges_len+1)*FRAME_CELL, (edges_height+1)*FRAME_CELL);
  draw_tiles.push_back(botright);

  for (int i = 0, j = draw_tiles.size(); i < j; i++) {
    draw_tiles[i].move(sf::Vector2f(center-size/2));
  }
}

void GUIFrame::render() {
  for (int i = 0, j = draw_tiles.size(); i < j; i++) {
    win_ptr->draw(draw_tiles[i]);
  }
}
