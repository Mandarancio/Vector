/*
 * Shape.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Shape.h"

Shape::Shape() {
	boundingBox_.x=0;
	boundingBox_.y=0;
	boundingBox_.w=0;
	boundingBox_.h=0;
}

Shape::~Shape() {

}

SDL_Rect Shape::getBoundingBox(){
	return boundingBox_;
}
