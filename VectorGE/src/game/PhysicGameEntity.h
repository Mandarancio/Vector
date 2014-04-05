/*
 * PhysicGameEntity.h
 *
 *  Created on: 06/apr/2014
 *      Author: martino
 */

#ifndef PHYSICGAMEENTITY_H_
#define PHYSICGAMEENTITY_H_

#include "GameEntity.h"

#include "physics/World.h"

class PhysicGameEntity: public GameEntity {
public:
	PhysicGameEntity(World * w);
	virtual ~PhysicGameEntity();
private:
	b2Body * body_;
	Shape * shape_;
};

#endif /* PHYSICGAMEENTITY_H_ */
