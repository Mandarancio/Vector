/*
 * GameScene.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameScene.h"

GameScene::GameScene(Camera * camera, b2World *world) :Entity() {
	this->camera=camera;
	this->world=world;
}

GameScene::~GameScene() {
}

void GameScene::render(){
	camera->getPainter()->clearWindow();

	for (int i=0;i<gameEntities.size();i++){
		gameEntities[i]->render(camera->getPainter());
	}

	camera->getPainter()->renderToScreen();
}
void GameScene::addEntity(GameEntity *ge){
	gameEntities.push_back(ge);
}
