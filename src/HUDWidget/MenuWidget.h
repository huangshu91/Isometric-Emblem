/*
 * MenuWidget.h
 *
 *  Created on: May 29, 2013
 *      Author: Maiev
 */

#ifndef MENUWIDGET_H_
#define MENUWIDGET_H_
#include "GUIWidget.h"
#include "../Interface/GUIFrame.h"
#include "../Util/Constants.h"
#include <vector>

class MenuWidget: public GUIWidget {
public:
  MenuWidget();
  virtual ~MenuWidget();

  void setup(GameEngine* eng);
  void build(sf::Vector2i loc, std::vector<std::string> opt, anchor::Region a);
  void build(std::vector<std::string> opt);
  sf::Vector2i getLoc() { return orig; };

  void addChild(MenuWidget);

  void enable();
  void select(int s);

  std::string getChoiceName() { return choices[selected]; };
  int getChoice() { return selected; };
  void disableChoice(menu::UnitChoice c);
  bool isDisabled(menu::UnitChoice c);
  std::string getMenuId() { return menu_id; };
  void setMenuId(std::string s) { menu_id = s; };
  MenuWidget* getParent() { return parent; };
  MenuWidget* getChild(std::string s);

  void resetMenu();
  void render();

private:
  void setAnchor(anchor::Region a);
  anchor::Region anc;
  sf::Vector2i orig;

  GUIFrame frame;

  sf::Vector2i MENU_SIZE;
  sf::Vector2i CENTER;

  std::vector<std::string> choices;
  std::vector<sf::Text> c_text;
  std::vector<bool> c_enable;
  int     num_opt;
  int     selected;

  sf::Sprite menu_cursor;

  std::string menu_id;

  MenuWidget* parent;
  std::vector<MenuWidget*> children;
};

#endif /* MENUWIDGET_H_ */
