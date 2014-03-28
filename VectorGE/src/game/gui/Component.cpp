/*
 * Component.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "Component.h"

Component::Component() {
	hasFocus_ = false;
	enabled_ = true;
	isVisible_ = true;
	isMouseIn_ = true;
	foreGround_ = Color(230, 230, 230);
	backGround_ = Color(54, 61, 63);
	bounds_.x = 0;
	bounds_.y = 0;
	bounds_.w = 0;
	bounds_.h = 0;
	parent_ = 0;
	horizontalAlignment_ = H_LEFT;
	verticalAlgnment_ = V_CENTER;
	font_ = new Font();
}

Component::~Component() {
}

void Component::render(Painter * p) {
	p->save();// <-- Performance incrised of 5x without the history saving
	p->setClip(bounds_);
	this->paintComponent(p);
	p->restore();
}
bool Component::hasFocus() {
	return hasFocus_;
}
void Component::getFocus() {
	hasFocus_ = true;
}
void Component::lostFocus() {
	hasFocus_ = false;
}

Color Component::getBackground() {
	return backGround_;
}

Color Component::getForeground() {
	return foreGround_;
}

void Component::setBackground(Color c) {
	backGround_ = c;
}

void Component::setForeground(Color c) {
	foreGround_ = c;
}

void Component::setFont(Font *f) {
	font_=f;
}
Font * Component::getFont() {
	return font_;
}

Component * Component::getParent() {
	return parent_;
}

void Component::setParent(Component * parent) {
	parent_ = parent;
}

void Component::setHorizontalAlignment(HorizontalAlignment ha) {
	horizontalAlignment_ = ha;
}

void Component::setVerticalAlignment(VerticalAlignment va) {
	verticalAlgnment_ = va;
}

void Component::setEnabled(bool enabled) {
	enabled_ = enabled;
}

bool Component::isEnabled() {
	return enabled_;
}

bool Component::isMouseIn() {
	return isMouseIn_;
}

void Component::mouseIn() {
	isMouseIn_ = true;
}
void Component::mouseOut() {
	isMouseIn_ = false;
}

bool Component::isVisible() {
	return isVisible_;
}
void Component::setVisibile(bool visible) {
	isVisible_ = visible;
}
void Component::setTooltip(std::string tooltip) {
	tooltip_ = tooltip;
}
std::string Component::getTooltip() {
	return tooltip_;
}
