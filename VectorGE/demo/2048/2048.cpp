/*
 * 2048.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "../../src/game/GameWindow.h"
#include "../../src/game/Camera.h"
#include "../../src/game/BackgroundLayer.h"
#include "../../src/game/GameScene.h"

#include "Board.h"

int main(int argc, char **argv) {
	srand(time(NULL));
	std::cout << "VECTOR 2048 game\n";
	int cell_size = 80;
	int padding = 15;
	int wsize = cell_size * 4 + 5 * padding;

	GameWindow *window = new GameWindow("2048", wsize, wsize+40, false);
	Camera *camera = new Camera(window->painter());
	GameScene *scene = new GameScene(camera);

	BackgroundLayer * background = new BackgroundLayer(Color(143, 116, 45));
	scene->addEntity(background);

	Board * board = new Board(cell_size, padding);

	scene->addEntity(board);
	scene->addKeyListener(board);

	scene->gameLoop(10);

	delete scene;
	delete window;

	return 0;
}
