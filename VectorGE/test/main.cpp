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
#include "../src/game/gui/CheckBox.h"

#include "../src/game/events/ActionListener.h"

#include "TestAnimation.h"

class TestListener: public ActionListener {
public:
	TestListener(Label *l) {
		label = l;
	}

	virtual void actionPerfoormed(Action * a) {
		if (!a->getCommand().compare("button")) {
			if (!label->getText().compare("hello world!")) {
				label->setText("ciao mondo!");
			} else {
				label->setText("hello world!");
			}
		} else {
			label->setVisibile(!label->isVisible());
		}
	}

private:
	Label * label;
};

int main(int argc, char **argv) {
	GameWindow *gw = new GameWindow();
	Camera *c = new Camera(gw->painter());
	GameScene *scene = new GameScene(c, 0); //,0,0.0);//9.8);

	MainContainer * mc = new MainContainer();
	mc->setBounds(0, 0, gw->getSize().width, gw->getSize().height);
	Label * l = new Label("hello world!");
	l->setBounds(10, 285, 150, 30);
	mc->addComponent(l);
	Button *b = new Button("button");
	b->setBounds(10, 100, 120, 30);
	TestListener * tl=new TestListener(l);
	b->addActionListener(tl);
	mc->addComponent(b);
	CheckBox * cb = new CheckBox("visible");
	cb->setChecked(true);
	cb->addActionListener(tl);
	cb->setBounds(10, 200, 200, 30);
	mc->addComponent(cb);

	scene->addGUIMainComponent(mc);

//	scene->addEntity(new BackgroundLayer());
//	TestAnimation *ta=new TestAnimation();
//	scene->addEntity(ta);
//	scene->addMouseListener(ta);

	scene->gameLoop(2);

	delete c;
	delete gw;
	return 0;
}

