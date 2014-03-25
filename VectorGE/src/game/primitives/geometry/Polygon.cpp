/*
 * Polygon.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#include "Polygon.h"

Polygon::Polygon() {

}

Polygon::Polygon(SDL_Point *vertex){
	int n;
	n = sizeof(vertex)/sizeof(SDL_Point);
	for (int i=0;i<n;i++)
		addVertex(vertex[i]);
}

Polygon::Polygon(std::vector<SDL_Point> vertex){
	for (int i=0;i<vertex.size();i++)
		addVertex(vertex[i]);
}

Polygon::~Polygon() {
}

void Polygon::addVertex(SDL_Point vertex){
	vertex_.push_back(vertex);
}

