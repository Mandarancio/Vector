/*
 * KeyListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef KEYLISTENER_H_
#define KEYLISTENER_H_

#include <SDL2/SDL_events.h>

class KeyListener {
public:
	KeyListener();
	virtual ~KeyListener();
	void triggerEvent(SDL_Event *event);
	virtual void keyUp(SDL_KeyboardEvent *e);
	virtual void keyDown(SDL_KeyboardEvent * e);
};

#endif /* KEYLISTENER_H_ */
