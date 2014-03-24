/*
 * main.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */
#include "../src/game/GameWindow.h"
#include "../src/game/Camera.h"
#include "../src/game/Painter.h"
#include "../src/game/GameScene.h"
#include "../src/game/BackgroundLayer.h"


int main(int argc, char **argv) {
	GameWindow *gw = new GameWindow();
	Painter *p= new Painter(gw->renderer());
	Camera *c = new Camera(p);
	GameScene *scene=new GameScene(c,0);
	p->translate(400,300);
	p->scale(0.5);

	scene->addEntity(new BackgroundLayer());
	scene->gameLoop();

	delete c;
	delete gw;
	return 0;
}

