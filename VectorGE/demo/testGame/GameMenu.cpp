/*
 * GameMenu.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#include "GameMenu.h"

GameMenu::GameMenu(StateListener * listener):State(listener) {

}

GameMenu::~GameMenu() {
}

void GameMenu::render(Painter * p) {
	p->setColors(Color(69,70, 64));
	p->paintRect(0, 0, p->getDisplaySize().width, p->getDisplaySize().height);
}
void GameMenu::step(double dt) {

}

void GameMenu::addMenuItem(std::string title, ActionListener * listener){
	this->menuItems_[title]=listener;
}
