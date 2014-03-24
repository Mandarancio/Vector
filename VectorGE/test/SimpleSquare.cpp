/*
 * SimpleSquare.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "SimpleSquare.h"
#include <iostream>

SimpleSquare::SimpleSquare(b2World * world, Camera * c) :
		GameEntity(), camera(c) {
	pos.x = c->getPainter()->getDisplaySize().width/2-5;
	pos.y = c->getPainter()->getDisplaySize().height/2-5;
	b2BodyDef bDef;

	bDef.position.x = pos.x/100;
	bDef.position.y = pos.y/100;
	bDef.type = b2_dynamicBody;

	b2FixtureDef fDef;
	fDef.density = 1.0;
	fDef.friction = 0.0;
	b2PolygonShape * shape = new b2PolygonShape();
	shape->SetAsBox(0.1, 0.1);
	fDef.shape = shape;

	body = world->CreateBody(&bDef);
	body->CreateFixture(&fDef);
	body->SetLinearVelocity(b2Vec2(2.0,0));
}

SimpleSquare::~SimpleSquare() {
}

void SimpleSquare::render(Painter * p) {
	p->setFill(Color(255, 255, 255, 255));
	p->paintRect(pos.x - 5, pos.y - 5, 10, 10);
}
void SimpleSquare::step(double dt, SDL_Event event) {
	int x= body->GetPosition().x * 100;
	int y= body->GetPosition().y * 100;
	camera->translate(-(x-pos.x),-(y-pos.y));
	pos.x =x;
	pos.y =y;
	body->ApplyForceToCenter(b2Vec2(0,5),true);

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
			body->ApplyForceToCenter(b2Vec2(0, -8), true);
			break;
//		case SDLK_DOWN:
//			body->ApplyForceToCenter(b2Vec2(0,1), true);
//			break;
		}
		break;
	}
}

