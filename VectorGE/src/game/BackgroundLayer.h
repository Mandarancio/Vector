/*
 * BackgroundLayer.h
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#ifndef BACKGROUNDLAYER_H_
#define BACKGROUNDLAYER_H_

#include "GameEntity.h"
#include "primitives/Color.h"


class BackgroundLayer: public GameEntity {
public:
	BackgroundLayer(Color c=Color(255,255,255));
	virtual ~BackgroundLayer();
	virtual void render(Painter *p);

private:
	Color color_;
};

#endif /* BACKGROUNDLAYER_H_ */
