/*
 * GUIWidget.h
 *
 *  Created on: Apr 27, 2013
 *      Author: Maiev
 */

#ifndef GUIWIDGET_H_
#define GUIWIDGET_H_

class GUIWidget {
public:
  GUIWidget();
  virtual ~GUIWidget();

  virtual void update() = 0;
  virtual void render() = 0;
};

#endif /* GUIWIDGET_H_ */
