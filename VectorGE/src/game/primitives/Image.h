/*
 * Image.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include <SDL2/SDL.h>

class Image {
public:
	Image(std::string path);
	virtual ~Image();
	SDL_Surface * getImage();
	SDL_Texture * getTexture(SDL_Renderer * renderer);

private:
	std::string path_;
	SDL_Surface * image_;
};

#endif /* IMAGE_H_ */
