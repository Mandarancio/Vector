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
	bounds_.x=0;
	bounds_.y=0;
	bounds_.w=0;
	bounds_.h=0;
	parent_=0;
}

Component::~Component() {
	// TODO Auto-generated destructor stub
}

void Component::render(Painter * p){
	SDL_Rect oldclip=p->getClip();
	p->setClip(bounds_);
	this->paintComponent(p);
	p->setClip(oldclip);
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

SDL_Rect Component::getBounds(){
	return bounds_;
}

SDL_Point Component::getLocation(){
	SDL_Point p;
	p.x=bounds_.x;
	p.y=bounds_.y;
	return p;
}

SDL_Size Component::getSize(){
	SDL_Size s;
	s.width=bounds_.w;
	s.height=bounds_.h;
	return s;
}

int Component::getX(){
	return bounds_.x;
}

int Component::getY(){
	return bounds_.y;
}

int Component::getWidth(){
	return bounds_.w;
}

int Component::getHeight(){
	return bounds_.h;
}

void Component::setBounds(SDL_Rect r){
	bounds_=r;
}

void Component::setBounds(int x,int y,int w,int h){
	bounds_.x=x;
	bounds_.y=y;
	bounds_.w=w;
	bounds_.h=h;
}

void Component::setSize(SDL_Size size){
	bounds_.w=size.width;
	bounds_.h=size.height;
}

void Component::setSize(int w,int h){
	bounds_.w=w;
	bounds_.h=h;
}

void Component::setLocation(SDL_Point p){
	bounds_.x=p.x;
	bounds_.y=p.y;
}

void Component::setLocation(int x,int y){
	bounds_.x=x;
	bounds_.y=y;
}

Component * Component::getParent(){
	return parent_;
}

void Component::setParent(Component * parent){
	parent_=parent;
}
