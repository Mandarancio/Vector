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
	ttf_file = "./resources/DejaVuSans.ttf";
	size = 20;
	font = TTF_OpenFont(ttf_file.c_str(), size);

	if (font == 0) {
		logSDLError(std::cout, "TTF_OpenFont");
	}
}

Font::Font(std::string font, int size) {
	ttf_file = font;
	this->size = size;
	this->font = TTF_OpenFont(ttf_file.c_str(), size);

	if (this->font == 0) {
		logSDLError(std::cout, "TTF_OpenFont");
	}
}

Font::~Font() {
}

SDL_Surface * Font::toSurface(std::string text, SDL_Color color) {
	SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surf == 0) {
		logSDLError(std::cout, "TTF_RenderText");
		return 0;
	}
	return surf;
}

SDL_Rect Font::textBounds(std::string text){
	Color c(0,0,0,255);
	SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(),c.getSDLColor());
	if (surf == 0) {
		logSDLError(std::cout, "TTF_RenderText");
		SDL_Rect r;
		r.x=0;
		r.y=0;
		r.w=0;
		r.h=0;
		return r;
	}
	return surf->clip_rect;
}
