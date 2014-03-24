/*
 * Painter.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Painter.h"
#include "../support/Logging.h"
#include <iostream>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

Painter::Painter(SDL_Renderer * rend) :
		renderer(rend), fill(255, 255, 255, 255), pen(0, 0, 0, 255) {
	transformation = new Transformation();
	font = TTF_OpenFont("./resources/DejaVuSans.ttf", 20);
	if (font == 0) {
		logSDLError(std::cout, "TTF_OpenFont");
	}
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

void Painter::setFont(TTF_Font *f) {
	font = f;
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
	SDL_Surface *text_surface = TTF_RenderText_Solid(font, text.c_str(),
			pen.getSDLColor());
	if (text_surface != 0) {
		SDL_Rect r;
		r.x = x;
		r.y = y;
		r.w = text_surface->w;
		r.h = text_surface->h;
		transformation->applyTransformation(r.x, r.y);
		transformation->applySizeTransformation(r.w, r.h);
		SDL_Texture*texture = SDL_CreateTextureFromSurface(renderer,
				text_surface);
		SDL_RenderCopy(renderer, texture, NULL, &r);
	}
	else
	{
		logSDLError(std::cout, "TTF_RenderText_Solid");
	}
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
}
