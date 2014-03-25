/*
 * Image.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Image.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../../support/Logging.h"

Image::Image(std::string path) {
	path_=path;
	image_=IMG_Load(path.c_str());
	if (image_==NULL){
		logSDLError(std::cout,"IMG_Load");
	}
}

Image::~Image() {
	// TODO Auto-generated destructor stub
}

SDL_Surface * Image::getImage(){
	return image_;
}
SDL_Texture * Image::getTexture(SDL_Renderer * renderer){
	SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,image_);
	if (texture==NULL){
		logSDLError(std::cout,"SDL_CreateTexture");
	}
	return texture;
}
