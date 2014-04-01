/*
 * BackgroundLayer.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer(Color c) {
	color_=c;
}

BackgroundLayer::~BackgroundLayer() {
}

void BackgroundLayer::render(Painter * p){
	p->setFill(color_);
	p->setPen(p->getFill());
	p->paintRect(0,0,p->getDisplaySize().width,p->getDisplaySize().height);

}
