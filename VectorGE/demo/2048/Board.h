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
#include "../../src/game/primitives/Image.h"

#include "Cell.h"

#include <map>

class Board: public GameEntity, public KeyListener {
public:
	Board(int cellSize, int cellPadding);
	virtual ~Board();
	virtual void render(Painter * p);
	virtual void step(double dt);
	virtual void keyDown(SDL_KeyboardEvent * e);

private:
	bool full();
	bool check();
	bool check(SDL_Keycode dir);
	int checkPos(SDL_Keycode dir);
	bool isBusy(int x, int y);

	void generate();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	Cell * getCell(int x, int y);

	void moveCell(int x0, int y0, int x1, int y1);

	int cellSize_;
	int cellPadding_;
	int boardSize_;

	Image * bg;

	std::map<int, Cell*> cells_;
	std::vector<Cell * > toDelete_;

	bool __active;
};

#endif /* BOARD_H_ */
