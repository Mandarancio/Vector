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
	bounds_.w = size - 8;
	bounds_.h = size - 8;
	bounds_.x = cx * (padding + size) + 4 + padding;
	bounds_.y = cy * (padding + size) + 4 + padding;
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
	p->setPen(Color(114, 106, 46));
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
	return Color(214, 206, 146);
}
int Cell::getValue() {
	return value_;
}

SDL_Point Cell::getCell() {
	return (SDL_Point ) { cellX_, cellY_ };
}

int Cell::getCellX(){
	return cellY_;
}

int  Cell::getCellY(){
	return cellX_;
}

bool Cell::compatible(Cell c) {
	return c.getValue()==value_;
}

bool Cell::sum(Cell c) {
	if (compatible(c)){
		value_*=2;
		std::stringstream ss;
		ss << value_;
		str_val = ss.str();
		return true;
	}
	return false;
}
