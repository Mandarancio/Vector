/*
 * Line.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Line.h"
#include "../../../support/Geometric.h"

#include <math.h>
#include <iostream>

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
}

bool Line::contains(SDL_Point p) {
	if (!rectContains(boundingBox_, p))
		return false;

	int dx = p2_.x - p1_.x;
	if (dx != 0) {
		double k = 1.0 * (p2_.y - p1_.y) / dx;
		double y = 1.0 * p1_.y + k * (p.x - p1_.x);
		if (abs(y - p.y) < 0.05)
			return true;
	} else {
		int dy = p2_.y - p1_.y;
		if (dy == 0) {
			return (p.x == boundingBox_.x && p.y == boundingBox_.y);
		}
		double k = 1.0 * (p2_.x - p1_.x) / dy;
		double x = 1.0 * p1_.x + k * (p.y - p1_.y);
		if (abs(x - p.x) < 0.05)
			return true;
	}

	return false;
}

bool Line::contains(int x, int y) {
	SDL_Point p;
	p.x = x;
	p.y = y;
	return contains(p);
}

bool Line::intersectLine(Line l) {

	float x12 = (float) p1_.x - (float) p2_.x;
	float x34 = (float) l.p1().x - (float) l.p2().x;
	float y12 = (float) p1_.y - (float) p2_.y;
	float y34 = (float) l.p1().y - (float) l.p2().y;

	float c = x12 * y34 - y12 * x34;

	if (fabs(c) < 0.01) {
		return false;
	} else {
		return true;
	}
}

bool Line::intersectLine(Line l, SDL_Point &inters){
	float x12 = (float) p1_.x - (float) p2_.x;
	float x34 = (float) l.p1().x - (float) l.p2().x;
	float y12 = (float) p1_.y - (float) p2_.y;
	float y34 = (float) l.p1().y - (float) l.p2().y;

	float c = x12 * y34 - y12 * x34;

	if (fabs(c) < 0.01) {
		return false;
	} else {
		// Intersection
		float a = p1_.x * p2_.y - p1_.y * p2_.x;
		float b = l.p1().x * l.p2().y - l.p1().y * l.p2().x;

		float x = (a * x34 - b * x12) / c;
		float y = (a * y34 - b * y12) / c;

		inters.x=round(x);
		inters.y=round(y);

		return true;
	}
}


SDL_Point Line::intersectPoint(Line l) {
	float x12 = (float) p1_.x - (float) p2_.x;
	float x34 = (float) l.p1().x - (float) l.p2().x;
	float y12 = (float) p1_.y - (float) p2_.y;
	float y34 = (float) l.p1().y - (float) l.p2().y;

	float c = x12 * y34 - y12 * x34;

	if (fabs(c) < 0.01) {
		return (SDL_Point){-1,-1};
	} else {
		// Intersection
		float a = p1_.x * p2_.y - p1_.y * p2_.x;
		float b = l.p1().x * l.p2().y - l.p1().y * l.p2().x;

		float x = (a * x34 - b * x12) / c;
		float y = (a * y34 - b * y12) / c;

		return (SDL_Point){round(x),round(y)};
	}

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
	if (y > p2_.y) {
		y = p2_.y;
		h = p1_.y - y;
	} else {
		h = p2_.y - y;
	}

	boundingBox_.x = x;
	boundingBox_.y = y;
	boundingBox_.w = w;
	boundingBox_.h = h;
}
float Line::lenght() {
	return sqrt(
			boundingBox_.w * boundingBox_.w + boundingBox_.h * boundingBox_.h);
}

SDL_Point Line::p1() {
	return p1_;
}
SDL_Point Line::p2() {
	return p2_;
}

Shape * Line::transform(Transformation t) {
	return transformLine(t);
}
Line * Line::transformLine(Transformation t) {
	return new Line(t.transform(p1_), t.transform(p2_));
}

