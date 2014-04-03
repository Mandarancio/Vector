/*
 * GameWindow.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <SDL2/SDL.h>
#include <string>

#include "Painter.h"
#include "primitives/SDLSize.h"


class GameWindow {
public:
	GameWindow(std::string title="title",Uint32 w=800,Uint32 h=600,bool resizable=false);
	virtual ~GameWindow();
	SDL_Size getSize();
	SDL_Rect getBounds();
	Painter * painter();
private:

	SDL_Window* window_;
	SDL_Renderer* renderer_;
	SDL_Size size_;
	Painter * painter_;
	bool resizable_;
};

#endif /* GAMEWINDOW_H_ */
