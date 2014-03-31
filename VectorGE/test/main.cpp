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
#include "../src/game/gui/TextField.h"

#include "../src/game/events/ActionListener.h"

#include "../src/game/armature/Armature.h"

#include "TestAnimation.h"

//class TestListener: public ActionListener {
//public:
//	TestListener(Label *l) {
//		label = l;
//	}
//
//	virtual void actionPerfoormed(Action * a) {
//		if (!a->getCommand().compare("button")) {
//			if (!label->getText().compare("hello world!")) {
//				label->setText("ciao mondo!");
//			} else {
//				label->setText("hello world!");
//			}
//		} else {
//			label->setVisibile(!label->isVisible());
//		}
//	}
//
//private:
//	Label * label;
//};

int main(int argc, char **argv) {
	GameWindow *gw = new GameWindow();
	Camera *c = new Camera(gw->painter());
	GameScene *scene = new GameScene(c); //,0,0.0);//9.8);
//
//	MainContainer * mc = new MainContainer();
//	mc->setBounds(0, 0, gw->getSize().width, gw->getSize().height);
//	Label * l = new Label("hello world!");
//	l->setBounds(10, 285, 150, 30);
//	mc->addComponent(l);
//	Button *b = new Button("button");
//	b->setBounds(10, 100, 120, 30);
//	TestListener * tl=new TestListener(l);
//	b->addActionListener(tl);
//	mc->addComponent(b);
//	CheckBox * cb = new CheckBox("visible");
//	cb->setChecked(true);
//	cb->addActionListener(tl);
//	cb->setBounds(10, 200, 200, 30);
//	mc->addComponent(cb);
//
//	TextField *tf=new TextField("text field");
//	tf->setBounds(10,350,200,30);
//	mc->addComponent(tf);
//
//	scene->addGUIMainComponent(mc);

	scene->addEntity(new BackgroundLayer());
	TestAnimation *ta=new TestAnimation(gw->getSize());
	scene->addEntity(ta);
//	scene->addMouseListener(ta);
	SDL_Point p;
	p.x=200;
	p.y=240;

	ArmaturePoint * a=new ArmaturePoint(p);

	p.x+=100;
	ArmaturePoint * c_a=new ArmaturePoint(p);

	p.x+=50;
	p.y+=100;
	ArmaturePoint * c_b=new ArmaturePoint(p);

	p.x+=100;
	ArmaturePoint *b=new ArmaturePoint(p);
//	a->addLinkedEntity(a1);

	ArmatureLine *line=new ArmatureLine(a,c_a,c_b,b);

	scene->addEntity(line);
	scene->addEntity(a);
	scene->addEntity(c_a);
	scene->addEntity(c_b);
	scene->addEntity(b);

	scene->addMouseListener(a);
	scene->addMouseListener(c_a);
	scene->addMouseListener(c_b);
	scene->addMouseListener(b);

	scene->gameLoop(2);

	delete c;
	delete gw;
	return 0;
}

