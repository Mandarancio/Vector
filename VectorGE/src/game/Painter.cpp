/*
 * Painter.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Painter.h"

Painter::Painter(SDL_Renderer * rend) :
		renderer(rend),fill(255,255,255,255),pen(0,0,0,255) {
}

Painter::~Painter() {
	// TODO Auto-generated destructor stub
}

void Painter::setPen(Color c){
	pen=c;
}
void Painter::setFill(Color c){
	fill=c;
}

void Painter::paintRect(int x, int y, int w, int h){
	SDL_Rect r;
	r.x=x;
	r.y=y;
	r.w=w;
	r.h=h;
	paintRect(r);
}

void Painter::paintRect(SDL_Rect rect){
	SDL_SetRenderDrawColor(renderer,fill.red(),fill.green(),fill.blue(),fill.alpha());
	SDL_RenderFillRect(renderer,&rect);
	SDL_SetRenderDrawColor(renderer,pen.red(),pen.green(),pen.blue(),pen.alpha());
	SDL_RenderDrawRect(renderer,&rect);

}

void Painter::clearWindow(){
    SDL_RenderClear(renderer);
}
void Painter::renderToScreen(){
	SDL_RenderPresent(renderer);
}
