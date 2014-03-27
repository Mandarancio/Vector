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

#include "../src/game/gui/Button.h"
#include "../src/game/gui/Label.h"

#include "TestAnimation.h"

int main(int argc, char **argv) {
	GameWindow *gw = new GameWindow();
	Camera *c = new Camera(gw->painter());
	GameScene *scene=new GameScene(c,0);//,0,0.0);//9.8);

	MainContainer * mc=new MainContainer();
	mc->setBounds(0,0,gw->getSize().width,gw->getSize().height);
	Label * l=new Label("hello world");
	l->setBounds(10,285,120,30);
	mc->addComponent(l);
	Button *b=new Button("button");
	b->setBounds(10,100,120,30);
	mc->addComponent(b);

	scene->addGUIMainComponent(mc);

//	scene->addEntity(new BackgroundLayer());
//	TestAnimation *ta=new TestAnimation();
//	scene->addEntity(ta);
//	scene->addMouseListener(ta);

	scene->gameLoop(0);

	delete c;
	delete gw;
	return 0;
}

