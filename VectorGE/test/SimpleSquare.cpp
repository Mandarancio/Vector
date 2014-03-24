/*
 * SimpleSquare.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "SimpleSquare.h"
#include <iostream>

SimpleSquare::SimpleSquare(b2World * world) :
		GameEntity() {
	pos.x = 100;
	pos.y = 100;
	b2BodyDef bDef;

	bDef.position.x = 1;
	bDef.position.y = 1;
	bDef.type = b2_dynamicBody;

	b2FixtureDef fDef;
	fDef.density = 1.0;
	fDef.friction = 1.0;
	b2PolygonShape * shape = new b2PolygonShape();
	shape->SetAsBox(0.1, 0.1);
	fDef.shape = shape;

	body = world->CreateBody(&bDef);
	body->CreateFixture(&fDef);
	body->SetLinearVelocity(b2Vec2(5.0,0));
}

SimpleSquare::~SimpleSquare() {
}

void SimpleSquare::render(Painter * p) {
	p->setFill(Color(0, 0, 0, 255));
	p->paintRect(pos.x - 5, pos.y - 5, 10, 10);
}
void SimpleSquare::step(double dt, SDL_Event event) {
	pos.x = body->GetPosition().x * 100;
	pos.y = body->GetPosition().y * 100;

	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
//		case SDLK_LEFT:
//			body->ApplyForceToCenter(b2Vec2(-1, 0), true);
//			break;
//		case SDLK_RIGHT:
//			body->ApplyForceToCenter(b2Vec2(1, 0), true);
//			break;
		case SDLK_UP:
			body->ApplyForceToCenter(b2Vec2(0, -1), true);
			break;
//		case SDLK_DOWN:
//			body->ApplyForceToCenter(b2Vec2(0,1), true);
//			break;
		}
		break;
	}
}

