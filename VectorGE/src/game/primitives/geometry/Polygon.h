/*
 * Polygon.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "../../../core/Entity.h"
#include <vector>
#include <SDL2/SDL.h>

class Polygon: public Entity {
public:
	Polygon();
	Polygon(SDL_Point * vertex);
	Polygon(std::vector<SDL_Point> vertex);

	virtual ~Polygon();

	void addVertex(SDL_Point vertex);

private:
	std::vector<SDL_Point> vertex_;
};

#endif /* POLYGON_H_ */
