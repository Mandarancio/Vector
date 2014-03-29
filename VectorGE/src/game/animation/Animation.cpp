/*
 * Animation.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: martino
 */

#include "Animation.h"
#include "LinearAnimationFunction.h"

#include <iostream>

Animation::Animation(EntityStatus startStatus, EntityStatus endStatus,
		double duration, LoopMode loop) {
	duration_ = duration;
	loop_ = loop;
	__time = 0;
	steps_[0.0] = startStatus;
	steps_[1.0] = endStatus;

	functions_[0.0] = new LinearAnimationFunction();
	functions_[1.0] = new LinearAnimationFunction();

	__currentStatus = startStatus;
	__nextStatus = endStatus;
	__currentTime = 0.0;
	__nextTime = duration;
	__reverseFlag = false;
}

Animation::Animation(EntityStatus startStatus, AnimationFunction * s_function,
		EntityStatus endStatus,AnimationFunction * e_function, double duration, LoopMode loop) {
	duration_ = duration;
	loop_ = loop;
	__time = 0;
	steps_[0.0] = startStatus;
	steps_[1.0] = endStatus;

	functions_[0.0] = s_function;
	functions_[1.0] = e_function;

	__currentStatus = startStatus;
	__nextStatus = endStatus;
	__currentTime = 0.0;
	__nextTime = duration;
	__reverseFlag = false;
}

Animation::~Animation() {
}

void Animation::addStep(float at, EntityStatus step) {
	addStep(at, step, new LinearAnimationFunction());
}
void Animation::addStep(float at, EntityStatus step,
		AnimationFunction* function) {
	steps_[at] = step;
	if (at * duration_ < __nextTime) {
		__nextStatus = step;
		__nextTime = at * duration_;
	}
	functions_[at] = function;
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
			__currentTime = duration_;
			__time = duration_;
			__reverseFlag = true;
			_prevStep();
			return __currentStatus;
		}
	}

	if (__time > __nextTime && !__reverseFlag) {
		__currentTime = __nextTime;
		__currentStatus=__nextStatus;
		_nextStep();
	} else if (__time < __nextTime && __reverseFlag) {
		__currentTime = __nextTime;
		__currentStatus=__nextStatus;

		_prevStep();
	}
	AnimationFunction * f = functions_[__currentTime/duration_];
	if (!f) {
		std::cout << "ERROR! Function["<<__currentTime<<"] null!\n";
		return __currentStatus;
	}
	float dx = (__time - __currentTime) / (__nextTime - __currentTime);
	SDL_Rect r;
	r.x = f->eval(__currentStatus.bounds.x, __nextStatus.bounds.x, dx);
	r.y = f->eval(__currentStatus.bounds.y, __nextStatus.bounds.y, dx);
	r.w = f->eval(__currentStatus.bounds.w, __nextStatus.bounds.w, dx);
	r.h = f->eval(__currentStatus.bounds.h, __nextStatus.bounds.h, dx);
	float opacity = f->eval(__currentStatus.opacity, __nextStatus.opacity, dx);
	float angle = f->eval(__currentStatus.angle, __nextStatus.angle, dx);
	float scale = f->eval(__currentStatus.scale, __nextStatus.scale, dx);

	EntityStatus status;
	status.bounds = r;
	status.angle = angle;
	status.opacity = opacity;
	status.scale = scale;

	return status;
}

void Animation::_nextStep() {
	float t = __currentTime / duration_;
	__nextTime = steps_.upper_bound(t)->first * duration_;
	__nextStatus = steps_.upper_bound(t)->second;

}

void Animation::_prevStep() {
	float t = __currentTime / duration_;
	std::map<float, EntityStatus>::iterator iter = steps_.lower_bound(t);
	if (iter != steps_.begin()) {
		iter--;

	}
	__nextTime = iter->first*duration_;
	__nextStatus = iter->second;


}
