/*
 * Geometric.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Geometric.h"

#include <math.h>

bool rectContains(SDL_Rect rect, SDL_Point p){
	if (p.x>=rect.x && p.x<=rect.x+rect.w){
		if (p.y>=rect.y && p.y<=rect.y+rect.h)
			return true;
		else
			return false;
	}
	return false;
}

bool rectContains(SDL_Rect rect, int x,int y){
	SDL_Point p;
	p.x=x;
	p.y=y;
	return rectContains(rect,p);
}


bool rectContains(SDL_Rect rectA, SDL_Rect rectB){
	return (rectContains(rectA,rectB.x,rectB.y) &&
			rectContains(rectA,rectB.x+rectB.w,rectB.y) &&
			rectContains(rectA,rectB.x+rectB.w,rectB.y+rectB.h) &&
			rectContains(rectA,rectB.x,rectB.y+rectB.h));
}

bool rectIntersect(SDL_Rect rectA, SDL_Rect rectB){
	if (rectContains(rectA,rectB.x,rectB.y) ||
			rectContains(rectA,rectB.x+rectB.w,rectB.y)||
			rectContains(rectA,rectB.x+rectB.w,rectB.y+rectB.h) ||
			rectContains(rectA,rectB.x,rectB.y+rectB.h)){
		return true;
	}
	int x1,y1,x2,y2;
	int w1,h1;
	x1=(rectA.x<rectB.x? rectA.x:rectB.x);
	w1=(rectA.x<rectB.x? rectA.w:rectB.w);
	x2=(rectA.x>=rectB.x? rectA.x:rectB.x);
	y1=(rectA.y<rectB.y? rectA.y:rectB.y);
	h1=(rectA.y<rectB.y? rectA.h:rectB.h);
	y2=(rectA.y>=rectB.y? rectA.y:rectB.y);
	int dx=x2-x1;
	int dy=y2-y1;
	return (dx<w1 && dy<h1);

}
