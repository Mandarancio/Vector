/*
 * Cell.h
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#ifndef CELL_H_
#define CELL_H_

#include "../../src/game/GameEntity.h"
#include "../../src/game/animation/Animation.h"
#include <string>

class Cell: public GameEntity {
public:
	Cell(int cx,int cy,int size,int padding,int val=2);
	virtual ~Cell();
	virtual void render(Painter * p);
	virtual void step(double dt);

	int getValue();
	SDL_Point getCell();
	int getCellX();
	int getCellY();

	bool compatible(Cell * c);
	bool sum(Cell * c);

	bool isLocked();
	void unlock();

	void move(int x,int y);
	bool isAnimating();
private:
	Color getColor();
	Color getPen();
	int value_;
	int cellX_,cellY_;
	std::string str_val;
	int padding_;
	bool lock_;

	EntityStatus present_;
	EntityStatus future_;
	Animation * animation_;
};

#endif /* CELL_H_ */
