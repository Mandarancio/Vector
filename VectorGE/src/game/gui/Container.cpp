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

void Container::step(double dt){
	for (int i=0;i<components_.size();i++){
		components_[i]->step(dt);
	}
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
		if (components_[i]->isEnabled() && components_[i]->isVisible()
				&& rectContains(components_[i]->getBounds(), e->x, e->y)) {
			if (!components_[i]->isMouseIn())
				components_[i]->mouseIn();
			components_[i]->mouseMotion(e);
		} else if (components_[i]->isMouseIn())
			components_[i]->mouseOut();
	}
}

void Container::mouseButtonDown(SDL_MouseButtonEvent * e) {
	for (int i = 0; i < components_.size(); i++) {
		if (components_[i]->isMouseIn()) {
			if (!components_[i]->hasFocus()) {
				for (int j = 0; j < components_.size(); j++) {
					if (components_[j]->hasFocus())
						components_[j]->lostFocus();
				}
				components_[i]->getFocus();
			}
			components_[i]->mouseButtonDown(e);
		}
	}
	if (!hasFocus()) {
		getFocus();
	}
}

void Container::mouseButtonUp(SDL_MouseButtonEvent * e) {
	for (int i = 0; i < components_.size(); i++) {
		if (components_[i]->hasFocus()) {
			components_[i]->mouseButtonUp(e);
		}
	}
}

void Container::lostFocus() {
	Component::lostFocus();
	for (int i = 0; i < components_.size(); i++) {
		if (components_[i]->hasFocus())
			components_[i]->lostFocus();
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
		if (components_[i]->isVisible())
			components_[i]->render(p);
	}
}

