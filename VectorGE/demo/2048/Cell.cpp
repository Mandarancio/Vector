/*
 * Cell.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#include "Cell.h"
#include <sstream>
#include <iostream>

#define ATIME 200

Cell::Cell(int cx, int cy, int size, int padding, int val) {
	cellX_ = cx;
	cellY_ = cy;
	value_ = val;
	bounds_.w = size;
	bounds_.h = size;
	bounds_.x = cx * (padding + size) + padding;
	bounds_.y = cy * (padding + size) + padding;
	scale_ = 0.0;
	padding_ = padding;
	std::stringstream ss;
	ss << val;
	present_ = getCurrentStatus();
	future_ = present_;
	future_.scale = 1.0;

	lock_ = false;
	str_val = ss.str();
	animation_ = new Animation(present_, future_, ATIME);
}

Cell::~Cell() {

}

void Cell::render(Painter * p) {
	int w = bounds_.w * scale_;
	int h = bounds_.h * scale_;
	int x = bounds_.x + (bounds_.w - w) / 2;
	int y = bounds_.y + (bounds_.h - h) / 2;
	p->setFill(getColor());
	p->setPen(p->getFill());
	p->paintRect(x, y, w, h);
	p->setPen(getPen());
	p->getFont()->scale(2.0 * scale_);
	SDL_Rect tb = p->getFont()->textBounds(str_val);
	if (tb.w > w - 8 * scale_) {
		p->getFont()->scale(1.2 * scale_);
		tb = p->getFont()->textBounds(str_val);
	}
	tb.x = x + (w - tb.w) / 2;
	tb.y = y + (w - tb.h) / 2;
	p->paintText(str_val, tb.x, tb.y);
}

void Cell::step(double dt) {
	if (animation_ != NULL) {
		setCurrentStatus(animation_->step(dt));
		if (animation_->isEnded()) {
			present_=getCurrentStatus();
			delete animation_;
			animation_ = NULL;
		}
	}
}

Color Cell::getColor() {
	if (value_ == 2) {
		return Color(255, 255, 255);
	} else if (value_ == 4)
		return Color(255, 213, 213);
	else if (value_ == 8)
		return Color(255, 170, 170);
	else if (value_ == 16)
		return Color(255, 128, 128);
	else if (value_ == 32)
		return Color(255, 42, 42);
	else if (value_ == 64)
		return Color(255, 0, 0);
	else if (value_ == 128)
		return Color(255, 238, 170);
	else if (value_ == 256)
		return Color(255, 230, 128);
	else if (value_ == 512)
		return Color(255, 221, 85);
	else if (value_ == 1024)
		return Color(255, 212, 42);
	else
		return Color(255, 204, 0);

}

Color Cell::getPen() {
	if (value_ < 8)
		return Color(150, 150, 150);
	else if (value_ < 128)
		return Color(255, 255, 255);
	else
		return Color();
}
int Cell::getValue() {
	return value_;
}

int Cell::getCellX() {
	return cellY_;
}

int Cell::getCellY() {
	return cellX_;
}

bool Cell::compatible(Cell * c) {
	return c!=NULL && !isLocked() && !c->isLocked() && c->getValue() == value_;
}

bool Cell::sum(Cell * c) {
	if (c != NULL && compatible(c)) {
		value_ *= 2;
		std::stringstream ss;
		ss << value_;
		str_val = ss.str();
		lock_ = true;
		if (animation_ != NULL) {
			delete animation_;
			animation_ = NULL;
		}
		present_ = getCurrentStatus();
		present_.scale = 1.5;
		setCurrentStatus(present_);
		animation_ = new Animation(present_, future_, ATIME);

		return true;
	}
	return false;
}

bool Cell::isLocked() {
	return lock_;
}
void Cell::unlock() {
	lock_ = false;
}

void Cell::move(int x, int y) {
	present_ = getCurrentStatus();
	cellX_ = x;
	cellY_ = y;
	future_ = present_;
	future_.scale = 1.0;
	future_.bounds.x = x * (padding_ + bounds_.w) + padding_;
	future_.bounds.y = y * (padding_ + bounds_.w) + padding_;
	if (animation_) {
		delete animation_;
		animation_ = NULL;
	}
	animation_ = new Animation(present_, future_, ATIME);
}

bool Cell::isAnimating() {
	return animation_ != NULL && !animation_->isEnded();
}

SDL_Point Cell::getCell() {
	return (SDL_Point ) { cellX_, cellY_ } ;
}
