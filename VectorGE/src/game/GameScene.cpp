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
#include <cmath>

#define FPS_DEBUG true

GameScene::GameScene(Camera * camera, b2World *world) :
		Entity() {
	this->camera = camera;
	this->world = world;
	positionIterations = 8;
	velocityIterations = 10;
}

GameScene::GameScene(Camera * camera, float gx, float gy) :
		Entity() {
	this->camera = camera;
	this->world = new b2World(b2Vec2(gx, gy));
	positionIterations = 8;
	velocityIterations = 10;
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
		past=present;
		gettimeofday(&present, NULL);
		delta = (present.tv_usec - past.tv_usec) / 1000.0;
		camera->getPainter()->clearWindow();

		if (world != 0) {
			float dt = delta / 1000.0;
			world->Step(dt, velocityIterations, positionIterations);
		}

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			std::cout << "here";
			quit = true;
			break;
		}

		for (int i = 0; i < gameEntities.size(); i++) {
			gameEntities[i]->step(delta, event);
			gameEntities[i]->render(camera->getPainter());
		}
		if (FPS_DEBUG) {
			delta = (present.tv_usec - past.tv_usec) / 1000.0;
			fps = abs(1000.0 / delta);

			ss << "FPS: " << fps;
			camera->getPainter()->save();
			camera->getPainter()->clearTransaltion();

			camera->getPainter()->setPen(Color(125, 125, 125, 255));
			camera->getPainter()->paintText(ss.str(), 5, 10);
			ss.str("");
			camera->getPainter()->restore();
		}
		camera->getPainter()->renderToScreen();

		if (dt > 0)
			SDL_Delay(dt);

	}
}

void GameScene::addEntity(GameEntity *ge) {
	gameEntities.push_back(ge);
}

b2World * GameScene::getWorld() {
	return world;
}

