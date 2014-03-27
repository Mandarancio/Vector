/*
 * WindowListener.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef WINDOWLISTENER_H_
#define WINDOWLISTENER_H_

#include <SDL2/SDL_events.h>

class WindowListener {
public:
	WindowListener();
	virtual ~WindowListener();
	void triggerEvent(SDL_Event *e);
protected:
	virtual void windowResized(SDL_WindowEvent *e);


};

#endif /* WINDOWLISTENER_H_ */
