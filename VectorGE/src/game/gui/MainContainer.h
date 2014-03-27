/*
 * MainContainer.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef MAINCONTAINER_H_
#define MAINCONTAINER_H_

#include "Container.h"
#include "../events/WindowListener.h"

class MainContainer: public Container, public WindowListener {
public:
	MainContainer();
	virtual ~MainContainer();
	virtual void windowResized(SDL_WindowEvent *e);

};

#endif /* MAINCONTAINER_H_ */
