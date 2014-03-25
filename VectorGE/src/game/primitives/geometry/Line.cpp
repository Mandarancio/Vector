/*
 * Line.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Line.h"

Line::Line(SDL_Point p1, SDL_Point p2) :
		p1_(p1), p2_(p2) {
	computeBox();
}

Line::Line(int x1, int y1, int x2, int y2) {
	p1_.x = x1;
	p1_.y = y1;
	p2_.x = x2;
	p2_.y = y2;
	computeBox();
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

bool Line::pointOnLine(SDL_Point p) {
	return true;
}

bool Line::intersectLine(Line l) {
	return false;
}

SDL_Rect Line::getBoundingBox() {
	return boundingBox_;
}

void Line::computeBox() {
	int x, y, w, h;
	x = p1_.x;
	y = p1_.y;
	if (x > p2_.x) {
		x = p2_.x;
		w = p1_.x - x;
	} else {
		w = p2_.x - x;
	}
	if (y>p2_.y){
		y= p2_.y;
		h=p1_.y-y;
	}
	else {
		h=p2_.y-y;
	}

	boundingBox_.x=x;
	boundingBox_.y=y;
	boundingBox_.w=w;
	boundingBox_.h=h;
}
