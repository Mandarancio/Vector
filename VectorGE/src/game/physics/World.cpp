/*
 * World.cpp
 *
 *  Created on: 05/apr/2014
 *      Author: martino
 */

#include "World.h"

World::World(float gx, float gy) {
	world_=new b2World(b2Vec2(gx,gy));
	conversion_=100.0;
	positionIterations_=8;
	velocityIterations_=10;
}

World::~World() {
	delete world_;
}


void World::step(float dt){
	world_->Step(dt, velocityIterations_, positionIterations_);
}
