/*
 * main.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include <iostream>

#include "../src/game/GameWindow.h"
#include "../src/game/Camera.h"
#include "../src/game/Painter.h"
#include "../src/game/GameScene.h"
#include "../src/game/BackgroundLayer.h"


#include "../src/game/primitives/geometry/Line.h"

#include "TestAnimation.h"

int main(int argc, char **argv) {
	GameWindow *gw = new GameWindow();
	Camera *c = new Camera(gw->painter());
	GameScene *scene=new GameScene(c);//,0,0.0);//9.8);
//	scene->addEntity(new BackgroundLayer());
	scene->addEntity(new TestAnimation());


	scene->gameLoop(0);

	delete c;
	delete gw;
	return 0;
}

