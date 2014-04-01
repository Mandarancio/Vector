/*
 * KeyListener.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "KeyListener.h"

KeyListener::KeyListener() {
	isKeyDown_=false;
}

KeyListener::~KeyListener() {
	// TODO Auto-generated destructor stub
}

void KeyListener::triggerEvent(SDL_Event *event){
	switch (event->type){
	case SDL_KEYUP:
		keyUp((SDL_KeyboardEvent*)event);
		break;
	case SDL_KEYDOWN:
		keyDown((SDL_KeyboardEvent*)event);
		break;
	}
}

void KeyListener::keyUp(SDL_KeyboardEvent *e){
	isKeyDown_=false;
}
void KeyListener::keyDown(SDL_KeyboardEvent * e){
	isKeyDown_=true;
}
