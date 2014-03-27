/*
 * MouseListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef MOUSELISTENER_H_
#define MOUSELISTENER_H_

#include <SDL2/SDL_events.h>
class MouseListener {
public:
	MouseListener();
	virtual ~MouseListener();
	void triggerEvent(SDL_Event *event);
protected:
	virtual void mouseMotion(SDL_MouseMotionEvent *e);
	virtual void mouseButtonDown(SDL_MouseButtonEvent *e);
	virtual void mouseButtonUp(SDL_MouseButtonEvent *e);
	virtual void mouseWheel(SDL_MouseWheelEvent *e);
};

#endif /* MOUSELISTENER_H_ */
