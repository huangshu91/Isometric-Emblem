/*
 * GUIFrame.h
 *
 *  Created on: Apr 24, 2013
 *      Author: Maiev
 */

#ifndef GUIFRAME_H_
#define GUIFRAME_H_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>

class GameEngine;

class GUIFrame {
public:
  GUIFrame();
  virtual ~GUIFrame();

  void setup(GameEngine* eng);
  void build(sf::Vector2i loc, sf::Vector2i s);
  virtual void setText(std::vector<std::string> args);
  virtual void render();

  const sf::Vector2i getLoc() { return center; };
  const sf::Vector2i getSize() { return size; };
  // theres something buggy about getting the default font in this way,
  // this will be disabled until we add in custom fonts.
  //sf::Font getFont() { return sf::Font::getDefaultFont(); };

protected:
  GameEngine* eng_ptr;
  sf::RenderWindow* win_ptr;

  std::vector<sf::Sprite> draw_tiles;
  std::vector<sf::Text> draw_text;

  sf::Vector2i center;
  sf::Vector2i size;

  //static sf::Font font;
  sf::Font font;
};

#endif /* GUIFRAME_H_ */
