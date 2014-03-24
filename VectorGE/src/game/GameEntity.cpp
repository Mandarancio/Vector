/*
 * GameEntity.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameEntity.h"

GameEntity::GameEntity() {
	// TODO Auto-generated constructor stub

}

GameEntity::~GameEntity() {
	// TODO Auto-generated destructor stub
}

void GameEntity::step(double dt,SDL_Event event){
	//by default nothing to do
	//needed for animation and other stuff..
}

b2Body * GameEntity::getBody(){
	return 0;
}
