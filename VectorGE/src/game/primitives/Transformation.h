/*
 * Transformation.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include <SDL2/SDL.h>
#include "../../core/Entity.h"

class Transformation: public Entity {
public:
	Transformation();
	virtual ~Transformation();

	SDL_Point applyTransformation(SDL_Point p);
	SDL_Point applyTransformation(int x,int y);

	void translate(int x,int y);
	void translate(SDL_Point p);

	SDL_Point getTransaltion();
private:
	SDL_Point applyTranslation(SDL_Point p);

	SDL_Point translation_;
	double rotation_;
};

#endif /* TRANSFORMATION_H_ */
