/*
 * Line.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef LINE_H_
#define LINE_H_
#include "Shape.h"



class Line: public Shape {
public:
	Line(SDL_Point p1,SDL_Point p2);
	Line(int x1,int y1,int x2,int y2);
	virtual ~Line();

	virtual bool contains(SDL_Point p);
	virtual bool contains(int x,int y);
	bool intersectLine(Line l);

	float lenght();
	SDL_Point p1();
	SDL_Point p2();

	virtual Shape * transform(Transformation t);
	Line * transformLine(Transformation t);

private:
	void computeBox();

	SDL_Point p1_;
	SDL_Point p2_;
};

#endif /* LINE_H_ */
