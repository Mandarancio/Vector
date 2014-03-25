/*
 * Line.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef LINE_H_
#define LINE_H_

#include "../../../core/Entity.h"
#include <SDL2/SDL.h>

class Line: public Entity {
public:
	Line(SDL_Point p1,SDL_Point p2);
	Line(int x1,int y1,int x2,int y2);
	virtual ~Line();

	bool pointOnLine(SDL_Point p);
	bool intersectLine(Line l);

	SDL_Rect getBoundingBox();
private:
	void computeBox();

	SDL_Point p1_;
	SDL_Point p2_;

	SDL_Rect boundingBox_;
};

#endif /* LINE_H_ */
