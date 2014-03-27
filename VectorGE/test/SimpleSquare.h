/*
 * SimpleSquare.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef SIMPLESQUARE_H_
#define SIMPLESQUARE_H_

#include "../src/game/GameEntity.h"
#include "../src/game/Camera.h"
#include <Box2D/Box2D.h>

class SimpleSquare: public GameEntity {
public:
	SimpleSquare(b2World * world, Camera * c);
	virtual ~SimpleSquare();
	virtual void render(Painter * p);
	virtual void step(double dt);
private:
	SDL_Point pos;
	b2Body *body;
	Camera * camera;
};

#endif /* SIMPLESQUARE_H_ */
