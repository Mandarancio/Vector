/*
 * Character.h
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <game/GameEntity.h>
#include <Box2D/Box2D.h>

class Character: public GameEntity {
public:
	Character(b2World * world);
	virtual ~Character();
	virtual void render(Painter * p);
	virtual void step(double dt);
private:
	b2Body *body;


};

#endif /* CHARACTER_H_ */
