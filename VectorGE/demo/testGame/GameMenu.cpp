/*
 * GameMenu.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#include "GameMenu.h"

GameMenu::GameMenu(StateListener * listener) :
		State(listener) {
	__selected_item = 0;
	__font = 0;
	__selectAnimation = 0;
}

GameMenu::~GameMenu() {
}

void GameMenu::render(Painter * p) {
	p->setColors(Color(69, 70, 64));
	p->paintRect(0, 0, p->getDisplaySize().width, p->getDisplaySize().height);
	p->setColors(Color(0, 0, 0, 180));
	p->paintRect(__selectBound);
	for (unsigned int i = 0; i < menuItems_.size(); i++) {
		__paintItem(p, menuItems_[i], i);
	}
}
void GameMenu::step(double dt) {
	if (__selectAnimation) {
		__selectBound = __selectAnimation->step(dt).bounds;
	}
}

void GameMenu::keyDown(SDL_KeyboardEvent * e) {
	if (!isKeyDown_) {
		switch (e->keysym.sym) {
		case (SDLK_UP):
			__move(-1);
			break;
		case (SDLK_DOWN):
			__move(1);
			break;
		}
	}
	KeyListener::keyDown(e);
}

void GameMenu::addMenuItem(std::string title, ActionListener * listener) {
	this->menuItems_.push_back(title);
	this->menuListeners_.push_back(listener);
	if (__font)
		__init();
}

void GameMenu::__paintItem(Painter * p, std::string item, int index) {
	if (__font == 0) {
		__font = p->getFont();
		__font->scale(2);
		__init();
	}
	__font->scale(2);

	SDL_Rect tb = p->getFont()->textBounds(item);
	tb.x = (bounds_.w - tb.w) / 2;
	tb.y = (index + 1) * (bounds_.h / (this->menuItems_.size() + 2));


	p->setPen(Color(255, 255, 255));
	p->paintText(item, tb.x, tb.y);
}

void GameMenu::__init() {
	if (!__font || menuItems_.size() == 0)
		return;
	__selectBound = __font->textBounds(menuItems_[__selected_item]);
	__selectBound.w += 20;
	__selectBound.h += 20;
	__selectBound.x = (bounds_.w - __selectBound.w) / 2;
	__selectBound.y = (__selected_item + 1)
			* (bounds_.h / (menuItems_.size() + 2)) - 10;
}

void GameMenu::__move(int dir) {
	if (__selected_item + dir >= 0
			&& (unsigned int)( __selected_item + dir )< menuItems_.size()) {
		__selected_item += dir;
		EntityStatus presStatus,nextStatus;
		presStatus.bounds = __selectBound;

		__font->scale(2);
		SDL_Rect next = __font->textBounds(menuItems_[__selected_item]);

		next.w += 20;
		next.h += 20;
		next.x = (bounds_.w - next.w) / 2;
		next.y = (__selected_item + 1) * (bounds_.h / (menuItems_.size() + 2)) - 10;
		nextStatus.bounds=next;
		if (__selectAnimation){
			delete __selectAnimation;
		}
		__selectAnimation=new Animation(presStatus,nextStatus,100);
	}
}
