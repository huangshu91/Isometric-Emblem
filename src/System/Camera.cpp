/*
 * Camera.cpp
 *
 *  Created on: Jun 27, 2012
 *      Author: Maiev
 */

#include "Camera.h"
#include "../Util/Constants.h"
#include "stdlib.h"
#include <iostream>
#include <cmath>

Camera::Camera() {
  cam_view.setCenter(0, 0);
  cam_view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  window_ptr = 0;
  //shouldn't be a problem but possible divide by 0 in smooth move
  smoothTime = 0;
  intensity = 0;
  zoomAmount = 1;

  state = camera::NONE;
}

Camera::~Camera() { }

void Camera::setup(sf::RenderWindow *wp) {
  window_ptr = wp;
}

sf::Vector2f Camera::GetLocation() {
  sf::Vector2f cent = GetCenter();
  cent.x -= cam_view.getSize().x/2;
  cent.y -= cam_view.getSize().y/2;
  return cent;
}

const sf::Vector2f Camera::GetCenter() {
  return cam_view.getCenter();
}

void Camera::setCenter(sf::Vector2f cent) {
  state = camera::NONE;
  cam_view.setCenter(cent);
}

void Camera::smoothMove(sf::Vector2f center, float time) {
  smooth_goal = center;
  smooth_start = GetCenter();
  // time*fps_limit will give you how much to move PER FRAME
  smoothTime = time*FPS_LIMIT;
  deltaT = 0;
  state = camera::SMOOTH;

  sf::Vector2f diff = smooth_goal - smooth_start;
  moveamt = diff/time;
  smooth_clock.resetClock();
}

// for now use a constant shake duration, maybe add variable times if
// necessary for future features.
void Camera::shakeMove(sf::Vector2f center, int inten) {
  shake_start = cam_view.getCenter();
  intensity = inten;
  state = camera::SHAKE;

  shake_clock.resetClock();
}

void Camera::shakeMove(int inten) {
  shake_start = cam_view.getCenter();
  intensity = inten;
  state = camera::SHAKE;

  shake_clock.resetClock();
}

void Camera::update() {
  if (state == camera::SMOOTH) {
    if (smooth_clock.getElapsedTime()*FPS_LIMIT >= smoothTime) {
      cam_view.setCenter(smooth_goal);
      state = camera::NONE;
    }

    //different camera movement style
    /*
    sf::Vector2f diff = smooth_goal - smooth_start;
    move(diff.x/smoothTime, diff.y/smoothTime);
    */

    float delta = smooth_clock.getElapsedTime() - deltaT;
    move(moveamt.x*delta, moveamt.y*delta);
    deltaT = smooth_clock.getElapsedTime();
  }

  if (state == camera::SHAKE) {
    int x_mov = (rand()%(2*intensity+1))-intensity;
    int y_mov = (rand()%(2*intensity+1))-intensity;
    cam_view.move(x_mov, y_mov);

    if (shake_clock.getElapsedTime() >= SHAKE_DURATION) {
      cam_view.setCenter(shake_start);
      state = camera::NONE;
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
  zoomAmount = factor;
  cam_view.zoom(factor);
}
