/*
 * Board.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#include "Board.h"
#include <iostream>

Board::Board(int cellSize, int cellPadding) {
	cellPadding_ = cellPadding;
	cellSize_ = cellSize;
	boardSize_ = 4 * cellSize + 5 * cellPadding;
	bg = new Image("./resources/2048/bg.png");
	__active = true;
	generate();
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::render(Painter * p) {
	p->getFont()->scale(2);
	for (std::map<int, Cell*>::iterator i = cells_.begin(); i != cells_.end();
			++i) {
		if (i->second != NULL)
			i->second->render(p);
	}
	p->paintImage(*bg, 0, 0);

}

void Board::step(double dt) {
	GameEntity::step(dt);
	//do something
}

void Board::keyDown(SDL_KeyboardEvent * e) {
	if (!isKeyDown_ && __active) {
		switch (e->keysym.sym) {
		case (SDLK_UP):
			std::cout << "UP\n";
			moveUp();
			break;
		case (SDLK_DOWN):
			moveDown();
			std::cout << "DOWN\n";
			break;
		case (SDLK_LEFT):
			moveLeft();
			std::cout << "LEFT\n";
			break;
		case (SDLK_RIGHT):
			moveRight();
			std::cout << "RIGHT\n";
			break;
		}

	}
	KeyListener::keyDown(e);
}

bool Board::full() {
	return cells_.size() == 16;
}

bool Board::check() {
	return check(SDLK_UP) || check(SDLK_DOWN) || check(SDLK_LEFT)
			|| check(SDLK_RIGHT);
}

bool Board::check(SDL_Keycode dir) {
	return false;
}

bool Board::isBusy(int x, int y) {
	return cells_.find(y * 4 + x) != cells_.end() && getCell(x, y) != NULL;
}

void Board::generate() {
	std::vector<SDL_Point> freecell;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (!isBusy(x, y)) {
				freecell.push_back((SDL_Point ) { x, y });
			}
		}
	}
	if (freecell.size() > 0) {
		int sel = rand() % freecell.size();
		Cell * c = new Cell(freecell[sel].x, freecell[sel].y, cellSize_,
				cellPadding_);
		cells_[freecell[sel].x + freecell[sel].y * 4] = c;
	}
}

void Board::moveUp() {
	bool check = true;
	bool something = false;
	while (check) {
		check = false;
		for (int y = 1; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (getCell(x, y)) {
					if (!isBusy(x, y - 1)) {
						getCell(x, y)->move(x, y - 1);
						moveCell(x, y, x, y - 1);
						check = true;
						something = true;
					} else {
						if (getCell(x, y - 1)->sum(getCell(x, y))) {
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							delete c;
							something = true;

						}
					}
				}
			}
		}
	}
	if (something)
		generate();
}

void Board::moveDown() {
	bool check = true;
	bool something = false;

	while (check) {
		check = false;
		for (int y = 2; y >=0; y--) {
			for (int x = 0; x < 4; x++) {
				if (getCell(x, y)) {
					if (!isBusy(x, y + 1)) {
						getCell(x, y)->move(x, y + 1);
						moveCell(x, y, x, y + 1);
						check = true;
						something = true;
					} else {
						if (getCell(x, y + 1)->sum(getCell(x, y))) {
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							delete c;
							something = true;
						}
					}
				}
			}
		}
	}
	if (something)
		generate();
}

void Board::moveLeft() {
	bool check = true;
	bool something = false;

	while (check) {
		check = false;
		for (int x = 1; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (getCell(x, y)) {
					if (!isBusy(x - 1, y)) {
						getCell(x, y)->move(x - 1, y);
						moveCell(x, y, x - 1, y);
						check = true;
						something = true;
					} else {
						if (getCell(x - 1, y)->sum(getCell(x, y))) {
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							delete c;
							something = true;
						}
					}
				}
			}
		}
	}
	if (something)
		generate();
}
void Board::moveRight() {
	bool check = true;
	bool something = false;

	while (check) {
		check = false;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 4; y++) {
				if (getCell(x, y)) {
					if (!isBusy(x + 1, y)) {
						getCell(x, y)->move(x + 1, y);
						moveCell(x, y, x + 1, y);
						check = true;
						something = true;
					} else {
						if (getCell(x + 1, y)->sum(getCell(x, y))) {
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							delete c;
							something = true;
						}
					}
				}
			}
		}
	}
	if (something)
		generate();
}

Cell * Board::getCell(int x, int y) {
	return cells_[x + y * 4];
}

void Board::moveCell(int x0, int y0, int x1, int y1) {
	Cell * c = getCell(x0, y0);
	cells_.erase(x0 + y0 * 4);
	cells_[x1 + y1 * 4] = c;
}

