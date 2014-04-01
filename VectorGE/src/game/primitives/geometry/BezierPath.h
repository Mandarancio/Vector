/*
 * BezierPath.h
 *
 *  Created on: Mar 31, 2014
 *      Author: martino
 */

#ifndef BEZIERPATH_H_
#define BEZIERPATH_H_

#include "Shape.h"
#include "Line.h"

#include <vector>

class BezierCurve: public Shape {
public:
	BezierCurve(SDL_Point a, SDL_Point c_a, SDL_Point c_b, SDL_Point b);
	BezierCurve(SDL_Point a, SDL_Point c, SDL_Point b);

	virtual ~BezierCurve();
	virtual bool contains(SDL_Point p);
	virtual bool contains(int x, int y);
	virtual Shape * transform(Transformation t);
	BezierCurve * transformBezierCurve(Transformation t);

	SDL_Point getPointA();
	SDL_Point getPointB();
	SDL_Point getControlPointA();
	SDL_Point getControlPointB();

	std::vector<SDL_Point> vertex();
	std::vector<Line> getLines();

private:
	void __computeBBox();
	void __initLines();
	SDL_Point __computePoint(float t);
	SDL_Point a, b, c_a, c_b;
	std::vector<Line> __lines;
	std::vector<SDL_Point> __points;
};

class BezierPath: public Shape {
public:
	BezierPath(BezierCurve * curve);
	BezierPath(SDL_Point a, SDL_Point c_a, SDL_Point c_b, SDL_Point b);
	BezierPath(SDL_Point a, SDL_Point c, SDL_Point b);

	virtual ~BezierPath();
	virtual bool contains(SDL_Point p);
	virtual bool contains(int x, int y);
	virtual Shape * transform(Transformation t);
	BezierPath * transformBezierPath(Transformation t);

	bool isClosed();

	void addCurve(SDL_Point c_a, SDL_Point c_b, SDL_Point b);
	void addCurve(SDL_Point c, SDL_Point b);

	void closeCurve(SDL_Point c_a, SDL_Point c_b);
	void closeCurve(SDL_Point c);

	void closeCurve();


	std::vector<BezierCurve *> getCurves();
	std::vector<SDL_Point> vertex();
	std::vector<Line> getLines();
	Sint16 * vx();
	Sint16 * vy();

	int vertexCount();
private:
	void __computeBBox();
	void __initVertex();

	std::vector<BezierCurve *> __curves;
	bool __closed;
	Sint16 * __vx,*__vy;
	int __vertexCount;
};

#endif /* BEZIERPATH_H_ */
