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
#include "SDLSize.h"

class Transformation: public Entity {
public:
	Transformation();
	Transformation(SDL_Point translation,double rotation,double scale);
	virtual ~Transformation();

	SDL_Point transform(SDL_Point p);

	void applyTransformation(SDL_Point &p);
	void applyTransformation(int &x,int &y);
	void applyTransformation(Sint16 &x,Sint16 &y);

	void applySizeTransformation(int &w,int &h);
	void applySizeTransformation(Uint16 &w,Uint16 &h);
	void applySizeTransformation(SDL_Size size);

	void translate(int x,int y);
	void translate(SDL_Point p);

	void scale(double f);

	SDL_Point getTransaltion();
	double getScale();

	Transformation * clone();

	void reset();
private:
	void applyTranslation(SDL_Point &p);
	void applyScale(SDL_Point &p);

	SDL_Point translation_;
	double rotation_;
	double scale_;
};

#endif /* TRANSFORMATION_H_ */
