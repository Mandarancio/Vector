/*
 * Label.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Label.h"

Label::Label(std::string text) :
		Component(), text_(text) {

}

Label::~Label() {
	// TODO Auto-generated destructor stub
}

void Label::setText(std::string text) {
	text_ = text;
}

std::string Label::getText() {
	return text_;
}



void Label::paintComponent(Painter * p) {
	p->setPen(foreGround_);
	int x = getX();
	int y = getY();

	if (verticalAlgnment_ == V_CENTER) {
		int h = p->getFont()->textBounds(text_).h;
		y += (getHeight() - h) / 2;
	} else if (verticalAlgnment_ == V_BOTTOM) {
		int h = p->getFont()->textBounds(text_).h;
		y += (getHeight() - h);
	}

	if (horizontalAlignment_ == H_CENTER) {
		int w = p->getFont()->textBounds(text_).w;
		x += (getWidth() - w) / 2;
	} else if (horizontalAlignment_ == H_RIGHT) {
		int w = p->getFont()->textBounds(text_).w;
		x += (getWidth() - w);
	}
	p->paintText(text_, x, y);
}
