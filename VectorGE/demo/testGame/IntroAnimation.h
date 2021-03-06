/*
 * IntroAnimation.h
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#ifndef INTROANIMATION_H_
#define INTROANIMATION_H_

#include <game/GameEntity.h>
#include <game/primitives/Image.h>
#include <game/animation/Animation.h>

#include <core/stateMachine/State.h>


class IntroAnimation: public GameEntity, public State {
public:
	IntroAnimation(StateListener * listener,SDL_Rect display);
	virtual ~IntroAnimation();
	virtual void render(Painter * p);
	virtual void step(double dt);

private:
	Image * image;
	Animation * animation;

};

#endif /* INTROANIMATION_H_ */
