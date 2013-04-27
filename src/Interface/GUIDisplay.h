/*
 * GUIDisplay.h
 *
 *  Created on: Apr 26, 2013
 *      Author: Maiev
 */

#ifndef GUIDISPLAY_H_
#define GUIDISPLAY_H_
#include <vector>
#include <string>
#include "GUIFrame.h"

class GUIDisplay : public GUIFrame {
public:
  GUIDisplay();
  virtual ~GUIDisplay();

  void setText(std::vector<std::string> args);

  void render();

private:
  std::vector<sf::String> text;
};

#endif /* GUIDISPLAY_H_ */
