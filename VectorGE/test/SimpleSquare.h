/*
 * SimpleSquare.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef SIMPLESQUARE_H_
#define SIMPLESQUARE_H_

#include "../src/game/GameEntity.h"

class SimpleSquare: public GameEntity {
public:
	SimpleSquare();
	virtual ~SimpleSquare();
	virtual void render(Painter * p);
	virtual void step(double dt,SDL_Event event);
private:
	SDL_Point pos;
};

#endif /* SIMPLESQUARE_H_ */
