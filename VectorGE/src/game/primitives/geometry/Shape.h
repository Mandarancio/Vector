/*
 * Shape.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "../../../core/Entity.h"
#include "../Transformation.h"
#include <SDL2/SDL.h>


class Shape {
public:
	Shape();
	virtual ~Shape();
	virtual bool contains(SDL_Point p)=0;
	virtual bool contains(int x,int y)=0;
	virtual Shape * transform(Transformation t)=0;
	SDL_Rect getBoundingBox();
protected:
	SDL_Rect boundingBox_;
};

#endif /* SHAPE_H_ */
