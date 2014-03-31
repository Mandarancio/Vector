/*
 * TestAnimation.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "TestAnimation.h"
#include "../src/game/primitives/geometry/BezierPath.h"

TestAnimation::TestAnimation(SDL_Size display): GameEntity() {
	image = new Image("./resources/icons/vector.png");
	bounds_.w=image->getSize().width;
	bounds_.h=image->getSize().height;
	bounds_.x=(display.width-bounds_.w)/2;
	bounds_.y=(display.height-bounds_.h)/2;
	opacity_=0.0;

	EntityStatus end=this->getCurrentStatus();
	EntityStatus middle=this->getCurrentStatus();
	middle.opacity=1.0;
	middle.bounds.x+=10;
	middle.bounds.y+=10;
	middle.bounds.w-=20;
	middle.bounds.h-=20;

	animation=new Animation(this->getCurrentStatus(),end,2000,REVERSELOOP);
	animation->addStep(0.6,middle);
	animation->addStep(0.4,middle);
}

TestAnimation::~TestAnimation() {
	// TODO Auto-generated destructor stub
}

void TestAnimation::render(Painter * p) {
//	SDL_Point a,b,c_a,c_b;
//	a.x=100;
//	a.y=100;
//	c_a.x=150;
//	c_a.y=100;
//	c_b.y=200;
//	c_b.x=200;
//	b.x=250;
//	b.y=200;
//
//	p->setPen(Color());
//	p->setFill(Color());
//	p->paintBezierCourve(new BezierCurve(a,c_a,c_b,b));
//	p->paintRect(a.x-3,a.y-3,6,6);
//	p->paintRect(b.x-3,b.y-3,6,6);
//
//	p->paintLine(a.x,a.y,c_a.x,c_a.y);
//	p->paintLine(b.x,b.y,c_b.x,c_b.y);
//
//
//	p->paintRect(c_a.x-3,c_a.y-3,6,6);
//	p->paintRect(c_b.x-3,c_b.y-3,6,6);

	Uint8 val=255*opacity_;
	if (val>255)
		val=255;
	p->paintImage(*image,bounds_,val);
}
void TestAnimation::step(double dt) {
	setCurrentStatus(animation->step(dt));
}

