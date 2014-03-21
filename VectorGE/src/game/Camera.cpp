/*
 * Camera.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "Camera.h"

Camera::Camera(SDL_Renderer *renderer) : Entity(){
	this->renderer=renderer;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

