/*
 * Color.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Color.h"

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
		{
	color.r=r;
	color.g=g;
	color.b=b;
	color.a=a;
}

Color::~Color() {
}

Uint32 Color::getARGB(){
	return (color.a)|(color.r>8)|(color.g>16)|(color.b>24);
}
Uint32 Color::getRGBA(){
	return (color.r)|(color.g>8)|(color.b>16)|(color.a>24);
}
SDL_Color Color::getSDLColor(){
	return color;
}
Uint8 Color::red(){
	return color.r;
}
Uint8 Color::green(){
	return color.g;
}
Uint8 Color::blue(){
	return color.b;
}
Uint8 Color::alpha(){
	return color.a;
}

Color Color::darker(){
	return Color(color.r-10,color.g-10,color.b-10,color.a);
}

Color Color::brighter(){
	return Color(color.r+10,color.g+10,color.b+10,color.a);
}
