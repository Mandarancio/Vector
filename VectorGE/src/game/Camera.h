/*
 * Camera.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "../core/Entity.h"
#include "Painter.h"

class Camera : public Entity {
public:
	Camera(Painter *p);
	virtual ~Camera();
	Painter * getPainter();
	void translate(int x,int y);
private:
	Painter * painter;
	};

#endif /* CAMERA_H_ */
