/*
 * PhysicGameEntity.cpp
 *
 *  Created on: 06/apr/2014
 *      Author: martino
 */

#include "PhysicGameEntity.h"

PhysicGameEntity::PhysicGameEntity() {
	shape_=0;
	body_=0;
}

PhysicGameEntity::~PhysicGameEntity() {
	if (body_)
		delete body_;
	if (shape_)
		delete shape_;
}

void PhysicGameEntity::step(double dt){
	if (body_){
		bounds_.x=body_->getX();
		bounds_.y=body_->getY()+shape_->getBoundingBox().h;
	}
}
