/*
 * GameEntity.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

#include "../core/Entity.h"
#include "Painter.h"

class GameEntity: public Entity {
public:
	GameEntity();
	virtual ~GameEntity();
	virtual void render(Painter * p)=0;
	virtual void step(double dt,SDL_Event event);
};

#endif /* GAMEENTITY_H_ */
