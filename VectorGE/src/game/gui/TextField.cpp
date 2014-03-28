/*
 * TextField.cpp
 *
 *  Created on: 28/mar/2014
 *      Author: martino
 */

#include "TextField.h"

#include <iostream>

TextField::TextField(std::string text) :
		text_(text) {
	cursorPos_ = 0;
	__cursorTimer = 0;
	__cursorAnimVisible = false;
	__clickFlag = false;
}

TextField::~TextField() {
	// TODO Auto-generated destructor stub
}

void TextField::step(double dt) {
	if (isEnabled() && hasFocus()) {
		__cursorTimer += abs(dt);
		if (__cursorTimer >= 1000) {
			__cursorTimer = 0;
			__cursorAnimVisible = !__cursorAnimVisible;
		}
	}
}

void TextField::setText(std::string text) {
	text_ = text;
}

std::string TextField::getText() {
	return text_;
}

void TextField::getFocus() {
	Component::getFocus();
	if (!__cursorAnimVisible) {
		__cursorAnimVisible = true;
		__cursorTimer = 0;
	}
}

void TextField::mouseButtonUp(SDL_MouseButtonEvent * e) {
	if (!__clickFlag && isEnabled()) {
		__clickFlag = true;
		cursorPos_ = _convertXtoCursorPos(e->x - getX());
		__cursorTimer=0;
		__cursorAnimVisible=true;
	}
}
void TextField::mouseButtonDown(SDL_MouseButtonEvent *e) {
	__clickFlag = false;

}

void TextField::paintComponent(Painter *p) {
	p->setFont(getFont());
	p->setPen(backGround_.darker().darker());
	p->setFill(Color(255, 255, 255));
	p->paintRect(bounds_);
	p->setPen(Color(6, 6, 6));
	int y = (getHeight() - p->getFont()->textBounds(text_).h) / 2;
	p->paintText(text_, getX() + 4, getY() + y);

	if (hasFocus() && isEnabled()) {
		paintCursor(p);
	}
}

void TextField::paintCursor(Painter *p) {
	if (__cursorAnimVisible) {
		int x = _convertCursorPosToX(cursorPos_);
		p->paintLine(getX() + x, getY() + 3, getX() + x,
				getY() + getHeight() - 3);
	}
}

int TextField::_convertCursorPosToX(int cp) {
	int x = 4;
	if (cp > 0 && text_.length() >= cp) {
		std::string sub = text_.substr(0, cp);
		x += getFont()->textBounds(sub).w;
	}
	if (x > getWidth() - 4)
		x = getWidth() - 4;
	return x;
}

int TextField::_convertXtoCursorPos(int x) {
	if (x < 4)
		return 0;
	if (x > getWidth() - 4)
		return text_.length();

	int w = getFont()->textBounds(text_).w;

	if (w > getWidth() - 8) {
		w = getWidth() - 8;
	}
	if (x > w)
		return text_.length() ;
	float cw = 1.0 * w / text_.length();
	int ind = round((x-1.0) / cw);
	return ind;
}
