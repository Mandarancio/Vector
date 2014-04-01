/*
 * TestAnimation.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "TestAnimation.h"

#include <iostream>

TestAnimation::TestAnimation(SDL_Size display) :
		GameEntity() {
	image = new Image("./resources/icons/vector.png");
	bounds_.w = image->getSize().width;
	bounds_.h = image->getSize().height;
	bounds_.x = (display.width - bounds_.w) / 2;
	bounds_.y = (display.height - bounds_.h) / 2;
	opacity_ = 0.0;

	EntityStatus end = this->getCurrentStatus();
	EntityStatus middle = this->getCurrentStatus();
	middle.opacity = 1.0;
	middle.bounds.x += 10;
	middle.bounds.y += 10;
	middle.bounds.w -= 20;
	middle.bounds.h -= 20;

	animation = new Animation(this->getCurrentStatus(), end, 2000, REVERSELOOP);
	animation->addStep(0.6, middle);
	animation->addStep(0.4, middle);

	path = new BezierPath((SDL_Point ) { 100, 100 }, 50);
	SDL_Point *arr =new SDL_Point[4];
	arr[0]=(SDL_Point){100,200};
	arr[1]=(SDL_Point){150,250};
	arr[2]=(SDL_Point){100,300};
	arr[3]=(SDL_Point){50,250};
	pol=new Polygon(arr,4);
}

TestAnimation::~TestAnimation() {
	delete pol;
	delete path;
	delete image;
}

void TestAnimation::render(Painter * p) {

	p->setPen(Color());
	p->setFill(Color(100,100,100));
	p->paintBezierPath(path);
	p->paintPolygon(*pol);

	Uint8 val = 255 * opacity_;
	if (val > 255)
		val = 255;
	p->paintImage(*image, bounds_, val);
}
void TestAnimation::step(double dt) {
	setCurrentStatus(animation->step(dt));
}

