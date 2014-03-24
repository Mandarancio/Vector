/*
 * BackgroundLayer.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer() {
	// TODO Auto-generated constructor stub

}

BackgroundLayer::~BackgroundLayer() {
	// TODO Auto-generated destructor stub
}

void BackgroundLayer::render(Painter * p){
	p->paintRect(0,0,800,600);

}
