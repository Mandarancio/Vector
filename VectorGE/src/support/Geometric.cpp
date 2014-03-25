/*
 * Geometric.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Geometric.h"



bool rectContains(SDL_Rect rect, SDL_Point p){
	if (p.x>=rect.x && p.x<=rect.x+rect.w){
		if (p.y>=rect.y && p.y<=rect.y+rect.h)
			return true;
		else
			return false;
	}
	return false;
}
