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

class Camera {
public:
  Camera();
  ~Camera();

  void SetWindow(sf::RenderWindow *wp);

  void CenterCamera();
  void ZoomCamera(float factor);
  void Move(int x, int y);
  void Update(sf::Vector2f center);

  sf::Vector2f GetLocation();
  const sf::Vector2f GetCenter();

  sf::View* GetView();

private:

  sf::View            cam_view;
  sf::RenderWindow*   window_ptr;
};


#endif /* CAMERA_H_ */
