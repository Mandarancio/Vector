/*
 * Camera.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "../core/Entity.h"

#include <SDL2/SDL.h>

class Camera : public Entity {
public:
	Camera(SDL_Renderer *renderer);
	virtual ~Camera();

private:
	SDL_Renderer * renderer;

};

#endif /* CAMERA_H_ */
