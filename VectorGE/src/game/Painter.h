/*
 * Painter.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef PAINTER_H_
#define PAINTER_H_
#include <SDL2/SDL_render.h>
#include <vector>
#include <string>

#include "../core/Entity.h"
#include "primitives/Color.h"
#include "primitives/Transformation.h"
#include "primitives/Font.h"

class Painter: public Entity {
public:
	Painter(SDL_Renderer * rend);
	virtual ~Painter();
	void setPen(Color c);
	void setFill(Color c);
	void setFont(Font * f);

	void paintRect(Sint16 x,Sint16 y,Uint16 w,Uint16 h);
	void paintRect(SDL_Rect rect);

	void paintLine(int x1,int y1,int x2,int y2);
	void paintPoint(int x,int y);

	void paintText(std::string text,int x,int y);

	void paintTexture(SDL_Texture *texture,SDL_Rect bounds);

	void clearWindow();
	void renderToScreen();

	void translate(int x,int y);
	void scale(double s);

	void save();
	void restore();

private:
	std::vector<Transformation*> 	transformationHistory;
	Transformation * 				transformation;
	SDL_Renderer * 					renderer;
	Color 							fill;
	Color 							pen;
	Font *							font;
};

#endif /* PAINTER_H_ */
