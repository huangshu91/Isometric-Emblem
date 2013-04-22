/*
 * Camera.cpp
 *
 *  Created on: Jun 27, 2012
 *      Author: Maiev
 */

#include "Camera.h"
#include "../Util/Constants.h"
using namespace std;

Camera::Camera() {
  cam_view.setCenter(0, 0);
  cam_view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

Camera::~Camera() { }

void Camera::SetWindow(sf::RenderWindow *wp) {
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
void Camera::Update(sf::Vector2f cent) {
  cam_view.setCenter(cent);
}

void Camera::Move(int x, int y) {
  cam_view.move(x, y);
}

sf::View* Camera::GetView() {
  return &cam_view;
}

void Camera::ZoomCamera(float factor) {
  cam_view.zoom(factor);
}
