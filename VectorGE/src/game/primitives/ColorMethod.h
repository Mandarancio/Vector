/*
 * ColorMethod.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef COLORMETHOD_H_
#define COLORMETHOD_H_

#include "../../core/Entity.h"
#include "Color.h"

class ColorMethod: public Entity {
public:
	ColorMethod();
	virtual ~ColorMethod();
	virtual Color colorAt(SDL_Point p)=0;
	virtual Color colorAt(int x,int y)=0;

};

#endif /* COLORMETHOD_H_ */
