/*
 * Body.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: martino
 */

#include "Body.h"

Body::Body(b2Body * body,b2World * world) {
	body_ = body;
	conversion_ = 100.0;
	world_=world;
}

Body::~Body() {
	if (body_ && world_){
		world_->DestroyBody(body_);
	}

}

b2Body * Body::getBody() {
	return body_;
}

SDL_Point Body::getPosition() {
	SDL_Point p;
	p.x = round(conversion_ * body_->GetPosition().x);
	p.y = round(conversion_ * body_->GetPosition().y);
	return p;
}

int Body::getX() {
	return round(conversion_ * body_->GetPosition().x);
}

int Body::getY() {
	return round(conversion_ * body_->GetPosition().y);
}
