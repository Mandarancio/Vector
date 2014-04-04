/*
 * GameMenu.h
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#ifndef GAMEMENU_H_
#define GAMEMENU_H_

#include <game/GameEntity.h>
#include <core/stateMachine/State.h>
#include <game/events/ActionListener.h>

#include <string>
#include <map>

class GameMenu: public GameEntity, public State {
public:
	GameMenu(StateListener * listener);
	virtual ~GameMenu();
	virtual void render(Painter * p);
	virtual void step(double dt);

	void addMenuItem(std::string title, ActionListener * listener);

private:
	std::map<std::string, ActionListener*> menuItems_;

};

#endif /* GAMEMENU_H_ */
