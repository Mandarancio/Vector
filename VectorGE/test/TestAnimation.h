/*
 * TestAnimation.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef TESTANIMATION_H_
#define TESTANIMATION_H_

#include "../src/game/GameEntity.h"
#include "../src/game/primitives/Image.h"
#include "../src/game/primitives/geometry/BezierPath.h"
#include "../src/game/animation/Animation.h"

class TestAnimation : public GameEntity{
public:
	TestAnimation(SDL_Size display);
	virtual ~TestAnimation();
	virtual void render(Painter * p);
	virtual void step(double dt);

private:
	Image * image;
	Animation * animation;
	BezierPath *path;
	Polygon * pol;
};

#endif /* TESTANIMATION_H_ */
