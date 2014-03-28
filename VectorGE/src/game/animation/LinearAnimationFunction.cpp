/*
 * LinearAnimationFunction.cpp
 *
 *  Created on: 29/mar/2014
 *      Author: martino
 */

#include "LinearAnimationFunction.h"

LinearAnimationFunction::LinearAnimationFunction() {
	// TODO Auto-generated constructor stub

}

LinearAnimationFunction::~LinearAnimationFunction() {
	// TODO Auto-generated destructor stub
}

float LinearAnimationFunction::eval(float p1, float p2, float dt){
	return p1*(1.0-dt)+p2*dt;
}
