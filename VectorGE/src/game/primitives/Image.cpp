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
		size_.width=0;
		size_.height=0;
	}else{
		size_.width=image_->w;
		size_.height=image_->h;
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

SDL_Size Image::getSize(){
	return size_;
}
SDL_Rect Image::getBounds(){
	SDL_Rect r;
	r.w=size_.width;
	r.h=size_.height;
	return r;
}
