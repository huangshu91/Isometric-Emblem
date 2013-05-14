/*
 * AIController.h
 *
 *  Created on: May 12, 2013
 *      Author: Maiev
 */

#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_

class GameEngine;

class AIController {
public:
  AIController(GameEngine* eng);
  virtual ~AIController();

private:
  GameEngine* eng_ptr;
};

#endif /* AICONTROLLER_H_ */
