/*
 * Camera.cpp
 *
 *  Created on: Jun 27, 2012
 *      Author: Maiev
 */

#include "Camera.h"
#include "../Util/Constants.h"
#include <iostream>
using namespace std;

Camera::Camera() {
  cam_view.setCenter(0, 0);
  cam_view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  isSmoothMove = false;
}

Camera::~Camera() { }

void Camera::setup(sf::RenderWindow *wp) {
  window_ptr = wp;
}

sf::Vector2f Camera::GetLocation() {
  sf::Vector2f retpos(cam_view.getViewport().left, cam_view.getViewport().top);
  return retpos;
}

const sf::Vector2f Camera::GetCenter() {
  return cam_view.getCenter();
}

// TODO: this probably needs rework or support update through entity/tile
void Camera::setCenter(sf::Vector2f cent) {
  isSmoothMove = false;
  cam_view.setCenter(cent);
}

void Camera::smoothMove(sf::Vector2f center, float time) {
  smooth_goal = center;
  smooth_start = GetCenter();
  smoothTime = time*FPS_LIMIT;
  isSmoothMove = true;

  sf::Vector2f diff = smooth_goal - smooth_start;
  move(diff.x/smoothTime, diff.y/smoothTime);
  smooth_clock.resetClock();
}

void Camera::update() {
  if (isSmoothMove) {
    sf::Vector2f diff = smooth_goal - smooth_start;
    move(diff.x/smoothTime, diff.y/smoothTime);

    if (smooth_clock.getElapsedTime()*FPS_LIMIT >= smoothTime) {
      isSmoothMove = false;
    }
  }

}

void Camera::move(float x, float y) {
  cam_view.move(x, y);
}

sf::View* Camera::GetView() {
  return &cam_view;
}

void Camera::zoomCamera(float factor) {
  cam_view.zoom(factor);
}
