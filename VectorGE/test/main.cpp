/*
 * main.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */
#include "../src/game/GameWindow.h"
#include "../src/game/Camera.h"

int main(int argc, char **argv) {
	GameWindow *gw = new GameWindow();
	Camera *c = new Camera(gw->renderer());
	SDL_Delay(2000);

	delete c;
	delete gw;
	return 0;
}

