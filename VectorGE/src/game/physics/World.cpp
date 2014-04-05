/*
 * World.cpp
 *
 *  Created on: 05/apr/2014
 *      Author: martino
 */

#include "World.h"

World::World(float gx, float gy) {
	world_ = new b2World(b2Vec2(gx, gy));
	conversion_ = 100.0;
	positionIterations_ = 8;
	velocityIterations_ = 10;
}

World::~World() {
	delete world_;
}

void World::step(float dt) {
	world_->Step(dt, velocityIterations_, positionIterations_);
}

b2Body * World::createDBody(SDL_Rect rect) {

	return createBody(rect,b2_dynamicBody);
}

b2Body * World::createSBody(SDL_Rect rect) {
	return createBody(rect,b2_staticBody);
}

b2Body * World::createBody(SDL_Rect rect, b2BodyType type) {
	b2BodyDef bDef;

	bDef.position.x = rect.x / conversion_;
	bDef.position.y = rect.y / conversion_;
	bDef.type = type;
	b2FixtureDef fDef;
	fDef.density = 1.0;
	fDef.friction = 0.0;
	b2PolygonShape * shape = new b2PolygonShape();

	shape->SetAsBox(rect.w / conversion_, rect.h / conversion_);
	fDef.shape = shape;

	b2Body *body = world_->CreateBody(&bDef);
	body->CreateFixture(&fDef);
	return body;
}
