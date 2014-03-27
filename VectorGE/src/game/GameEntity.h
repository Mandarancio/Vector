/*
 * GameEntity.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

#include <Box2D/Box2D.h>

#include "../core/Entity.h"
#include "Painter.h"

class GameEntity: public Entity {
public:
	GameEntity();
	virtual ~GameEntity();
	virtual void render(Painter * p)=0;
	virtual void step(double dt);
};

#endif /* GAMEENTITY_H_ */
