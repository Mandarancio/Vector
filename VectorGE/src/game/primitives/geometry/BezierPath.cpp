/*
 * BezierPath.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: martino
 */

#include "BezierPath.h"
#include "../../../support/Geometric.h"
#define BEZIER_RES 5

BezierCurve::BezierCurve(SDL_Point a, SDL_Point c_a, SDL_Point c_b,
		SDL_Point b) {
	this->a = a;
	this->b = b;
	this->c_a = c_a;
	this->c_b = c_b;
	__initLines();
	__computeBBox();
}
BezierCurve::BezierCurve(SDL_Point a, SDL_Point c, SDL_Point b) {
	this->a = a;
	this->b = b;
	this->c_a = c;
	this->c_b = c;
	__initLines();
	__computeBBox();
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
	return transformBezierCurve(t);
}

BezierCurve * BezierCurve::transformBezierCurve(Transformation t) {
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

std::vector<SDL_Point> BezierCurve::vertex() {
	return __points;
}

std::vector<Line> BezierCurve::getLines() {
	return __lines;
}

void BezierCurve::__computeBBox() {
	SDL_Rect bb = __lines[0].getBoundingBox();
	SDL_Rect bbi;
	for (int i = 1; i < __lines.size(); i++) {

		bbi = __lines[i].getBoundingBox();
		if (bb.x > bbi.x) {
			bb.w += bb.x - bbi.x;
			bb.x = bbi.x;
		}
		if (bb.y > bbi.y) {
			bb.h += bb.y - bbi.y;
			bb.y = bbi.y;
		}
		if (bb.w < abs(bbi.x - bb.x) + bbi.w) {
			bb.w = abs(bbi.x - bb.x) + bbi.w;
		}
		if (bb.h < abs(bbi.y - bb.y) + bbi.h) {
			bb.h = abs(bbi.y - bb.y) + bbi.h;
		}

	}
	boundingBox_ = bb;
}

void BezierCurve::__initLines() {
	int dx = b.x - a.x;
	int dy = b.y - a.y;
	int dcx = c_b.x - c_a.x;
	int dcy = c_b.y - c_a.y;
	float d = (sqrt(dx * dx + dy * dy) / 2) + (sqrt(dcx * dcx + dcy * dcy) / 2);
	int n = round(d / BEZIER_RES);
//	if (n < 12)
//		n = 12;
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

	result.x = round((ax * tCubed) + (bx * tSquared) + (cx * t) + a.x);
	result.y = round((ay * tCubed) + (by * tSquared) + (cy * t) + a.y);

	return result;
}

BezierPath::BezierPath(BezierCurve * curve) {
	__closed = false;
	__curves.push_back(curve);
	__computeBBox();

	__initVertex();
}

BezierPath::BezierPath(SDL_Point a, SDL_Point c_a, SDL_Point c_b, SDL_Point b) {
	__closed = false;
	__curves.push_back(new BezierCurve(a, c_a, c_b, b));
	__computeBBox();

	__initVertex();

}

BezierPath::BezierPath(SDL_Point a, SDL_Point c, SDL_Point b) {
	__closed = false;
	__curves.push_back(new BezierCurve(a, c, b));
	__computeBBox();

	__initVertex();
}

BezierPath::BezierPath(SDL_Point center, int rx,int ry){

	int dry=round(ry*4.0*(sqrt(2)-1)/3.0);
	int drx=round(rx*4.0*(sqrt(2)-1)/3.0);

	__closed=false;
	SDL_Point a,b,c_a,c_b;
	a=b=c_a=c_b=center;
	a.y-=ry;
	c_a.x+=drx;
	c_a.y-=ry;
	b.x+=rx;
	c_b.x+=rx;
	c_b.y-=dry;
	__curves.push_back(new BezierCurve(a,c_a,c_b,b));
	__computeBBox();
	__initVertex();
	c_a=b;
	c_a.y+=dry;
	c_b.x=center.x+drx;
	c_b.y=center.y+ry;
	b=center;
	b.y+=ry;
	addCurve(c_a,c_b,b);
	c_a=b;
	c_a.x-=drx;
	c_b.x=center.x-rx;
	c_b.y=center.y+dry;
	b=center;
	b.x-=rx;
	addCurve(c_a,c_b,b);
	c_a=b;
	c_a.y-=dry;
	c_b=center;
	c_b.y-=ry;
	c_b.x-=drx;
	closeCurve(c_a,c_b);
}


BezierPath::BezierPath(SDL_Point center, int r){
	int dr=round(r*4.0*(sqrt(2)-1)/3.0);

	__closed=false;
	SDL_Point a,b,c_a,c_b;
	a=b=c_a=c_b=center;
	a.y-=r;
	c_a.x+=dr;
	c_a.y-=r;
	b.x+=r;
	c_b.x+=r;
	c_b.y-=dr;
	__curves.push_back(new BezierCurve(a,c_a,c_b,b));
	__computeBBox();
	__initVertex();
	c_a=b;
	c_a.y+=dr;
	c_b.x=center.x+dr;
	c_b.y=center.y+r;
	b=center;
	b.y+=r;
	addCurve(c_a,c_b,b);
	c_a=b;
	c_a.x-=dr;
	c_b.x=center.x-r;
	c_b.y=center.y+dr;
	b=center;
	b.x-=r;
	addCurve(c_a,c_b,b);
	c_a=b;
	c_a.y-=dr;
	c_b=center;
	c_b.y-=r;
	c_b.x-=dr;
	closeCurve(c_a,c_b);
}

BezierPath::~BezierPath() {
	for (int i = 0; i < __curves.size(); i++) {
		delete __curves[i];
	}
	__curves.clear();
}

bool BezierPath::contains(SDL_Point p) {
	return contains(p.x, p.y);
}

bool BezierPath::contains(int x, int y) {
	int nvert = vertexCount();
	Sint16 * vertx = vx();
	Sint16 * verty = vy();
	int i, j, c = 0;
#pragma omp parallel for
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((verty[i] > y) != (verty[j] > y))
				&& (x
						< (vertx[j] - vertx[i]) * (y - verty[i])
								/ (verty[j] - verty[i]) + vertx[i]))
			c = !c;
	}
	return c;
}

