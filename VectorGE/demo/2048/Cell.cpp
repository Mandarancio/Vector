/*
 * Cell.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#include "Cell.h"
#include <sstream>

Cell::Cell(int cx, int cy, int size, int padding, int val) {
	cellX_ = cx;
	cellY_ = cy;
	value_ = val;
	bounds_.w = size;
	bounds_.h = size;
	bounds_.x = cx * (padding + size) + padding;
	bounds_.y = cy * (padding + size) + padding;
	padding_=padding;
	std::stringstream ss;
	ss << val;
	str_val = ss.str();
}

Cell::~Cell() {

}

void Cell::render(Painter * p) {

	p->setFill(getColor());
	p->setPen(p->getFill());
	p->paintRect(bounds_);
	p->setPen(getPen());
	p->getFont()->scale(2.0);
	SDL_Rect tb = p->getFont()->textBounds(str_val);
	if (tb.w > bounds_.w - 8) {
		p->getFont()->scale(1.2);
		tb = p->getFont()->textBounds(str_val);
	}
	tb.x = bounds_.x + (bounds_.w - tb.w) / 2;
	tb.y = bounds_.y + (bounds_.h - tb.h) / 2;
	p->paintText(str_val, tb.x, tb.y);
}

Color Cell::getColor() {
	if (value_==2){
		return Color(255, 255, 255);
	}else if (value_==4)
		return Color(255,213,213);
	else if (value_==8)
		return Color(255,170,170);
	else if (value_==16)
		return Color(255,128,128);
	else if (value_==32)
		return Color(255,42,42);
	else if (value_==64)
		return Color(255, 0, 0);
	else if (value_==128)
		return Color(255,238,170);
	else if (value_==256)
		return Color(255,230,128);
	else if (value_==512)
		return Color(255,221,85);
	else if (value_==1024)
		return Color(255,212,42);
	else return Color(255,204,0);

}

Color Cell::getPen(){
	if (value_<8)
		return Color(150,150,150);
	else if (value_<128)
		return Color(255,255,255);
	else return Color();
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
	return c->getValue() == value_;
}

bool Cell::sum(Cell * c) {
	if (c!=NULL && c->getValue()==value_) {
		value_ *= 2;
		std::stringstream ss;
		ss << value_;
		str_val = ss.str();
		return true;
	}
	return false;
}

void Cell::move(int x, int y){
	cellX_=x;
	cellY_=y;
	bounds_.x = x * (padding_ + bounds_.w) + padding_;
	bounds_.y = y * (padding_ + bounds_.w) + padding_;
}

SDL_Point Cell::getCell() {
	return (SDL_Point ) { cellX_, cellY_ } ;
}
