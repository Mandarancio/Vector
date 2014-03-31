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
	bounds_.x = pos.x ;
	bounds_.y = pos.y ;
	bounds_.w = 0;
	bounds_.h = 0;
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
	p->paintRect(bounds_.x-5,bounds_.y-5,10,10);
//	p->paintCircle(bounds_.x,bounds_.y,5);
#endif
}

void ArmaturePoint::mouseMotion(SDL_MouseMotionEvent *e) {
	if (__mouseDown) {
		int dx = (e->x ) - bounds_.x;
		int dy = (e->y ) - bounds_.y;

		bounds_.x += dx;
		bounds_.y += dy;

		_updateLinkedEntities(dx, dy);
	}
}
void ArmaturePoint::mouseButtonDown(SDL_MouseButtonEvent *e) {

	if (abs(e->x - getX()) < 5 && abs(e->y - getY()) < 5) {
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

ArmatureLine::ArmatureLine(ArmaturePoint * a, ArmaturePoint * c_a,ArmaturePoint * c_b,ArmaturePoint *b){
	this->a=a;
	this->b=b;
	this->c_a=c_a;
	this->c_b=c_b;

	curve=0;
}

ArmatureLine::~ArmatureLine(){
	delete a;
	delete b;
	delete c_a;
	delete c_b;
}

void ArmatureLine::render(Painter * p){
	if (curve)
		delete curve;

	curve=new BezierCurve(a->getLocation(),c_a->getLocation(),c_b->getLocation(),b->getLocation());
	p->setPen(Color());
	p->setFill(Color());
	p->paintBezierCourve(curve);

	p->paintLine(a->getX(),a->getY(),c_a->getX(),c_a->getY());
	p->paintLine(b->getX(),b->getY(),c_b->getX(),c_b->getY());
}
