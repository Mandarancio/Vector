/*
 * Cell.h
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#ifndef CELL_H_
#define CELL_H_

#include "../../src/game/GameEntity.h"
#include <string>

class Cell: public GameEntity {
public:
	Cell(int cx,int cy,int size,int padding,int val=2);
	virtual ~Cell();
	virtual void render(Painter * p);

	int getValue();
	SDL_Point getCell();
	int getCellX();
	int getCellY();

	bool compatible(Cell c);
	bool sum(Cell c);
private:
	Color getColor();
	int value_;
	int cellX_,cellY_;
	std::string str_val;
};

#endif /* CELL_H_ */
