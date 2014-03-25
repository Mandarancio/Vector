/*
 * SolidColorMethod.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "SolidColorMethod.h"

SolidColorMethod::SolidColorMethod(Color c) :
		color_(c) {

}

SolidColorMethod::~SolidColorMethod() {
}

Color SolidColorMethod::colorAt(SDL_Point p) {
	return color_;
}

Color SolidColorMethod::colorAt(int x, int y) {
	return color_;
}
