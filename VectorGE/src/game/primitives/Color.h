/*
 * Color.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <SDL/SDL.h>
class Color {
public:
	Color(Uint8 r,Uint8 g,Uint8 b,Uint8 a);
	virtual ~Color();
	Uint32 getARGB();
	Uint8 red();
	Uint8 green();
	Uint8 blue();
	Uint8 alpha();
private:
	Uint8 red_;
	Uint8 green_;
	Uint8 blue_;
	Uint8 alpha_;
};

#endif /* COLOR_H_ */
