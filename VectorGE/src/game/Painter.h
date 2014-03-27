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
#include "primitives/SDLSize.h"
#include "primitives/Image.h"
#include "primitives/geometry/Shape.h"
#include "primitives/geometry/Line.h"
#include "primitives/geometry/Polygon.h"

#include "events/WindowListener.h"

class Painter: public Entity,public WindowListener {
public:
	Painter(SDL_Renderer * rend,SDL_Size size);
	virtual ~Painter();
	void setPen(Color c);
	void setFill(Color c);

	void setFont(Font * f);
	Font * getFont();

	Color getFill();
	Color getPen();

	void paintRect(Sint16 x,Sint16 y,Uint16 w,Uint16 h);
	void paintRect(SDL_Rect rect);

	void paintCircle(int x, int y,Uint16 r);
	void paintOval(int x,int y,Uint16 rx,Uint16 ry);

	void paintLine(int x1,int y1,int x2,int y2);
	void paintLine(Line  l);
	void paintPoint(int x,int y);

	void paintText(std::string text,int x,int y);

	void paintImage(Image img,SDL_Rect bounds);
	void paintImage(Image img,SDL_Point pos);
	void paintImage(Image img,int x,int y);

	void paintTexture(SDL_Texture *texture,SDL_Rect bounds);

	void paintShape(Shape * shape);
	void paintPolygon(Polygon p);

	void clearWindow();
	void renderToScreen();

	void translate(int x,int y);
	void scale(double s);

	void save();
	void restore();

	void clearTransaltion();

	SDL_Size getDisplaySize();
	SDL_Point getDisplayCenter();

	SDL_Rect getClip();
	void setClip(SDL_Rect clip);
	void setClip(int x,int y,int w,int h);
	void removeClip();

protected:
	virtual void windowResized(SDL_WindowEvent *e);

private:

	std::vector<Transformation*> 	transformationHistory;
	Transformation * 				transformation;
	SDL_Renderer * 					renderer;
	Color 							fill;
	Color							pen;
	Font *							font;
	SDL_Size						displaySize;
	SDL_Point						displayCenter;
	SDL_Rect 						clip;
};

#endif /* PAINTER_H_ */
