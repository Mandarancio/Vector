/*
 * World.h
 *
 *  Created on: 05/apr/2014
 *      Author: martino
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <Box2D/Box2D.h>

class World {
public:
	World(float gx,float gy);
	virtual ~World();

	void step(float dt);

private:
	b2World* world_ ;
	int positionIterations_;// = 8;
	int velocityIterations_; //= 10;
	float conversion_; //=100
};

#endif /* WORLD_H_ */
