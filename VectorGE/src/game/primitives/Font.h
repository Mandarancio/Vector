/*
 * Font.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef FONT_H_
#define FONT_H_

#include "../../core/Entity.h"
#include <SDL2/SDL_ttf.h>
#include <string>

class Font: public Entity {
public:
	Font();
	Font(std::string font, int size);
	virtual ~Font();

	SDL_Surface * toSurface(std::string text,SDL_Color color);
	SDL_Rect textBounds(std::string text);

	std::string getName();
	int getSize();

	void scale(double s);

	Font * clone();

private:
	TTF_Font *font_;
	std::string ttf_file_;
	int size_;
	double scale_;
};

#endif /* FONT_H_ */
