/*
 * Character.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#include "Character.h"

Character::Character(b2World * world) {
	// TODO Auto-generated constructor stub
	bounds_.x = 10;
	bounds_.y = 300;
	bounds_.w = 30;
	bounds_.h = 65;
	b2BodyDef bDef;

	bDef.position.x = bounds_.x / 100;
	bDef.position.y = bounds_.y / 100;
	bDef.type = b2_dynamicBody;

	b2FixtureDef fDef;
	fDef.density = 1.0;
	fDef.friction = 0.0;
	b2PolygonShape * shape = new b2PolygonShape();
	shape->SetAsBox(bounds_.w/100.0, bounds_.h/100.0);
	fDef.shape = shape;

	body = world->CreateBody(&bDef);
	body->CreateFixture(&fDef);
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
