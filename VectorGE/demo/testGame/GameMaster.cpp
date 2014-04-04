/*
 * GameMaster.cpp
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#include "GameMaster.h"
#include <iostream>

#include "GameMenu.h"

GameMaster::GameMaster(GameScene * scene) : StateMachine(NULL){
	scene_=scene;
	IntroAnimation * ia=new IntroAnimation(this,scene->getDisplayBounds());
	current_=ia;
	state_=ia;
	scene->addEntity(current_);
}

GameMaster::~GameMaster() {
}


void GameMaster::ended(int id){

	std::cout<<"ended "<<id<<"\n";
	scene_->removeEntity(current_);
	std::cout<<"removed current element\n";
	if (id==0){
		std::cout<<"go to main menu\n";
		GameMenu * menu=new GameMenu(this);
		current_=menu;
		state_=menu;
		scene_->addEntity(menu);
	}
}
