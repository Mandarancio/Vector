/*
 * LinearAnimationFunction.h
 *
 *  Created on: 29/mar/2014
 *      Author: martino
 */

#ifndef LINEARANIMATIONFUNCTION_H_
#define LINEARANIMATIONFUNCTION_H_

#include "AnimationFunction.h"

class LinearAnimationFunction: public AnimationFunction {
public:
	LinearAnimationFunction();
	virtual ~LinearAnimationFunction();

	virtual float eval(float p1, float p2, float dt);
};

#endif /* LINEARANIMATIONFUNCTION_H_ */
