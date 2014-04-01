/*
 * Board.h
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "../../src/game/GameEntity.h"
#include "../../src/game/events/KeyListener.h"

#include "Cell.h"

#include <map>

class Board: public GameEntity,public KeyListener {
public:
	Board(int cellSize, int cellPadding);
	virtual ~Board();
	virtual void render(Painter * p);
	virtual void keyDown(SDL_KeyboardEvent * e);


private:
	bool full();
	bool check();
	bool check(SDL_Keycode dir);
	bool isBusy(int x,int y);

	void generate();

	int cellSize_;
	int cellPadding_;
	int boardSize_;

	std::map<SDL_Point,Cell> cells_;

	bool __active;
};

#endif /* BOARD_H_ */