Shape * BezierPath::transform(Transformation t) {
	return transformBezierPath(t);
}

BezierPath * BezierPath::transformBezierPath(Transformation t) {

	SDL_Point a, c_a, c_b, b;
	a = __curves.front()->getPointA();
	b = __curves.front()->getPointB();
	c_a = __curves.front()->getControlPointA();
	c_b = __curves.front()->getControlPointB();
	t.applyTransformation(a);
	t.applyTransformation(c_a);
	t.applyTransformation(c_b);
	t.applyTransformation(b);
	BezierPath *bp = new BezierPath(a, c_a, c_b, b);

	for (int i = 1; i < __curves.size(); i++) {
		c_a = __curves[i]->getControlPointA();
		c_b = __curves[i]->getControlPointB();
		b = __curves[i]->getPointB();
		t.applyTransformation(c_a);
		t.applyTransformation(c_b);
		t.applyTransformation(b);
		bp->addCurve(c_a, c_b, b);
	}

	return bp;
}

bool BezierPath::isClosed() {
	return __closed;
}

void BezierPath::addCurve(SDL_Point c_a, SDL_Point c_b, SDL_Point b) {
	SDL_Point a = __curves.back()->getPointB();
	__curves.push_back(new BezierCurve(a, c_a, c_b, b));
	if (b.x == __curves.front()->getPointA().x
			&& b.y == __curves.front()->getPointA().y)
		__closed = true;
	__computeBBox();
	__initVertex();
}

void BezierPath::addCurve(SDL_Point c, SDL_Point b) {
	this->addCurve(c, c, b);
}

void BezierPath::closeCurve(SDL_Point c_a, SDL_Point c_b) {
	SDL_Point a = __curves.back()->getPointB();
	SDL_Point b = __curves.front()->getPointA();
	__curves.push_back(new BezierCurve(a, c_a, c_b, b));
	__closed = true;
	__computeBBox();
	__initVertex();
}

void BezierPath::closeCurve(SDL_Point c) {
	this->closeCurve(c, c);
}

void BezierPath::closeCurve() {
	SDL_Point a = __curves.back()->getPointB();
	SDL_Point b = __curves.front()->getPointA();
	__curves.push_back(new BezierCurve(a, a, b, b));
	__closed = true;
	__computeBBox();
	__initVertex();
}

std::vector<BezierCurve *> BezierPath::getCurves() {
	return __curves;
}

std::vector<SDL_Point> BezierPath::vertex() {
	std::vector<SDL_Point> ver;
	for (int i = 0; i < __vertexCount; i++) {
		ver.push_back((SDL_Point ) { __vx[i], __vy[i] });
	}
	return ver;
}

std::vector<Line> BezierPath::getLines() {
	std::vector<Line> lines;
	for (int i = 0; i < __curves.size(); i++) {
		for (int j = 0; j < __curves[i]->getLines().size(); j++) {
			lines.push_back(__curves[i]->getLines()[j]);
		}
	}
	return lines;
}

Sint16 * BezierPath::vx() {
	return __vx;
}

Sint16 * BezierPath::vy() {
	return __vy;
}

int BezierPath::vertexCount() {
	return __vertexCount;
}

void BezierPath::__computeBBox() {
	SDL_Rect bb = __curves[0]->getBoundingBox();
	SDL_Rect bbi;
	for (int i = 1; i < __curves.size(); i++) {
		bbi = __curves[i]->getBoundingBox();
		if (bb.x > bbi.x) {
			bb.w += bb.x - bbi.x;
			bb.x = bbi.x;
		}
		if (bb.y > bbi.y) {
			bb.h += bb.y - bbi.y;
			bb.y = bbi.y;
		}
		if (bb.w < abs(bbi.x - bb.x) + bbi.w) {
			bb.w = abs(bbi.x - bb.x) + bbi.w;
		}
		if (bb.h < abs(bbi.y - bb.y) + bbi.h) {
			bb.h = abs(bbi.y - bb.y) + bbi.h;
		}

	}
	boundingBox_ = bb;
}

void BezierPath::__initVertex() {

	__vertexCount = 0;
	for (int i = 0; i < __curves.size(); i++) {
		__vertexCount += __curves[i]->vertex().size();
	}
	__vx = new Sint16[__vertexCount];
	__vy = new Sint16[__vertexCount];
	int c = 0;
	for (int i = 0; i < __curves.size(); i++) {
		for (int j = 0; j < __curves[i]->vertex().size(); j++) {
			__vy[c] = __curves[i]->vertex()[j].y;
			__vx[c] = __curves[i]->vertex()[j].x;
			c++;
		}
	}
}
