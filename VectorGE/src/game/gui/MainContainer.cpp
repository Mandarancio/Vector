/*
 * MainContainer.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "MainContainer.h"
MainContainer::MainContainer() {
	// TODO Auto-generated constructor stub

}

MainContainer::~MainContainer() {
	// TODO Auto-generated destructor stub
}

void MainContainer::windowResized(SDL_WindowEvent *e){
	this->setSize(e->data1,e->data2);
}
