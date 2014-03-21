/*
 * GameWindow.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <string>

class GameWindow {
public:
	GameWindow(std::string title="title");
	virtual ~GameWindow();
	SDL_Renderer * renderer();
private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;
};

#endif /* GAMEWINDOW_H_ */
