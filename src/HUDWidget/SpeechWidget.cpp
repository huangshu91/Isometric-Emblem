/*
 * SpeechWidget.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: Maiev
 */

#include "SpeechWidget.h"
#include "../System/GameEngine.h"
#include "../Database/Database.h"
#include <string>

sf::Vector2i SpeechWidget::MENU_SIZE = sf::Vector2i(920, 160);
// Modify these to be more consistent once sprite size is figured out
sf::Vector2i SpeechWidget::CHAR_POS[] = { sf::Vector2i(170, 360),
    sf::Vector2i(270,360), sf::Vector2i(370, 360), sf::Vector2i(610, 360),
    sf::Vector2i(710,360), sf::Vector2i(710, 360)};

SpeechWidget::SpeechWidget() {
  t_rate = TEXT_RATE;
  cur_page = 0;
  finished = false;
}

SpeechWidget::~SpeechWidget() {
  // TODO Auto-generated destructor stub
}

void SpeechWidget::setup(GameEngine* eng) {
  GUIWidget::setup(eng);
  text_hud.setup(eng);

  MENU_LOC = sf::Vector2i(WINDOW_WIDTH/2, WINDOW_HEIGHT - (MENU_SIZE.y/2+20));
  text_hud.build(MENU_LOC, MENU_SIZE);
  text_hud.enable();
}

void SpeechWidget::loadConvo(string convo) {
  conv = eng_ptr->getDatabase()->getConvo(convo);
  if (conv.pages == 0 && conv.chars == 0) {
    eng_ptr->getLog()->e("Could not load convo: "+convo);
    return;
  }

  finished = false;
  cur_page = 0;
  for (unsigned int i = 0; i < conv.char_keys.size(); i++) {
    string it = conv.char_keys[i];
    sf::Sprite s(*(eng_ptr->getRes()->getResource(it)));
    s.setOrigin(s.getLocalBounds().width/2, s.getLocalBounds().height);
    s.setPosition(sf::Vector2f(CHAR_POS[conv.char_pos[i]]));
    Speaker tmp;
    tmp.name = it;
    tmp.sp = s;
    actors.push_back(tmp);
    actor.insert(make_pair(it, tmp));
  }

  cur_speak = actor.find(conv.dialogue[cur_page].char_key)->second;
  text_hud.setText(conv.dialogue[cur_page].line);
}

void SpeechWidget::nextPage() {
  // Or could display whole page instantly
  if (text_hud.isFinished() == false) return;

  cur_page++;
  if (cur_page >= conv.dialogue.size()) {
    finished = true;
    return;
  }

  text_hud.setText(conv.dialogue[cur_page].line);
  cur_speak = actor.find(conv.dialogue[cur_page].char_key)->second;
}

void SpeechWidget::update() {
  text_hud.update();
}

void SpeechWidget::render() {
  if (!visible) return;

  for (unsigned int i = 0; i < actors.size(); i++) {
    win_ptr->draw(actors[i].sp);
  }

  sf::View v = win_ptr->getView();
  sf::RectangleShape rs(sf::Vector2f(960,540));
  rs.setPosition(v.getViewport().left, v.getViewport().top);
  rs.setFillColor(sf::Color(0,0,0,100));
  win_ptr->draw(rs);

  win_ptr->draw(cur_speak.sp);

  text_hud.render();
}
