/*
 * MenuWidget.h
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#ifndef MENUWIDGET_H_
#define MENUWIDGET_H_
#include "../Interface/GUIFrame.h"
#include "GUIWidget.h"
#include "../Util/Constants.h"
#include <vector>

class MenuWidget: public GUIWidget {
public:
  MenuWidget();
  virtual ~MenuWidget();

  void setup(GameEngine* eng);
  void build(sf::Vector2i loc, std::vector<std::string> opt);

  void enable();
  void disable();
  void select(int s);

  std::string getChoiceName() { return choices[selected]; };
  int getChoice() { return selected; };
  void disableChoice(menu::Choice c);

  void render();

private:
  GUIFrame frame;

  sf::Vector2i MENU_SIZE;
  sf::Vector2i CENTER;

  bool visible;

  std::vector<std::string> choices;
  std::vector<sf::Text> c_text;
  std::vector<bool> c_enable;
  int     num_opt;
  int     selected;
};

#endif /* MENUWIDGET_H_ */
