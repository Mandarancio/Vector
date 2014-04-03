/*
 * GameMaster.cpp
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#include "GameMaster.h"

GameMaster::GameMaster(GameScene * scene) : StateMachine(NULL){
	scene_=scene;
	IntroAnimation * ia=new IntroAnimation(this,scene->getDisplayBounds());
	current_=ia;
	state_=ia;
	scene->addEntity(current_);
}

GameMaster::~GameMaster() {
}


