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

GameScene::GameScene(Camera * camera) :
		Entity() {
	this->camera = camera;
	this->world = 0;
	__quit = false;

	this->addWindowListener(camera->getPainter());
}

GameScene::GameScene(Camera * camera, World *world) :
		Entity() {
	this->camera = camera;
	this->world = world;
	__quit = false;

	this->addWindowListener(camera->getPainter());

}

GameScene::GameScene(Camera * camera, float gx, float gy) :
		Entity() {
	this->camera = camera;
	this->world = new World(gx, gy);

	__quit = false;

	this->addWindowListener(camera->getPainter());
}

GameScene::~GameScene() {
	for (unsigned int i = 0; i < gameEntities.size(); i++) {
		delete gameEntities[i];
	}
	gameEntities.clear();

	mouseListeners.clear();

	keyListeners.clear();
	if (world != NULL)
		delete world;
}

void GameScene::gameLoop(Uint16 dt) {
	SDL_Event event;
	struct timeval past, present;

	double delta;
	gettimeofday(&past, NULL);

	bool autoFPS = dt == 0;
	int delay = dt;

#if FPS_DEBUG
	int fps;
#endif
	std::stringstream ss;
	Painter * p = camera->getPainter();

	while (!__quit) {
		past.tv_usec = present.tv_usec;
		gettimeofday(&present, NULL);
		delta = (present.tv_usec - past.tv_usec) / 1000.0;
		p->clearWindow();

		if (world != 0) {
			float dt = delta / 1000.0;
			world->step(dt);
		}

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			__quit = true;
			break;
		case SDL_MOUSEMOTION:
			triggerMouseListener(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			triggerMouseListener(event);
			break;
		case SDL_MOUSEBUTTONUP:
			triggerMouseListener(event);
			break;
		case SDL_MOUSEWHEEL:
			triggerMouseListener(event);
			break;
		case SDL_KEYDOWN:
			triggerKeyListener(event);
			break;
		case SDL_KEYUP:
			triggerKeyListener(event);
			break;
		case SDL_WINDOWEVENT:
			triggerWindowListener(event);
			break;
		}

		for (unsigned int i = 0; i < gameEntities.size(); i++) {
			GameEntity * ge = gameEntities[i];
			if (ge != 0) {
				ge->step(delta);
				if (ge)
					ge->render(p);
			}
		}

		__removeEntities();

#if FPS_DEBUG
		fps = abs(1000.0 / delta);
		p->getFont()->scale(1.0);
		ss << "FPS: " << fps;
//		p->save();
		p->clearTransaltion();
		p->removeClip();

		SDL_Rect r = p->getFont()->textBounds(ss.str());
		r.x = 5;
		r.y = 5;
		r.w += 10;
		r.h += 10;
		p->setFill(Color(0, 0, 0, 180));
		p->setPen(Color(0, 0, 0, 180));
		p->paintRect(r);
		p->setPen(Color(255, 255, 255));
		p->paintText(ss.str(), 10, 10);

		ss.str("");
//		p->restore();
#endif
		p->renderToScreen();
		if (autoFPS) {
			delay = round(1000.0 / 500 - abs(delta));
			if (delay < 0)
				delay = 0;
		}

		if (delay > 0) {
			SDL_Delay(delay);
		}
	}
}

void GameScene::addEntity(GameEntity *ge) {
	gameEntities.push_back(ge);
}

void GameScene::removeEntity(GameEntity *ge) {
	__toRemove.push_back(ge);
}

void GameScene::__removeEntities() {
	for (unsigned int i = 0; i < __toRemove.size(); i++) {
		__removeEntity(__toRemove[i]);
	}
	__toRemove.clear();
}

void GameScene::__removeEntity(GameEntity *ge) {
	std::vector<GameEntity*>::iterator it = std::find(gameEntities.begin(),
			gameEntities.end(), ge);
	if (it != gameEntities.end()) {
		gameEntities.erase(it);
		delete ge;
	}
}

void GameScene::addGUIMainComponent(MainContainer * mc) {
	addEntity(mc);
	addMouseListener(mc);
	addWindowListener(mc);
	addKeyListener(mc);
}

World * GameScene::getWorld() {
	return world;
}

void GameScene::addMouseListener(MouseListener * ml) {
	mouseListeners.push_back(ml);
}
void GameScene::removeMouseListener(MouseListener *ml) {
	for (unsigned int i = 0; i < mouseListeners.size(); i++) {
		if (ml == mouseListeners[i]) {
			removeMouseListener(i);
			break;
		}
	}
}

void GameScene::removeMouseListener(int ind) {
	mouseListeners.erase(mouseListeners.begin() + ind);
}

void GameScene::addKeyListener(KeyListener *kl) {
	keyListeners.push_back(kl);
}

void GameScene::removeKeyListener(KeyListener *kl) {
	for (unsigned int i = 0; i < keyListeners.size(); i++) {
		if (kl == keyListeners[i]) {
			removeKeyListener(i);
			break;
		}
	}
}

void GameScene::removeKeyListener(int ind) {
	keyListeners.erase(keyListeners.begin() + ind);
}

void GameScene::addWindowListener(WindowListener *l) {
	windowListeners.push_back(l);
}

void GameScene::removeWindowListener(WindowListener *l) {
	for (unsigned int i = 0; i < windowListeners.size(); i++) {
		if (windowListeners[i] == l) {
			removeWindowListener(i);
			break;
		}
	}
}

void GameScene::removeWindowListener(int ind) {
	windowListeners.erase(windowListeners.begin() + ind);
}

void GameScene::quit() {
	__quit = true;
}

void GameScene::clear() {
	for (unsigned int i = 0; i < gameEntities.size(); i++) {
		__toRemove.push_back(gameEntities[i]);
	}
	keyListeners.clear();
	mouseListeners.clear();
}

SDL_Rect GameScene::getDisplayBounds() {
	return camera->getDisplayBounds();
}

void GameScene::triggerMouseListener(SDL_Event e) {

	for (unsigned int i = 0; i < mouseListeners.size(); i++) {
		mouseListeners[i]->triggerEvent(&e);
	}
}

void GameScene::triggerKeyListener(SDL_Event e) {
	for (unsigned int i = 0; i < keyListeners.size(); i++) {
		keyListeners[i]->triggerEvent(&e);
	}
}

void GameScene::triggerWindowListener(SDL_Event e) {
	for (unsigned int i = 0; i < windowListeners.size(); i++) {
		windowListeners[i]->triggerEvent(&e);
	}
}
