/*
 * Painter.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef PAINTER_H_
#define PAINTER_H_
#include <SDL2/SDL_render.h>

#include "../core/Entity.h"
#include "primitives/Color.h"




class Painter: public Entity {
public:
	Painter(SDL_Renderer * rend);
	virtual ~Painter();
	void setPen(Color c);
	void setFill(Color c);

	void paintRect(int x,int y,int w,int h);
	void paintRect(SDL_Rect rect);

	void clearWindow();
	void renderToScreen();
private:
	SDL_Renderer * renderer;
	Color fill;
	Color pen;
};

#endif /* PAINTER_H_ */
