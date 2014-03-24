/*
 * Painter.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Painter.h"

#include <iostream>

Painter::Painter(SDL_Renderer * rend) :
		renderer(rend), fill(255, 255, 255, 255), pen(0, 0, 0, 255) {
	transformation=new Transformation();
}

Painter::~Painter() {
	// TODO Auto-generated destructor stub
}

void Painter::setPen(Color c) {
	pen = c;
}
void Painter::setFill(Color c) {
	fill = c;
}

void Painter::paintRect(Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	paintRect(r);
}

void Painter::paintRect(SDL_Rect rect) {

	transformation->applyTransformation(rect.x,rect.y);
	transformation->applySizeTransformation(rect.w,rect.h);


	SDL_SetRenderDrawColor(renderer, fill.red(), fill.green(), fill.blue(),
			fill.alpha());
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, pen.red(), pen.green(), pen.blue(),
			pen.alpha());
	SDL_RenderDrawRect(renderer, &rect);
}

void Painter::paintLine(int x1, int y1, int x2, int y2) {
	transformation->applyTransformation(x1,y1);
	transformation->applyTransformation(x2,y2);
	SDL_SetRenderDrawColor(renderer, pen.red(), pen.green(), pen.blue(),
			pen.alpha());
	SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
}


void Painter::paintPoint(int x, int y) {
	transformation->applyTransformation(x,y);
	SDL_SetRenderDrawColor(renderer, pen.red(), pen.green(), pen.blue(),
			pen.alpha());
	SDL_RenderDrawPoint(renderer,x,y);
}

void Painter::clearWindow() {
	SDL_RenderClear(renderer);
}
void Painter::renderToScreen() {
	SDL_RenderPresent(renderer);
}

void Painter::translate(int x,int y){
	transformation->translate(x,y);
}

void Painter::scale(double s){
	transformation->scale(s);
}
