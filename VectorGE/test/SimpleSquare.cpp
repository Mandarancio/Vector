/*
 * SimpleSquare.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "SimpleSquare.h"

SimpleSquare::SimpleSquare() :
		GameEntity() {
	pos.x = 100;
	pos.y = 100;
}

SimpleSquare::~SimpleSquare() {
}

void SimpleSquare::render(Painter * p) {
	p->paintRect(pos.x - 5, pos.y - 5, 10, 10);
}
void SimpleSquare::step(double dt, SDL_Event event) {
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			pos.x--;
			break;
		case SDLK_RIGHT:
			pos.x++;
			break;
		case SDLK_UP:
			pos.y--;
			break;
		case SDLK_DOWN:
			pos.y++;
			break;
		}
		break;
	}
}

