/*
 * main.cpp
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#include "../../src/game/GameWindow.h"
#include "../../src/game/Camera.h"
#include "../../src/game/GameScene.h"

int main(int argc, char **argv) {
	GameWindow *window = new GameWindow("Vector test game", 800, 600, false);
	Camera *camera = new Camera(window->painter());
	GameScene *scene = new GameScene(camera);


	scene->gameLoop();
	return 0;
}
