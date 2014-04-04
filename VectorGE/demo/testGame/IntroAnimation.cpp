/*
 * IntroAnimation.cpp
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#include "IntroAnimation.h"

#include <iostream>

IntroAnimation::IntroAnimation(StateListener * listener, SDL_Rect display) :
		State(listener) {
	image = new Image("./resources/icons/vector.png");
	bounds_.w = image->getSize().width-20;
	bounds_.h = image->getSize().height-20;
	bounds_.x = (display.w - bounds_.w) / 2;
	bounds_.y = (display.h - bounds_.h) / 2;
	opacity_ = 0.0;
	EntityStatus end=this->getCurrentStatus();
	EntityStatus middle = this->getCurrentStatus();
	middle.opacity = 1.0;
	middle.bounds.x -= 10;
	middle.bounds.y -= 10;
	middle.bounds.w += 20;
	middle.bounds.h += 20;

	animation = new Animation(this->getCurrentStatus(), end, 1200);
	animation->addStep(0.4, middle);
	animation->addStep(0.8,middle);
}

IntroAnimation::~IntroAnimation() {
	delete animation;
	delete image;
}

void IntroAnimation::render(Painter * p) {
	Uint8 val = 255 * opacity_;

	p->setColors(Color(69, 70, 64));
	p->paintRect(0, 0, p->getDisplaySize().width, p->getDisplaySize().height);

	if (val > 255)
		val = 255;
	p->paintImage(*image, bounds_, val);
}
void IntroAnimation::step(double dt) {
	setCurrentStatus(animation->step(dt));
	if (animation->isEnded() && listener_ != 0) {
		std::cout << "animation ended!\n";
		listener_->ended(0);
	}
}

