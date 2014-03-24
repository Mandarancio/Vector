/*
 * Color.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Color.h"

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) :
		red_(r), green_(g), blue_(b), alpha_(a) {

}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

Uint32 Color::getARGB(){
	return alpha_|red_>8|green_>16|blue_>24;
}
Uint8 Color::red(){
	return red_;
}
Uint8 Color::green(){
	return green_;
}
Uint8 Color::blue(){
	return blue_;
}
Uint8 Color::alpha(){
	return alpha_;
}
