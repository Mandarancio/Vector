/*
 * Label.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Label.h"

Label::Label(std::string text) :
		Component(), text_(text) {
	// TODO Auto-generated constructor stub
	horizontalTextAlignment_ = H_LEFT;
	verticalTextAlgnment_ = V_CENTER;
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

void Label::setHorizontalAlignment(HorizontalAlignment ha) {
	horizontalTextAlignment_ = ha;
}

void Label::setVerticalAlignment(VerticalAlignment va) {
	verticalTextAlgnment_ = va;
}

void Label::paintComponent(Painter * p) {
	p->setPen(foreGround_);
	int x = getX();
	int y = getY();

	if (verticalTextAlgnment_ == V_CENTER) {
		int h = p->getFont()->textBounds(text_).h;
		y += (getHeight() - h) / 2;
	} else if (verticalTextAlgnment_ == V_BOTTOM) {
		int h = p->getFont()->textBounds(text_).h;
		y += (getHeight() - h);
	}

	if (horizontalTextAlignment_ == H_CENTER) {
		int w = p->getFont()->textBounds(text_).w;
		x += (getWidth() - w) / 2;
	} else if (horizontalTextAlignment_ == H_RIGHT) {
		int w = p->getFont()->textBounds(text_).w;
		x += (getWidth() - w);
	}
	p->paintText(text_, x, y);
}
