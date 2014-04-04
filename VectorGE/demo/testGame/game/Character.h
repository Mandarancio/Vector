/*
 * Character.h
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <game/GameEntity.h>

class Character: public GameEntity {
public:
	Character();
	virtual ~Character();
	virtual void render(Painter * p);

};

#endif /* CHARACTER_H_ */
