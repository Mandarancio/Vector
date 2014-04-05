/*
 * Rectangle.h
 *
 *  Created on: 06/apr/2014
 *      Author: martino
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {
public:
	Rectangle(int x,int y, int w,int h);
	Rectangle(SDL_Rect rect);
	virtual ~Rectangle();
	virtual bool contains(SDL_Point p);
	virtual bool contains(int x, int y);
	virtual Shape * transform(Transformation t);

};

#endif /* RECTANGLE_H_ */
