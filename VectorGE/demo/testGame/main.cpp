/*
 * main.cpp
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#include "../../src/game/GameWindow.h"
#include "../../src/game/Camera.h"
#include "../../src/game/GameScene.h"

#include "GameMaster.h"

int main(int argc, char **argv) {
	GameWindow *window = new GameWindow("Vector test game", 800, 600, false);
	Camera *camera = new Camera(window->painter());
	GameScene *scene = new GameScene(camera);

	GameMaster * gm=new GameMaster(scene);

	scene->gameLoop(1);
	return 0;
}
