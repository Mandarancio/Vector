/*
 * GameMaster.h
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#ifndef GAMEMASTER_H_
#define GAMEMASTER_H_


#include <game/GameScene.h>
#include <game/events/ActionListener.h>
#include <core/stateMachine/StateMachine.h>


#include "IntroAnimation.h"

class GameMaster : public StateMachine, public ActionListener{
public:
	GameMaster(GameScene * scene);
	virtual ~GameMaster();

	virtual void ended(int id);
	virtual void actionPerfoormed(Action* a);

private:
	GameScene *scene_;
	GameEntity * current_;
};

#endif /* GAMEMASTER_H_ */
