/*
 * WindowListener.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#include "WindowListener.h"
#include <SDL2/SDL_video.h>

WindowListener::WindowListener() {
	// TODO Auto-generated constructor stub

}

WindowListener::~WindowListener() {
	// TODO Auto-generated destructor stub
}

void WindowListener::triggerEvent(SDL_Event *event) {

	switch (event->window.event) {
	case SDL_WINDOWEVENT_SHOWN:
		break;
	case SDL_WINDOWEVENT_HIDDEN:

		break;

	case SDL_WINDOWEVENT_MOVED:

		break;
	case SDL_WINDOWEVENT_RESIZED:
		windowResized((SDL_WindowEvent*) event);
		break;
	case SDL_WINDOWEVENT_MINIMIZED:
		break;
	case SDL_WINDOWEVENT_MAXIMIZED:
		break;
	case SDL_WINDOWEVENT_RESTORED:
		break;
	case SDL_WINDOWEVENT_ENTER:

		break;
	case SDL_WINDOWEVENT_LEAVE:
		break;
	case SDL_WINDOWEVENT_FOCUS_GAINED:

		break;
	case SDL_WINDOWEVENT_FOCUS_LOST:

		break;
	case SDL_WINDOWEVENT_CLOSE:
		break;
	default:

		break;
	}

}

void WindowListener::windowResized(SDL_WindowEvent *e) {
}
