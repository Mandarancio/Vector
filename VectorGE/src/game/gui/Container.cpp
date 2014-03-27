/*
 * Container.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Container.h"
#include "../../support/Geometric.h"

Container::Container() :
		Component() {
	layout_ = 0;
}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

void Container::addComponent(Component * c) {
	c->setParent(this);
	components_.push_back(c);
}
void Container::removeComponent(Component * c) {
}
void Container::removeComponent(int ind) {
}

std::vector<Component *> Container::getComponents() {
	return components_;
}

Layout * Container::getLayout() {
	return layout_;
}

void Container::setLayout(Layout * l) {
	layout_ = l;
}

void Container::setSize(int w, int h) {
	Component::setSize(w, h);
	if (layout_) {
		//TODO add here
	}
}
void Container::mouseMotion(SDL_MouseMotionEvent * e) {
	for (int i = 0; i < components_.size(); i++) {
		if (rectContains(components_[i]->getBounds(),e->x,e->y)){
			components_[i]->mouseMotion(e);
			components_[i]->getFocus();
		}
		else components_[i]->lostFocus();
	}
}
void  Container::mouseButtonDown(SDL_MouseButtonEvent * e){
	for (int i = 0; i < components_.size(); i++) {
		if (components_[i]->hasFocus()){
			components_[i]->mouseButtonDown(e);
		}
	}
}

void  Container::mouseButtonUp(SDL_MouseButtonEvent * e){
	for (int i = 0; i < components_.size(); i++) {
		if (components_[i]->hasFocus()){
			components_[i]->mouseButtonUp(e);
		}
	}
}

void Container::paintComponent(Painter * p) {
	p->setFill(backGround_);
	p->setPen(backGround_);
	p->paintRect(bounds_);
	paintSubComponents(p);
}

void Container::paintSubComponents(Painter *p) {
	for (int i = 0; i < components_.size(); i++) {
		components_[i]->render(p);
	}
}


