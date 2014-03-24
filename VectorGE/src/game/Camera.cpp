/*
 * Camera.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "Camera.h"

Camera::Camera(Painter *p) : Entity(), painter(p){
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

Painter * Camera::getPainter(){
	return painter;
}

void Camera::translate(int x,int y){
	painter->translate(x,y);
}
