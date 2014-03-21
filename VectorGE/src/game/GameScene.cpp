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

