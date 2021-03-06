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
#include "../Util/Constants.h"

class Camera {
public:
  Camera();
  ~Camera();

  void setup(sf::RenderWindow *wp);

  void CenterCamera();
  void zoomCamera(float factor);
  void move(float x, float y);
  void setCenter(sf::Vector2f center);

  void smoothMove(sf::Vector2f center, float time);
  void shakeMove(sf::Vector2f center, int inten);
  void shakeMove(int inte);

  void update();

  float getZoom() { return zoomAmount; };
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

  float deltaT;
  sf::Vector2f moveamt;

  sf::Vector2f shake_start;
  FormatClock shake_clock;
  int intensity;

  float zoomAmount;

  camera::Effect  state;
};


#endif /* CAMERA_H_ */
