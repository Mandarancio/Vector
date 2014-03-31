/*
 * BezierPath.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: martino
 */

#include "BezierPath.h"
#define BEZIER_RES 5

BezierCurve::BezierCurve(SDL_Point a, SDL_Point c_a, SDL_Point c_b,
		SDL_Point b) {
	this->a = a;
	this->b = b;
	this->c_a = c_a;
	this->c_b = c_b;
	__initLines();
}

BezierCurve::~BezierCurve() {
	__lines.clear();
	__points.clear();
}

bool BezierCurve::contains(SDL_Point p) {
	return contains(p.x, p.y);
}

bool BezierCurve::contains(int x, int y) {
	for (int i = 0; i < __lines.size(); i++) {
		if (__lines[i].contains(x, y))
			return true;
	}
	return false;
}

Shape * BezierCurve::transform(Transformation t) {
	SDL_Point a = this->a;
	SDL_Point b = this->b;
	SDL_Point c_a = this->c_a;
	SDL_Point c_b = this->c_b;
	t.applyTransformation(a);
	t.applyTransformation(b);
	t.applyTransformation(c_b);
	t.applyTransformation(c_a);
	return new BezierCurve(a, c_a, c_b, b);
}

SDL_Point BezierCurve::getPointA() {
	return a;
}

SDL_Point BezierCurve::getPointB() {
	return b;
}

SDL_Point BezierCurve::getControlPointA() {
	return c_a;
}

SDL_Point BezierCurve::getControlPointB() {
	return c_b;
}

std::vector<SDL_Point> BezierCurve::getPoints() {
	return __points;
}

std::vector<Line> BezierCurve::getLines() {
	return __lines;
}

void BezierCurve::__initLines() {
	int dx = b.x - a.x;
	int dy = b.y - a.y;
	int d = round(sqrt(dx * dx + dy * dy));
	int n = d / BEZIER_RES;
	if (n < 12)
		n = 12;
	float dt;
	int i;

	dt = 1.0 / (n - 1);

	for (i = 0; i < n; i++) {
		__points.push_back(__computePoint(i * dt));
		if (i > 0) {
			__lines.push_back(Line(__points[i], __points[i - 1]));
		}
	}

}

SDL_Point BezierCurve::__computePoint(float t) {
	float ax, bx, cx;
	float ay, by, cy;
	float tSquared, tCubed;
	SDL_Point result;

	/* calcolo dei coefficienti del polinomio */

	cx = 3.0 * (c_a.x - a.x);
	bx = 3.0 * (c_b.x - c_a.x) - cx;
	ax = b.x - a.x - cx - bx;

	cy = 3.0 * (c_a.y - a.y);
	by = 3.0 * (c_b.y - c_a.y) - cy;
	ay = b.y - a.y - cy - by;

	/* calcolo del punto della curva in relazione a t */

	tSquared = t * t;
	tCubed = tSquared * t;

	result.x = (ax * tCubed) + (bx * tSquared) + (cx * t) + a.x;
	result.y = (ay * tCubed) + (by * tSquared) + (cy * t) + a.y;

	return result;
}

BezierPath::BezierPath() {
	__closed=false;
}
BezierPath::~BezierPath() {
	for (int i=0;i<__curves.size();i++){
		delete __curves[i];
	}
	__curves.clear();
}

bool BezierPath::contains(SDL_Point p) {
	return contains(p.x,p.y);
}
bool BezierPath::contains(int x, int y) {
	return false;
}
Shape * BezierPath::transform(Transformation t) {
	return 0;
}
