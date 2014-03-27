/*
 * Container.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Container.h"

Container::Container() {
	// TODO Auto-generated constructor stub

}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

void Container::addComponent(Component * c){}
void Container::removeComponent(Component * c){}
void Container::removeComponent(int ind){}


void Container::paintComponent(Painter * p){
	p->setFill(backGround_);
	p->setPen(backGround_);
	p->paintRect(bounds_);
	paintSubComponents(p);
}

void Container::paintSubComponents(Painter *p){
	for (int i=0;i<components_.size();i++){
		components_[i]->render(p);
	}
}


std::vector<Component *> Container::getComponents(){
	return components_;
}

