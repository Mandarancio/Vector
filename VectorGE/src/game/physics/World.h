/*
 * World.h
 *
 *  Created on: 05/apr/2014
 *      Author: martino
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <Box2D/Box2D.h>
#include <SDL2/SDL_rect.h>

class World {
public:
	World(float gx,float gy);
	virtual ~World();

	void step(float dt);

	b2Body * createDBody(SDL_Rect rect);

private:
	b2World* world_ ;
	int positionIterations_;// = 8;
	int velocityIterations_; //= 10;
	float conversion_; //=100
};

#endif /* WORLD_H_ */
