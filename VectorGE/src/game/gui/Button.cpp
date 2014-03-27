/*
 * Button.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Button.h"

Button::Button(std::string text) {
	text_ = text;
	cmdString_ = "button";
	horizontalAlignment_ = H_CENTER;
	status_ = NORMAL;
}

Button::~Button() {
}

void Button::setText(std::string text) {
	text_ = text;
}

std::string Button::getText() {
	return text_;
}

void Button::paintComponent(Painter * p) {

	int x = getX();
	int y = getY();
	int w = getWidth();
	int h = getHeight();

	p->setPen(Color(0, 0, 0, 0));

	if (status_ == NORMAL) {
		p->setFill(backGround_.darker().darker());
		p->paintRect(bounds_);
		p->setFill(
				(isMouseIn() ? backGround_.brighter().brighter() : backGround_));
		p->paintRect(x + 1, y + 1, w - 2, h - 4);
		h -= 2;
	} else if (status_ == PRESSED) {
		p->setFill(backGround_.brighter());
		p->paintRect(bounds_);
		p->setFill(backGround_.darker());
		p->paintRect(x + 1, y + 3, w - 2, h - 4);
		h += 2;

	}

	//Paint text
	if (isEnabled())
		p->setPen(foreGround_);
	else
		p->setPen(foreGround_.darker().darker());

	if (verticalAlgnment_ == V_CENTER) {
		int th = p->getFont()->textBounds(text_).h;
		y += (h - th) / 2;
	} else if (verticalAlgnment_ == V_BOTTOM) {
		int th = p->getFont()->textBounds(text_).h;
		y += (h - th);
	}

	if (horizontalAlignment_ == H_CENTER) {
		int tw = p->getFont()->textBounds(text_).w;
		x += (w - tw) / 2;
	} else if (horizontalAlignment_ == H_RIGHT) {
		int tw = p->getFont()->textBounds(text_).w;
		x += (w - tw);
	}
	p->paintText(text_, x, y);
}

void Button::mouseButtonDown(SDL_MouseButtonEvent * e) {
	if (isEnabled()) {
		if (status_==NORMAL){
			triggerActionListeners();
			status_ = PRESSED;
		}
	}
}

void Button::mouseButtonUp(SDL_MouseButtonEvent * e) {
	if (isEnabled()) {
		if (status_==PRESSED){
			status_ = NORMAL;
		}
	}
}

void Button::addActionListener(ActionListener * l) {
	actionListeners_.push_back(l);
}

void Button::removeActionListener(ActionListener * l) {
	for (int i = 0; i < actionListeners_.size(); i++) {
		if (actionListeners_[i] == l) {
			actionListeners_.erase(actionListeners_.begin() + i);
			return;
		}
	}
}

void Button::triggerActionListeners() {
	Action * action = new Action(cmdString_);
	for (int i = 0; i < actionListeners_.size(); i++) {
		actionListeners_[i]->actionPerfoormed(action);
	}
}

