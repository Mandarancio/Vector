/*
 * BackgroundLayer.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef BACKGROUNDLAYER_H_
#define BACKGROUNDLAYER_H_

#include "GameEntity.h"


class BackgroundLayer: public GameEntity {
public:
	BackgroundLayer();
	virtual ~BackgroundLayer();
	virtual void render(Painter *p);
};

#endif /* BACKGROUNDLAYER_H_ */
