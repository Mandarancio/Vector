/*
 * Font.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Font.h"
#include "../../support/Logging.h"
#include "Color.h"
#include <iostream>

Font::Font() {
	ttf_file_ = "./resources/DejaVuSans.ttf";
	size_ = 20;
	font_ = TTF_OpenFont(ttf_file_.c_str(), size_);

	if (font_ == 0) {
		logSDLError(std::cout, "TTF_OpenFont");
	}
	scale_=1.0;
}

Font::Font(std::string font, int size) {
	ttf_file_ = font;
	this->size_ = size;
	this->font_ = TTF_OpenFont(ttf_file_.c_str(), size);

	if (this->font_ == 0) {
		logSDLError(std::cout, "TTF_OpenFont");
	}
	scale_=1.0;
}

Font::~Font() {
}

SDL_Surface * Font::toSurface(std::string text, SDL_Color color) {
	SDL_Surface *surf = TTF_RenderText_Blended(font_, text.c_str(), color);
	if (surf == 0) {
		logSDLError(std::cout, "TTF_RenderText");
		return 0;
	}
	return surf;
}

SDL_Rect Font::textBounds(std::string text) {
	Color c;
	SDL_Surface *surf = TTF_RenderText_Blended(font_, text.c_str(),
			c.getSDLColor());
	if (surf == 0) {
		logSDLError(std::cout, "TTF_RenderText");
		SDL_Rect r;
		r.x = 0;
		r.y = 0;
		r.w = 0;
		r.h = 0;
		return r;
	}
	return surf->clip_rect;
}

std::string Font::getName() {
	return ttf_file_;
}

int Font::getSize() {
	return size_;
}

void Font::scale(double s){
	scale_=s;
	font_ = TTF_OpenFont(ttf_file_.c_str(),scale_*size_);

		if (font_ == 0) {
			logSDLError(std::cout, "TTF_OpenFont");
		}
}

