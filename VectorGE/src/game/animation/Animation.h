/*
 * Animation.h
 *
 *  Created on: Mar 28, 2014
 *      Author: martino
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "../GameEntity.h"
#include "AnimationFunction.h"
#include <map>

enum LoopMode{
	NOLOOP, RESTARTLOOP, REVERSELOOP
};

class Animation {
public:
	Animation(EntityStatus startStatus,EntityStatus endStatus,double duration,LoopMode loop=NOLOOP);
	Animation(EntityStatus startStatus,AnimationFunction * s_function,EntityStatus endStatus,AnimationFunction * e_function,double duration,LoopMode loop=NOLOOP);

	virtual ~Animation();

	void addStep(float at, EntityStatus step);
	void addStep(float at, EntityStatus step, AnimationFunction* function);


	EntityStatus step(float dt);
	bool isEnded();

private:
	void _nextStep();
	void _prevStep();

	double duration_;
	LoopMode loop_;

	std::map<float,EntityStatus> steps_;
	std::map<float,AnimationFunction*> functions_;

	float __time;
	EntityStatus __currentStatus;
	float __currentTime;
	EntityStatus __nextStatus;
	float __nextTime;

	bool __reverseFlag;
};

#endif /* ANIMATION_H_ */
