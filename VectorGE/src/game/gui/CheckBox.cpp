/*
 * CheckBox.cpp
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#include "CheckBox.h"

#include "../../support/Geometric.h"

CheckBox::CheckBox(std::string text) :
		text_(text) {
	isChecked_ = false;
	__onCheckArea = false;
	__onClick = false;
	cmdString_="checkbox";
}

CheckBox::~CheckBox() {
}

void CheckBox::setText(std::string text) {
	text_ = text;
}

std::string CheckBox::getText() {
	return text_;
}

bool CheckBox::isChecked() {
	return isChecked_;
}

void CheckBox::setChecked(bool checked) {
	isChecked_ = checked;
}

void CheckBox::mouseOut() {
	Component::mouseOut();
	__onCheckArea = false;
}

void CheckBox::mouseMotion(SDL_MouseMotionEvent *e) {
	Component::mouseMotion(e);
	if (isEnabled()) {
		SDL_Rect r;
		r.x = getX();
		r.y = getY() + 4;
		r.w = getHeight() - 8;
		r.h = r.w;
		if (rectContains(r, e->x, e->y))
			__onCheckArea = true;
		else
			__onCheckArea = false;
	}
}

void CheckBox::mouseButtonDown(SDL_MouseButtonEvent * e) {
	if (__onCheckArea && !__onClick && isEnabled()) {
		isChecked_ = !isChecked_;
		triggerActionListeners();
		__onClick = true;
	}
}
void CheckBox::mouseButtonUp(SDL_MouseButtonEvent * e) {
	if (__onClick)
		__onClick = false;
}

void CheckBox::paintComponent(Painter * p) {
	int h = getHeight() - 8;
	p->setPen(backGround_.brighter());
	p->setFont(getFont());
	if (__onCheckArea && isEnabled()) {
		p->setFill(backGround_.darker());
	} else {
		p->setFill(backGround_.darker().darker());
	}

	p->paintRect(getX(), getY() + 4, h, h);

	if (isChecked_) {
		p->setFill(backGround_.brighter());
		p->paintRect(getX() + 4, getY() + 8, h - 8, h - 8);

	}

	int x = getX() + h + 6;
	int y = getY() + 4;
	int w = getWidth() - h - 6;
	p->setPen(foreGround_);
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

void CheckBox::addActionListener(ActionListener * l) {
	actionListeners_.push_back(l);
}

void CheckBox::removeActionListener(ActionListener * l) {
	for (int i = 0; i < actionListeners_.size(); i++) {
		if (actionListeners_[i] == l) {
			actionListeners_.erase(actionListeners_.begin() + i);
			return;
		}
	}
}

void CheckBox::triggerActionListeners() {
	Action * action = new Action(cmdString_);
	for (int i = 0; i < actionListeners_.size(); i++) {
		actionListeners_[i]->actionPerfoormed(action);
	}
}

