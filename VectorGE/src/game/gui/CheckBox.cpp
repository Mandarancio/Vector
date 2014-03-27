/*
 * CheckBox.cpp
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#include "CheckBox.h"

#include <iostream>

CheckBox::CheckBox(std::string text) :
		text_(text) {
	isChecked_ = false;
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
void CheckBox::paintComponent(Painter * p){
	int h=getHeight()-8;
	p->setPen(backGround_.brighter());
	p->setFill(backGround_.darker().darker());
	p->paintRect(getX(),getY()+4,h,h);
	int x=getX()+h+6;
	int y=getY()+4;
	int w=getWidth()-h-6;
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
