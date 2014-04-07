/*
 * Body.h
 *
 *  Created on: Apr 7, 2014
 *      Author: martino
 */

#ifndef BODY_H_
#define BODY_H_

#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

class Body {
public:
	Body(b2Body * body,b2World * world);
	virtual ~Body();

	b2Body * getBody();
	SDL_Point getPosition();
	int getX();
	int getY();
private:
	b2Body * body_;
	b2World * world_;
	float conversion_; //=100
};

#endif /* BODY_H_ */
