/*
 * Component.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Component.h"

Component::Component() {
	// TODO Auto-generated constructor stub
	hasFocus_=false;
	foreGround_=Color(0,0,0);
	backGround_=Color(250,250,250);
}

Component::~Component() {
	// TODO Auto-generated destructor stub
}

void Component::render(Painter * p){
	this->paintComponent(p);
}
bool Component::hasFocus(){
	return hasFocus_;
}
void  Component::getFocus(){
	hasFocus_=true;
}
void  Component::lostFocus(){
	hasFocus_=false;
}

Color Component::getBackground(){
	return backGround_;
}

Color Component::getForeground(){
	return foreGround_;
}

void Component::setBackground(Color c){
	backGround_=c;
}

void Component::setForeground(Color c){
	foreGround_=c;
}
