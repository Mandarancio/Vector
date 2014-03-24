/*
 * Painter.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Painter.h"
#include "../support/Logging.h"
#include <iostream>

Painter::Painter(SDL_Renderer * rend) :
		renderer(rend), fill(255, 255, 255, 255), pen(0, 0, 0, 255) {
	transformation = new Transformation();
	font = new Font();
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

void Painter::setFont(Font *f) {
	delete font;
	font = new Font(f->getName(),f->getSize()*transformation->getScale());

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

	transformation->applyTransformation(rect.x, rect.y);
	transformation->applySizeTransformation(rect.w, rect.h);

	SDL_SetRenderDrawColor(renderer, fill.red(), fill.green(), fill.blue(),
			fill.alpha());
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, pen.red(), pen.green(), pen.blue(),
			pen.alpha());
	SDL_RenderDrawRect(renderer, &rect);
}

void Painter::paintLine(int x1, int y1, int x2, int y2) {
	transformation->applyTransformation(x1, y1);
	transformation->applyTransformation(x2, y2);
	SDL_SetRenderDrawColor(renderer, pen.red(), pen.green(), pen.blue(),
			pen.alpha());
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Painter::paintPoint(int x, int y) {
	transformation->applyTransformation(x, y);
	SDL_SetRenderDrawColor(renderer, pen.red(), pen.green(), pen.blue(),
			pen.alpha());
	SDL_RenderDrawPoint(renderer, x, y);
}

void Painter::paintText(std::string text, int x, int y) {
	SDL_Surface * surface = font->toSurface(text, pen.getSDLColor());
	SDL_Rect r = font->textBounds(text);
	r.x = x;
	r.y = y;
	transformation->applyTransformation(r.x, r.y);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == 0) {
		logSDLError(std::cout, "CreateTexture");
	}
	SDL_RenderCopy(renderer, texture, NULL, &r);
}

void Painter::paintTexture(SDL_Texture *texture,SDL_Rect bounds){
	transformation->applyTransformation(bounds.x,bounds.y);
	transformation->applySizeTransformation(bounds.w,bounds.h);
	SDL_RenderCopy(renderer,texture,NULL,&bounds);
}

void Painter::clearWindow() {
	SDL_RenderClear(renderer);
}
void Painter::renderToScreen() {
	SDL_RenderPresent(renderer);
}

void Painter::translate(int x, int y) {
	transformation->translate(x, y);
}

void Painter::scale(double s) {
	transformation->scale(s);
	font=new Font(font->getName(),font->getSize()*s);
}

void Painter::save(){
	transformationHistory.push_back(transformation->clone());
}
void Painter::restore(){
	if (transformationHistory.size()>0){
		transformation=transformationHistory.back()->clone();
		transformationHistory.pop_back();
	}
}
