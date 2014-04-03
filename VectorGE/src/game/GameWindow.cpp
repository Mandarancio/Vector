/*
 * GameWindow.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameWindow.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_hints.h>


GameWindow::GameWindow(std::string title, Uint32 w, Uint32 h, bool resizable) {
	size_.width = w;
	size_.height = h;
	resizable_ = resizable;
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		//Error: The video can not be enabled... abort program...
	} else {
		if (resizable) {
			window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, w, h,
					SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		} else {
			window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
		}
		//ANTI ALIASING
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,2);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		TTF_Init();
		if (window_ == NULL) {
			//Error: you shall don't pass <img src="http://dadf.altervista.org/blog/wp-includes/images/smilies/icon_smile.gif" alt=":)" class="wp-smiley">  abort program
		} else {
			renderer_ = SDL_CreateRenderer(window_, -1,
					SDL_RENDERER_ACCELERATED);

			if (renderer_) {
				SDL_SetRenderDrawColor(renderer_, 0x00, 0xFF, 0xFF, 0xFF);

			}
		}
	}
	painter_ = new Painter(renderer_, size_);
}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	TTF_Quit();
	SDL_Quit();

}

SDL_Size GameWindow::getSize() {
	return size_;
}

SDL_Rect GameWindow::getBounds(){
	SDL_Rect r;
	r.w=size_.width;
	r.h=size_.height;
	return r;
}

Painter * GameWindow::painter() {
	return painter_;
}
