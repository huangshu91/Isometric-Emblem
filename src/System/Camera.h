/*
 * Camera.h
 *
 *  Created on: Jun 27, 2012
 *      Author: Maiev
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../Util/FormatClock.h"

class Camera {
public:
  Camera();
  ~Camera();

  void SetWindow(sf::RenderWindow *wp);

  void CenterCamera();
  void ZoomCamera(float factor);
  void Move(float x, float y);
  void setCenter(sf::Vector2f center);

  void smoothMove(sf::Vector2f center, float time);

  void update();

  sf::Vector2f GetLocation();
  const sf::Vector2f GetCenter();

  sf::View* GetView();

private:

  sf::View            cam_view;
  sf::RenderWindow*   window_ptr;

  sf::Vector2f smooth_goal;
  sf::Vector2f smooth_start;
  FormatClock smooth_clock;
  float smoothTime;
  bool isSmoothMove;
};


#endif /* CAMERA_H_ */
