/*
 * Armature.cpp
 *
 *  Created on: 30/mar/2014
 *      Author: martino
 */

#include "Armature.h"

#include <iostream>

#define DEBUG true

ArmaturePoint::ArmaturePoint(SDL_Point pos) {
	__mouseDown = false;
	bounds_.x = pos.x - 5;
	bounds_.y = pos.y - 5;
	bounds_.w = 10;
	bounds_.h = 10;
}

ArmaturePoint::~ArmaturePoint() {
	// TODO Auto-generated destructor stub
}

void ArmaturePoint::render(Painter* p) {
#if DEBUG
	if (__mouseDown) {
		p->setPen(Color(0, 255, 0));
	} else {
		p->setPen(Color());
	}
	p->setFill(p->getPen());
	p->paintRect(bounds_);
#endif
}

void ArmaturePoint::mouseMotion(SDL_MouseMotionEvent *e) {
	if (__mouseDown) {
		int dx = (e->x - 5) - bounds_.x;
		int dy = (e->y - 5) - bounds_.y;

		bounds_.x += dx;
		bounds_.y += dy;

		_updateLinkedEntities(dx, dy);
	}
}
void ArmaturePoint::mouseButtonDown(SDL_MouseButtonEvent *e) {

	if (abs(e->x - 5 - getX()) < 5 && abs(e->y - 5 - getY()) < 5) {
		__mouseDown = true;
	}
}
void ArmaturePoint::mouseButtonUp(SDL_MouseButtonEvent *e) {
	__mouseDown = false;
}

void ArmaturePoint::addLinkedEntity(GameEntity * ge) {
	linkedEntities_.push_back(ge);
}

void ArmaturePoint::_updateLinkedEntities(int dx, int dy) {
	for (int i = 0; i < linkedEntities_.size(); i++) {
		linkedEntities_[i]->setLocation(linkedEntities_[i]->getX() + dx,
				linkedEntities_[i]->getY() + dy);
	}
}

