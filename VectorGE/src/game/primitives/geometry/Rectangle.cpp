/*
 * Rectangle.cpp
 *
 *  Created on: 06/apr/2014
 *      Author: martino
 */

#include "Rectangle.h"
#include "../../../support/Geometric.h"

Rectangle::Rectangle(int x, int y, int w, int h) {
	boundingBox_.x = x;
	boundingBox_.y = y;
	boundingBox_.w = w;
	boundingBox_.h = h;
}

Rectangle::Rectangle(SDL_Rect rect) {
	boundingBox_ = rect;
}

Rectangle::~Rectangle() {
}

bool Rectangle::contains(SDL_Point p){
	return rectContains(boundingBox_,p);
}

bool Rectangle::contains(int x, int y){
	return rectContains(boundingBox_,x,y);
}

Shape * Rectangle::transform(Transformation t){
	SDL_Rect r=boundingBox_;
	t.applyTransformation(r.x,r.y);
	t.applySizeTransformation(r.w,r.h);
	return new Rectangle(r);
}

