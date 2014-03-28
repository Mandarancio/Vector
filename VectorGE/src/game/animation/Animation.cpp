/*
 * Animation.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: martino
 */

#include "Animation.h"

Animation::Animation(EntityStatus startStatus, EntityStatus endStatus,
		double duration, LoopMode loop) {
	duration_ = duration;
	loop_ = loop;
	__time = 0;
	steps_[0.0] = startStatus;
	steps_[1.0] = endStatus;
	__currentStatus=startStatus;
	__nextStatus=endStatus;
	__currentTime=0.0;
	__nextTime=duration;
}

Animation::~Animation() {
}

void Animation::addStep(float at, EntityStatus step) {
	steps_[at] = step;
	if (at*duration_<__nextTime){
		__nextStatus=step;
		__nextTime=at*duration_;
	}
}

EntityStatus Animation::step(float dt) {
	if (__time<=0)
		return steps_[0.0];
	if (__time>=duration_ && loop_==NOLOOP)
		return steps_[1.0];

	__time+=dt;

	if (__time>__nextTime){
		__currentTime=__nextTime;
		_nextStep();
	}

	float dx=(__time-__currentTime)/(__nextTime-__currentTime);

	SDL_Rect r;
	r.x=__currentStatus.bounds.x*(1-dx)+__nextStatus.bounds.x*dx;
	r.y=__currentStatus.bounds.y*(1-dx)+__nextStatus.bounds.y*dx;
	r.w=__currentStatus.bounds.w*(1-dx)+__nextStatus.bounds.w*dx;
	r.h=__currentStatus.bounds.h*(1-dx)+__nextStatus.bounds.h*dx;
	float opacity =__currentStatus.opacity*(1-dx)+__nextStatus.opacity*dx;
	float angle = __currentStatus.angle*(1-dx)+__nextStatus.angle*dx;
	float scale= __currentStatus.scale*(1-dx)+__nextStatus.scale*dx;

	EntityStatus status;
	status.bounds=r;
	status.angle=angle;
	status.opacity=opacity;
	status.scale=scale;

	return status;
}

void Animation::_nextStep(){
	__nextTime=steps_.upper_bound(__currentTime)->first;
	__nextStatus=steps_.upper_bound(__currentTime)->second;
}
