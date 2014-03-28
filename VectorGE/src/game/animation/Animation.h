/*
 * Animation.h
 *
 *  Created on: Mar 28, 2014
 *      Author: martino
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "../GameEntity.h"

#include <map>

enum LoopMode{
	NOLOOP, RESTARTLOOP, REVERSELOOP
};

class Animation {
public:
	Animation(EntityStatus startStatus,EntityStatus endStatus,double duration,LoopMode loop=NOLOOP);
	virtual ~Animation();

	void addStep(float at, EntityStatus step);

	EntityStatus step(float dt);

private:
	void _nextStep();

	double duration_;
	LoopMode loop_;

	std::map<float,EntityStatus> steps_;

	float __time;
	EntityStatus __currentStatus;
	float __currentTime;
	EntityStatus __nextStatus;
	float __nextTime;
};

#endif /* ANIMATION_H_ */
