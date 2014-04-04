/*
 * GameMaster.cpp
 *
 *  Created on: 03/apr/2014
 *      Author: martino
 */

#include "GameMaster.h"
#include <iostream>
#include <string>

#include "GameMenu.h"

#define START "Start game"
#define EXIT "Exit"
#define SETTINGS "Settings"

GameMaster::GameMaster(GameScene * scene) :
		StateMachine(NULL) {
	scene_ = scene;
	IntroAnimation * ia = new IntroAnimation(this, scene->getDisplayBounds());
	current_ = ia;
	state_ = ia;
	scene->addEntity(current_);
}

GameMaster::~GameMaster() {
}

void GameMaster::ended(int id) {

	std::cout << "ended " << id << "\n";
	scene_->clear();
	std::cout << "removed current element\n";
	if (id == 0) {
		std::cout << "go to main menu\n";
		__initMenu();
	}
}

void GameMaster::actionPerfoormed(Action* a) {
	std::string cmd = a->getCommand();
	std::size_t found = cmd.find("menu:");
	if (found != std::string::npos) {
		cmd = cmd.substr(5, cmd.size() - 5);
		if (cmd.compare(EXIT) == 0) {
			std::cout << "Exit from game!\n";
			scene_->quit();
		} else if (cmd.compare(START) == 0) {
			std::cout << "Start a game\n";
			scene_->clear();
			__initGame();
		} else if (cmd.compare(SETTINGS) == 0) {
			std::cout << "Settings\n";
		}

	}
}

void GameMaster::__initMenu() {
	GameMenu * menu = new GameMenu(this);
	menu->setBounds(scene_->getDisplayBounds());

	menu->addMenuItem(START, this);
	menu->addMenuItem(SETTINGS, this);
	menu->addMenuItem(EXIT, this);

	scene_->addKeyListener(menu);
	current_ = menu;
	state_ = menu;
	scene_->addEntity(menu);
}

void GameMaster::__initGame(){

}
