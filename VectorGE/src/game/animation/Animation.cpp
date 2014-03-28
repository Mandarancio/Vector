/*
 * Animation.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: martino
 */

#include "Animation.h"

#include <iostream>

Animation::Animation(EntityStatus startStatus, EntityStatus endStatus,
		double duration, LoopMode loop) {
	duration_ = duration;
	loop_ = loop;
	__time = 0;
	steps_[0.0] = startStatus;
	steps_[1.0] = endStatus;
	__currentStatus = startStatus;
	__nextStatus = endStatus;
	__currentTime = 0.0;
	__nextTime = duration;
	__reverseFlag = false;
}

Animation::~Animation() {
}

void Animation::addStep(float at, EntityStatus step) {
	steps_[at] = step;
	if (at * duration_ < __nextTime) {
		__nextStatus = step;
		__nextTime = at * duration_;
	}
}

EntityStatus Animation::step(float dt) {
	if (dt > 0) {
		if (__reverseFlag) {
			__time -= dt;

		} else {
			__time += dt;
		}
	}
	if (__time <= 0) {
		__time = 0;
		if (__reverseFlag) {
			__reverseFlag = false;
			__currentStatus = steps_[0.0];
			__currentTime = 0.0;
			_nextStep();
			return __currentStatus;
		}
	}

	if (__time >= duration_) {
		if (loop_ == NOLOOP) {
			return steps_[1.0];
		} else if (loop_ == RESTARTLOOP) {
			__time = 0;
			__currentStatus = steps_[0.0];
			__currentTime = 0.0;
			_nextStep();
			return __currentStatus;
		} else if (loop_ == REVERSELOOP) {
			__currentStatus = __nextStatus;
			__currentTime=duration_;
			__time = duration_;
			__reverseFlag = true;
			_prevStep();
			return __currentStatus;
		}
	}

	if (__time > __nextTime && !__reverseFlag) {
		__currentTime = __nextTime;
		_nextStep();
	}
	else if (__time<__nextTime && __reverseFlag){
		__currentTime = __nextTime;
		_prevStep();
	}

	float dx=(__time - __currentTime) / (__nextTime - __currentTime);
	SDL_Rect r;
	r.x = round(
			__currentStatus.bounds.x * (1.0 - dx) + __nextStatus.bounds.x * dx);
	r.y = round(
			__currentStatus.bounds.y * (1.0 - dx) + __nextStatus.bounds.y * dx);
	r.w = round(
			__currentStatus.bounds.w * (1.0 - dx) + __nextStatus.bounds.w * dx);
	r.h = round(
			__currentStatus.bounds.h * (1.0 - dx) + __nextStatus.bounds.h * dx);
	float opacity = __currentStatus.opacity * (1.0 - dx)
			+ __nextStatus.opacity * dx;
	float angle = round(
			__currentStatus.angle * (1.0 - dx) + __nextStatus.angle * dx);
	float scale = round(
			__currentStatus.scale * (1.0 - dx) + __nextStatus.scale * dx);

	EntityStatus status;
	status.bounds = r;
	status.angle = angle;
	status.opacity = opacity;
	status.scale = scale;

	return status;
}

void Animation::_nextStep() {
	float t=__currentTime/duration_;
	__nextTime = steps_.upper_bound(t)->first * duration_;
	__nextStatus = steps_.upper_bound(t)->second;
}

void Animation::_prevStep(){
	float t=__currentTime/duration_;
	std::map<float,EntityStatus>::iterator iter=steps_.lower_bound(t);
	if (iter!=steps_.begin()){
		iter--;

	}
	__nextTime=iter->first;
	__nextStatus=iter->second;
}
