/*
 * GameMaster.h
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#ifndef GAMEMASTER_H_
#define GAMEMASTER_H_

#include <game/GameScene.h>
#include <core/stateMachine/StateMachine.h>

#include "IntroAnimation.h"

class GameMaster : public StateMachine{
public:
	GameMaster(GameScene * scene);
	virtual ~GameMaster();

private:
	GameScene *scene_;
	GameEntity * current_;
};

#endif /* GAMEMASTER_H_ */
