/*
 * TestAnimation.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef TESTANIMATION_H_
#define TESTANIMATION_H_

#include "../src/game/GameEntity.h"
#include "../src/core/stateMachine/StateMachine.h"

class TestAnimation : public GameEntity{
public:
	TestAnimation();
	virtual ~TestAnimation();
	virtual void render(Painter * p);
	virtual void step(double dt,SDL_Event event);
};

#endif /* TESTANIMATION_H_ */
