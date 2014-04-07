/*
 * Character.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#include "Character.h"
#include <game/primitives/geometry/Rectangle.h>

Character::Character(World * world) {
	bounds_.x = 10;
	bounds_.y = 300;
	bounds_.w = 30;
	bounds_.h = 65;

	shape_=new Rectangle(bounds_);
	body_ = world->createDBody(bounds_);
}

Character::~Character() {
}

void Character::render(Painter * p) {
	p->setColors(Color());
	p->paintRect(bounds_);
}
