/*
 * GameWindow.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameWindow.h"

#include <SDL2/SDL2_gfxPrimitives.h>
GameWindow::GameWindow(std::string title) {
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		//Error: The video can not be enabled... abort program...
	} else {
		window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
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

}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

SDL_Renderer * GameWindow::renderer() {
	return renderer_;
}
