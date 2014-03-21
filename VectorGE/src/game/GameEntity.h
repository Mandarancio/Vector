/*
 * GameEntity.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

#include "../core/Entity.h"

class GameEntity: public Entity {
public:
	GameEntity();
	virtual ~GameEntity();
	virtual void render()=0;
};

#endif /* GAMEENTITY_H_ */
