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
	virtual ~BezierCurve();
	virtual bool contains(SDL_Point p);
	virtual bool contains(int x, int y);
	virtual Shape * transform(Transformation t);

	SDL_Point getPointA();
	SDL_Point getPointB();
	SDL_Point getControlPointA();
	SDL_Point getControlPointB();

	std::vector<SDL_Point> getPoints();
	std::vector<Line> getLines();

private:
	void __initLines();
	SDL_Point __computePoint(float t);
	SDL_Point a, b, c_a, c_b;
	std::vector<Line> __lines;
	std::vector<SDL_Point> __points;
};

class BezierPath: public Shape {
	BezierPath();
	virtual ~BezierPath();
	virtual bool contains(SDL_Point p);
	virtual bool contains(int x, int y);
	virtual Shape * transform(Transformation t);
private:

	std::vector<BezierCurve *> __curves;
	bool __closed;

};

#endif /* BEZIERPATH_H_ */
