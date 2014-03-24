/*
 * GameScene.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameScene.h"
#include <iostream>
#include <sys/time.h>
#include <sstream>

#define FPS_DEBUG true

GameScene::GameScene(Camera * camera, b2World *world) :
		Entity() {
	this->camera = camera;
	this->world = world;
	positionIterations=8;
	velocityIterations=10;
}

GameScene::GameScene(Camera * camera,float gx,float gy):Entity(){
	this->camera = camera;
	this->world=new b2World(b2Vec2(gx,gy));
	positionIterations=8;
	velocityIterations=10;
}

GameScene::~GameScene() {
}

void GameScene::gameLoop(int dt) {
	bool quit = false;
	SDL_Event event;
	struct timeval past, present;

	double delta;
	gettimeofday(&past, NULL);
	int fps;
	std::stringstream ss;
	while (!quit) {
		gettimeofday(&present, NULL);
		delta = (present.tv_usec - past.tv_usec) / 1000.0;
		camera->getPainter()->clearWindow();

		if (world!=0){
			float dt=delta/1000.0;
			world->Step(dt,velocityIterations,positionIterations);
		}

		SDL_PollEvent(&event);

		for (int i = 0; i < gameEntities.size(); i++) {
			gameEntities[i]->step(delta, event);
			gameEntities[i]->render(camera->getPainter());
		}
		if (dt > 0 && FPS_DEBUG) {
			fps = 1000.0 / delta;
			if (fps < 0)
				fps = 0;
			ss << "FPS: " << fps;
			camera->getPainter()->paintText(ss.str(), 5, 10);
			ss.str("");
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

b2World * GameScene::getWorld(){
	return world;
}

