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
}

Transformation::~Transformation() {
}

SDL_Point Transformation::applyTransformation(SDL_Point p) {
	return applyTranslation(p);
}
SDL_Point Transformation::applyTransformation(int x, int y) {
	SDL_Point p;
	p.x = x;
	p.y = y;

	return applyTransformation(p);
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

SDL_Point Transformation::getTransaltion() {
	return translation_;
}


SDL_Point Transformation::applyTranslation(SDL_Point p){
	SDL_Point tp;
	tp.x=p.x+translation_.x;
	tp.y=p.y+translation_.y;
	return tp;
}
