/*
 * Image.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "../../core/Entity.h"
#include "SDLSize.h"
#include <string>
#include <SDL2/SDL.h>

class Image : public Entity{
public:
	Image(std::string path);
	virtual ~Image();
	SDL_Surface * getImage();
	SDL_Texture * getTexture(SDL_Renderer * renderer);
	SDL_Size getSize();
	SDL_Rect getBounds();
private:
	std::string path_;
	SDL_Surface * image_;
	SDL_Size size_;
};

#endif /* IMAGE_H_ */
