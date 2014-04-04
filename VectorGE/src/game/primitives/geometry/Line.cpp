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
	if (rectIntersect(l.getBoundingBox(), boundingBox_)) {

		float s1_x, s1_y, s2_x, s2_y, sn, tn, sd, td;
		s1_x = p2_.x - p1_.x;
		s1_y = p2_.y - p1_.y;
		s2_x = l.p2().x - l.p1().x;
		s2_y = l.p2().y - l.p1().y;

		sn = -s1_y * (p1_.x - l.p1().x) + s1_x * (p1_.y - l.p1().y);
		sd = -s2_x * s1_y + s1_x * s2_y;
		tn = s2_x * (p1_.y - l.p1().y) - s2_y * (p1_.x - l.p1().x);
		td = -s2_x * s1_y + s1_x * s2_y;

		if (sn >= 0 && sn <= sd && tn >= 0 && tn <= td) {
			return true;
		}
	}
	return false; // No collision
}

bool Line::intersectLine(Line l, SDL_Point &inters) {
	if (rectIntersect(l.getBoundingBox(), boundingBox_)) {
		float s1_x, s1_y, s2_x, s2_y;
		s1_x = p2_.x - p1_.x;
		s1_y = p2_.y - p1_.y;
		s2_x = l.p2().x - l.p1().x;
		s2_y = l.p2().y - l.p1().y;
		float s, t;
		s = (-s1_y * (p1_.x - l.p1().x) + s1_x * (p1_.y - l.p1().y))
				/ (-s2_x * s1_y + s1_x * s2_y);
		t = (s2_x * (p1_.y - l.p1().y) - s2_y * (p1_.x - l.p1().x))
				/ (-s2_x * s1_y + s1_x * s2_y);

		if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
			inters.x = p1_.x + (t * s1_x);
			inters.y = p1_.y + (t * s1_y);
			return true;
		}

		return false; // No collision
	}
	return false; // No collision
}

SDL_Point Line::intersectPoint(Line l) {
	float x12 = (float) p1_.x - (float) p2_.x;
	float x34 = (float) l.p1().x - (float) l.p2().x;
	float y12 = (float) p1_.y - (float) p2_.y;
	float y34 = (float) l.p1().y - (float) l.p2().y;

	float c = x12 * y34 - y12 * x34;

	if (fabs(c) < 0.01) {
		return (SDL_Point ) { -1, -1 } ;
			} else {
				// Intersection
				float a = p1_.x * p2_.y - p1_.y * p2_.x;
				float b = l.p1().x * l.p2().y - l.p1().y * l.p2().x;

				float x = (a * x34 - b * x12) / c;
				float y = (a * y34 - b * y12) / c;

				return (SDL_Point ) { (int)round(x), (int)round(y) } ;
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
							boundingBox_.w * boundingBox_.w
									+ boundingBox_.h * boundingBox_.h);
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

