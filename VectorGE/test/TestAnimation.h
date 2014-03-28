/*
 * TestAnimation.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef TESTANIMATION_H_
#define TESTANIMATION_H_

#include "../src/game/GameEntity.h"
#include "../src/core/stateMachine/StateMachine.h"
#include "../src/game/primitives/Image.h"
#include "../src/game/primitives/geometry/Polygon.h"
#include "../src/game/events/MouseListener.h"

class TestAnimation : public GameEntity, public MouseListener{
public:
	TestAnimation();
	virtual ~TestAnimation();
	virtual void render(Painter * p);
	virtual void step(double dt);

	virtual void mouseMotion(SDL_MouseMotionEvent *e);
private:
	Image * image;
	SDL_Point mPos;
};

#endif /* TESTANIMATION_H_ */
