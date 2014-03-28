/*
 * GameEntity.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

#include <Box2D/Box2D.h>

#include "../core/Entity.h"
#include "Painter.h"

struct EntityStatus{
	SDL_Rect bounds;
	float angle;
	float scale;
	float opacity;
};

class GameEntity: public Entity {
public:
	GameEntity();
	virtual ~GameEntity();
	virtual void render(Painter * p)=0;
	virtual void step(double dt);

	SDL_Rect getBounds();
	SDL_Point getLocation();
	SDL_Size getSize();

	int getX();
	int getY();

	int getWidth();
	int getHeight();

	float getAngle();
	float getScale();
	float getOpacity();

	void setBounds(SDL_Rect r);
	void setBounds(int x, int y, int w, int h);

	void setSize(SDL_Size size);
	void setSize(int w, int h); //BASIC Function

	void setLocation(SDL_Point p);
	void setLocation(int x, int y); //BASIC Function

	void setAngle(float angle);
	void setScale(float scale);
	void setOpacity(float opacity);

	EntityStatus getCurrentStatus();
	void setCurrentStatus(EntityStatus status);
protected:
	SDL_Rect bounds_;
	float angle_;
	float scale_;
	float opacity_;

};

#endif /* GAMEENTITY_H_ */
