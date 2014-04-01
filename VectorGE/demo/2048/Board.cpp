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

	__active = true;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::render(Painter * p) {
	p->getFont()->scale(2);
//	for (int i = 0; i < cells_.size(); i++) {
//		cells_[i].render(p);
//	}
	p->setFill(Color(234, 226, 166));
	p->setPen(p->getFill());
	for (int i = 0; i <= 4; i++) {
		p->paintRect(0, i * (cellPadding_ + cellSize_), boardSize_,
				cellPadding_);
		p->paintRect(i * (cellPadding_ + cellSize_), 0, cellPadding_,
				boardSize_);
	}

}

void Board::keyDown(SDL_KeyboardEvent * e) {
	if (!isKeyDown_ && __active) {
		switch (e->keysym.sym) {
		case (SDLK_UP):
			std::cout << "UP\n";
			break;
		case (SDLK_DOWN):
			std::cout << "DOWN\n";
			break;
		case (SDLK_LEFT):
			std::cout << "LEFT\n";
			break;
		case (SDLK_RIGHT):
			std::cout << "RIGHT\n";
			break;
		}

	}
	KeyListener::keyDown(e);
}

bool Board::full(){
	return cells_.size()==16;
}


bool Board::check(){
	return check(SDLK_UP) || check(SDLK_DOWN) || check(SDLK_LEFT) || check(SDLK_RIGHT);
}

bool Board::check(SDL_Keycode dir){
	return false;
}

bool Board::isBusy(int x,int y){
	SDL_Point p=(SDL_Point){x,y};
	return cells_.count(p);
}


void Board::generate(){
	std::vector<SDL_Point> freecell;
	for (int x=0;x<4;x++){
		for (int y=0;y<4;y++){
			if (!isBusy(x,y)){
				freecell.push_back((SDL_Point){x,y});
			}
		}
	}

}
