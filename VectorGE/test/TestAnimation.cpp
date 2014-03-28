/*
 * TestAnimation.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "TestAnimation.h"

TestAnimation::TestAnimation(SDL_Size display): GameEntity() {
	image = new Image("./resources/icons/vector.png");
	bounds_.w=image->getSize().width;
	bounds_.h=image->getSize().height;
	bounds_.x=(display.width-bounds_.w)/2;
	bounds_.y=(display.height-bounds_.h)/2;
	opacity_=0.0;

	EntityStatus end=this->getCurrentStatus();
	end.opacity=1.0;

	animation=new Animation(this->getCurrentStatus(),end,2000,REVERSELOOP);
}

TestAnimation::~TestAnimation() {
	// TODO Auto-generated destructor stub
}

void TestAnimation::render(Painter * p) {
	Uint8 val=255*opacity_;
	if (val>255)
		val=255;
	p->paintImage(*image,bounds_,val);
}
void TestAnimation::step(double dt) {
	setCurrentStatus(animation->step(dt));
}

