/*
 * Armature.h
 *
 *  Created on: 30/mar/2014
 *      Author: martino
 */

#ifndef ARMATURE_H_
#define ARMATURE_H_

#include "../GameEntity.h"
#include "../events/MouseListener.h"
#include "../primitives/geometry/BezierPath.h"

#include <vector>

class ArmaturePoint  : public GameEntity, public MouseListener{
public:
	ArmaturePoint(SDL_Point pos);
	virtual ~ArmaturePoint();

	virtual void render(Painter * p);

	virtual void mouseMotion(SDL_MouseMotionEvent *e);
	virtual void mouseButtonDown(SDL_MouseButtonEvent *e);
	virtual void mouseButtonUp(SDL_MouseButtonEvent *e);

	void addLinkedEntity(GameEntity * ge);
private:
	void _updateLinkedEntities(int dx,int dy);
	std::vector<GameEntity*> linkedEntities_;
	bool __mouseDown;
};

class ArmatureLine : public GameEntity{
public:
	ArmatureLine(ArmaturePoint * a, ArmaturePoint * c_a,ArmaturePoint * c_b,ArmaturePoint *b);
	virtual ~ArmatureLine();
	virtual void render(Painter * p);


	void addLinkedEntity(GameEntity * ge);
	void updateLinkedEntities();

private:
	ArmaturePoint * a,*b,*c_b,*c_a;
	BezierCurve * curve;

	std::vector<GameEntity*> linkedEntities_;

};

#endif /* ARMATURE_H_ */
