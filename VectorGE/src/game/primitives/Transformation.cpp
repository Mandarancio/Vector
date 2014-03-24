/*
 * Transformation.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Transformation.h"

Transformation::Transformation() {
	translation_.x = 0;
	translation_.y = 0;
	rotation_ = 0.0;
	scale_ = 1.0;
}

Transformation::Transformation(SDL_Point translation, double rotation, double scale) :
		translation_(translation), rotation_(rotation), scale_(scale)
{

}

Transformation::~Transformation() {
}

void Transformation::applyTransformation(SDL_Point &p) {
	applyTranslation(p);
	applyScale(p);
}

void Transformation::applyTransformation(int &x, int &y) {
	SDL_Point p;
	p.x = x;
	p.y = y;

	applyTransformation(p);

	x = p.x;
	y = p.y;
}

void Transformation::applyTransformation(Sint16 &x, Sint16 &y) {
	SDL_Point p;
	p.x = x;
	p.y = y;

	applyTransformation(p);

	x = p.x;
	y = p.y;
}

void Transformation::applySizeTransformation(int &w, int &h) {
	SDL_Point p;
	p.x = w;
	p.y = h;
	applyScale(p);
	w = p.x;
	h = p.y;
}

void Transformation::applySizeTransformation(Uint16 &w, Uint16 &h) {
	SDL_Point p;
	p.x = w;
	p.y = h;
	applyScale(p);
	w = p.x;
	h = p.y;
}

void Transformation::translate(int x, int y) {
	SDL_Point p;
	p.x = x;
	p.y = y;
	translate(p);
}
void Transformation::translate(SDL_Point p) {
	translation_.x += p.x;
	translation_.y += p.y;
}

void Transformation::scale(double f) {
	if (f > 0)
		scale_ = f;
}

SDL_Point Transformation::getTransaltion() {
	return translation_;
}

double Transformation::getScale() {
	return scale_;
}

void Transformation::applyTranslation(SDL_Point &p) {
	p.x += translation_.x;
	p.y += translation_.y;
}

void Transformation::applyScale(SDL_Point &p) {
	p.x *= scale_;
	p.y *= scale_;
}

Transformation * Transformation::clone(){
	return new Transformation(translation_,rotation_,scale_);
}
