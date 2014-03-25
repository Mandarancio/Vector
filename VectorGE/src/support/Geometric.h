/*
 * Geometric.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef GEOMETRIC_H_
#define GEOMETRIC_H_

#include <SDL2/SDL.h>

bool rectContains(SDL_Rect rect, SDL_Point p);
bool rectContains(SDL_Rect rect, int x,int y);

bool rectContains(SDL_Rect rectA, SDL_Rect rectB);
bool rectIntersect(SDL_Rect rectA, SDL_Rect rectB);
#endif /* GEOMETRIC_H_ */
