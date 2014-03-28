/*
 * AnimationFunction.cpp
 *
 *  Created on: 29/mar/2014
 *      Author: martino
 */

#include "AnimationFunction.h"
#include <math.h>

AnimationFunction::AnimationFunction() {
	// TODO Auto-generated constructor stub

}

AnimationFunction::~AnimationFunction() {
	// TODO Auto-generated destructor stub
}


int AnimationFunction::eval(int p1,int p2,float dt){
	return round(eval((float)p1,(float)p2,dt));
}
