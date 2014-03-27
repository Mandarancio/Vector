/*
 * MouseListener.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "MouseListener.h"

MouseListener::MouseListener() {
	// TODO Auto-generated constructor stub

}

MouseListener::~MouseListener() {
	// TODO Auto-generated destructor stub
}

void MouseListener::triggerEvent(SDL_Event *event) {
	switch (event->type) {
	case SDL_MOUSEMOTION:
		mouseMotion((SDL_MouseMotionEvent*) event);
		break;
	case SDL_MOUSEBUTTONDOWN:
		mouseButtonDown((SDL_MouseButtonEvent*) event);
		break;
	case SDL_MOUSEBUTTONUP:
		mouseButtonUp((SDL_MouseButtonEvent*) event);
		break;
	case SDL_MOUSEWHEEL:
		mouseWheel((SDL_MouseWheelEvent*)event);
		break;
	}
}

void MouseListener::mouseMotion(SDL_MouseMotionEvent *e) {
}
void MouseListener::mouseButtonDown(SDL_MouseButtonEvent *e) {
}
void MouseListener::mouseButtonUp(SDL_MouseButtonEvent *e) {
}
void MouseListener::mouseWheel(SDL_MouseWheelEvent *e) {
}
