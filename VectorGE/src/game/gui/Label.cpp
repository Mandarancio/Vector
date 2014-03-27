/*
 * Label.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Label.h"

Label::Label(std::string text):Component(),text_(text) {
	// TODO Auto-generated constructor stub

}

Label::~Label() {
	// TODO Auto-generated destructor stub
}

void Label::paintComponent(Painter * p){
	p->setPen(foreGround_);
	int h=p->getFont()->textBounds(text_).h;
	p->paintText(text_,getX(),getY()+(getHeight()-h)/2);
}
