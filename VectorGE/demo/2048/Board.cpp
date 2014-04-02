/*
 * Board.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: martino
 */

#include "Board.h"
#include <iostream>
#include <string>

Board::Board(int cellSize, int cellPadding) {
	cellPadding_ = cellPadding;
	cellSize_ = cellSize;
	boardSize_ = 4 * cellSize + 5 * cellPadding;
	bounds_.w = boardSize_;
	bounds_.h = boardSize_;
	bgImage_ = new Image("./resources/2048/bg.png");
	__active = true;
	generate();
	__gameOver = false;
	__gameWin = false;
	__points = 0;
	__point_texture = 0;
}

Board::~Board() {
	delete bgImage_;
	for (std::map<int, Cell*>::iterator i = cells_.begin(); i != cells_.end();
			++i) {
		if (i->second != NULL)
			delete i->second;
	}
	for (int i = 0; i < toDelete_.size(); i++) {
		delete toDelete_[i];
	}
	if (__point_texture!=0){
		SDL_DestroyTexture(__point_texture);
	}
	toDelete_.clear();
	cells_.clear();
}

void Board::render(Painter * p) {
	for (int i = 0; i < toDelete_.size(); i++) {
		toDelete_[i]->render(p);
	}
	for (std::map<int, Cell*>::iterator i = cells_.begin(); i != cells_.end();
			++i) {
		if (i->second != NULL)
			i->second->render(p);
	}

	p->paintImage(*bgImage_, 0, 0);
	p->setFill(Color());
	p->setPen(Color());
	p->paintRect(0, this->boardSize_, this->boardSize_, 40);
	if (__point_texture == 0) {
		__ss << __points;
		std::string val = __ss.str();
		__ss.str("");
		p->getFont()->scale(1.1);
		p->setPen(Color(255, 255, 255));
		__point_bounds=p->getFont()->textBounds(val);
		__point_texture=p->textToTexture(val);
		__point_bounds.x=5;
		__point_bounds.y=boardSize_+(40-__point_bounds.h)/2;
	}
	p->paintTexture(__point_texture,__point_bounds);

	if (__gameWin || __gameOver) {
		p->setFill(Color(0, 0, 0, 200));
		p->setPen(p->getFill());
		p->paintRect(0, 0, boardSize_, boardSize_);
		std::string message = (__gameOver ? "Game over!" : "You win!");
		p->getFont()->scale(2.0);
		p->setPen(Color(255, 255, 255));
		SDL_Rect tb = p->getFont()->textBounds(message);
		p->paintText(message, (boardSize_ - tb.w) / 2, (boardSize_ - tb.h) / 2);
	}
}

void Board::step(double dt) {
	GameEntity::step(dt);
	for (std::map<int, Cell*>::iterator i = cells_.begin(); i != cells_.end();
			++i) {
		if (i->second != NULL)
			i->second->step(dt);
	}
	if (toDelete_.size() > 0) {
		bool finish = true;
		for (int i = 0; i < toDelete_.size(); i++) {
			if (toDelete_[i]->isAnimating()) {
				toDelete_[i]->step(dt);
				finish = false;
			}
		}
		if (finish) {
			for (int i = 0; i < toDelete_.size(); i++) {
				delete toDelete_[i];
			}
			toDelete_.clear();
		}
	}
}

void Board::keyDown(SDL_KeyboardEvent * e) {
	if (!isKeyDown_ && __active) {
		switch (e->keysym.sym) {
		case (SDLK_UP):
			moveUp();
			break;
		case (SDLK_DOWN):
			moveDown();
			break;
		case (SDLK_LEFT):
			moveLeft();
			break;
		case (SDLK_RIGHT):
			moveRight();
			break;
		}

	}
	KeyListener::keyDown(e);
}

bool Board::full() {
	if (cells_.size() == 16) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (getCell(x, y) != NULL) {
					if (getCell(x, y)->compatible(getCell(x - 1, y)))
						return false;
					if (getCell(x, y)->compatible(getCell(x + 1, y)))
						return false;
					if (getCell(x, y)->compatible(getCell(x, y - 1)))
						return false;
					if (getCell(x, y)->compatible(getCell(x, y + 1)))
						return false;
				} else
					return false;
			}
		}
		return true;
	}
	return false;
}

bool Board::isBusy(int x, int y) {
	return cells_.find(y * 4 + x) != cells_.end() && getCell(x, y) != NULL;
}

void Board::generate() {
	SDL_DestroyTexture(__point_texture);
	__point_texture = 0;

	std::vector<SDL_Point> freecell;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (!isBusy(x, y)) {
				freecell.push_back((SDL_Point ) { x, y });
			} else {
				if (getCell(x, y)->getValue() == 2048) {
					__gameWin = true;
					__active = false;
				}
				getCell(x, y)->unlock();
			}
		}
	}

	if (freecell.size() > 0) {
		int sel = rand() % freecell.size();
		Cell * c = new Cell(freecell[sel].x, freecell[sel].y, cellSize_,
				cellPadding_);
		cells_[freecell[sel].x + freecell[sel].y * 4] = c;
	}
	if (full() && !__gameWin) {
		__gameOver = true;
		__active = false;
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
							__points += getCell(x, y - 1)->getValue();
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							c->move(x, y - 1);
							toDelete_.push_back(c);
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
		for (int y = 2; y >= 0; y--) {
			for (int x = 0; x < 4; x++) {
				if (getCell(x, y)) {
					if (!isBusy(x, y + 1)) {
						getCell(x, y)->move(x, y + 1);
						moveCell(x, y, x, y + 1);
						check = true;
						something = true;
					} else {
						if (getCell(x, y + 1)->sum(getCell(x, y))) {
							__points += getCell(x, 1 + y)->getValue();
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							c->move(x, y + 1);
							toDelete_.push_back(c);
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
							__points += getCell(x - 1, y)->getValue();
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							c->move(x - 1, y);
							toDelete_.push_back(c);
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
		for (int x = 2; x > -1; x--) {
			for (int y = 0; y < 4; y++) {
				if (getCell(x, y)) {
					if (!isBusy(x + 1, y)) {
						getCell(x, y)->move(x + 1, y);
						moveCell(x, y, x + 1, y);
						check = true;
						something = true;
					} else {
						if (getCell(x + 1, y)->sum(getCell(x, y))) {
							__points += getCell(x + 1, y)->getValue();
							Cell * c = getCell(x, y);
							cells_.erase(x + y * 4);
							c->move(x + 1, y);
							toDelete_.push_back(c);
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
	if (x < 0 || x > 3)
		return 0;
	if (y < 0 || y > 3)
		return 0;
	return cells_[x + y * 4];
}

void Board::moveCell(int x0, int y0, int x1, int y1) {
	Cell * c = getCell(x0, y0);
	cells_.erase(x0 + y0 * 4);
	cells_[x1 + y1 * 4] = c;
}

