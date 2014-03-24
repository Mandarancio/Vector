/*
 * Color.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <SDL2/SDL.h>
class Color {
public:
	Color(Uint8 r,Uint8 g,Uint8 b,Uint8 a);
	virtual ~Color();
	Uint32 getARGB();
	Uint32 getRGBA();
	SDL_Color getSDLColor();
	Uint8 red();
	Uint8 green();
	Uint8 blue();
	Uint8 alpha();
private:
	SDL_Color color;
};

#endif /* COLOR_H_ */
