/*
 * AnimationFunction.h
 *
 *  Created on: 29/mar/2014
 *      Author: martino
 */

#ifndef ANIMATIONFUNCTION_H_
#define ANIMATIONFUNCTION_H_

class AnimationFunction {
public:
	AnimationFunction();
	virtual ~AnimationFunction();
	virtual float eval(float p1, float p2, float dt)=0;
	virtual int eval(int p1,int p2,float dt);
};

#endif /* ANIMATIONFUNCTION_H_ */
