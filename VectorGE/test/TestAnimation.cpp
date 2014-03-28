/*
 * TestAnimation.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "TestAnimation.h"

TestAnimation::TestAnimation() {
	// TODO Auto-generated constructor stub
	image=new Image("./resources/icons/vector.png");
	mPos.x=-10;
	mPos.y=-10;
}

TestAnimation::~TestAnimation() {
	// TODO Auto-generated destructor stub
}

void TestAnimation::render(Painter * p){
	int x=p->getDisplayCenter().x-image->getSize().width/2;
	int y=p->getDisplayCenter().y-image->getSize().height/2;
	p->setFill(Color(125,125,125));
	p->setPen(p->getFill());
	p->paintRect(x+5,y+5,image->getSize().width,image->getSize().height);
	p->paintRect(0,p->getDisplayCenter().y+150,p->getDisplaySize().width,p->getDisplaySize().height);
	p->paintImage(*image,x,y);
	p->setPen(Color(0,0,0));
	p->setFill(Color(0,0,0));
	p->paintRect(mPos.x-5,mPos.y-5,10,10);
}
void TestAnimation::step(double dt){}

void TestAnimation::mouseMotion(SDL_MouseMotionEvent *e){
	mPos.x=e->x;
	mPos.y=e->y;
}
