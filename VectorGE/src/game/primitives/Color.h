/*
 * Color.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <SDL2/SDL.h>
#include "../../core/Entity.h"

class Color: public Entity {
public:
	Color(Uint8 r=0,Uint8 g=0,Uint8 b=0,Uint8 a=255);
	virtual ~Color();
	Uint32 getARGB();
	Uint32 getRGBA();
	SDL_Color getSDLColor();
	Uint8 red();
	Uint8 green();
	Uint8 blue();
	Uint8 alpha();

	Color darker();
	Color brighter();
private:
	SDL_Color color;
};

#endif /* COLOR_H_ */
