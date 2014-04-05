/*
 * Character.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#include "Character.h"

Character::Character(World * world) {
	// TODO Auto-generated constructor stub
	bounds_.x = 10;
	bounds_.y = 300;
	bounds_.w = 30;
	bounds_.h = 65;


	body = world->createDBody(bounds_);
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::render(Painter * p) {
	p->setColors(Color());
	p->paintRect(bounds_);
}

void Character::step(double dt) {
	bounds_.x = body->GetPosition().x * 100;
	bounds_.y= body->GetPosition().y * 100;

}
