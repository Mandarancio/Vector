/*
 * GameScene.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameScene.h"
#include <iostream>
#include <sys/time.h>

GameScene::GameScene(Camera * camera, b2World *world) :
		Entity() {
	this->camera = camera;
	this->world = world;
}

GameScene::~GameScene() {
}

void GameScene::gameLoop(int dt) {
	bool quit = false;
	SDL_Event event;
	struct timeval past, present;

	double delta;
	gettimeofday(&past, NULL);

	while (!quit) {
		gettimeofday(&present, NULL);
		delta = (present.tv_usec - past.tv_usec) / 1000.0;
		camera->getPainter()->clearWindow();
		SDL_WaitEvent(&event);

		for (int i = 0; i < gameEntities.size(); i++) {
			gameEntities[i]->step(delta,event);
			gameEntities[i]->render(camera->getPainter());
		}
		camera->getPainter()->renderToScreen();

		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}
		gettimeofday(&past, NULL);
		if (dt > 0)
			SDL_Delay(dt);

	}
}

void GameScene::addEntity(GameEntity *ge) {
	gameEntities.push_back(ge);
}
