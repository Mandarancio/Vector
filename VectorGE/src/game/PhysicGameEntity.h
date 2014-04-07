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
#include "primitives/geometry/Shape.h"

#include <Box2D/Box2D.h>

class PhysicGameEntity: public GameEntity {
public:
	PhysicGameEntity(World * w);
	virtual ~PhysicGameEntity();
	virtual void step(double dt);
private:
	Body * body_;
	Shape * shape_;
};

#endif /* PHYSICGAMEENTITY_H_ */
