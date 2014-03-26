/*
 * Polygon.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"
#include "Line.h"
#include <vector>

class Polygon: public Shape {
public:
	Polygon();
	Polygon(SDL_Point * vertex);
	Polygon(std::vector<SDL_Point> vertex);


	virtual ~Polygon();

	void addVertex(SDL_Point vertex);
	void addVertex(int x,int y);

	virtual bool contains(SDL_Point p);
	virtual bool contains(int x,int y);

	virtual Shape * transform(Transformation t);
	Polygon *transformPolygon(Transformation t);

	std::vector<Line> lines();
	std::vector<SDL_Point> vertex();

	Sint16 * vx();
	Sint16 * vy();
private:
	void computeBox();

	std::vector<SDL_Point> vertex_;
	std::vector<Line> lines_;

};

#endif /* POLYGON_H_ */
