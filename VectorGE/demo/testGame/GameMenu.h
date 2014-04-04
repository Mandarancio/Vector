/*
 * GameMenu.h
 *
 *  Created on: Apr 4, 2014
 *      Author: martino
 */

#ifndef GAMEMENU_H_
#define GAMEMENU_H_

#include <game/GameEntity.h>
#include <game/events/ActionListener.h>
#include <game/events/KeyListener.h>
#include <game/animation/Animation.h>

#include <core/stateMachine/State.h>

#include <string>
#include <map>

class GameMenu: public GameEntity, public State, public KeyListener {
public:
	GameMenu(StateListener * listener);
	virtual ~GameMenu();
	virtual void render(Painter * p);
	virtual void step(double dt);
	virtual void keyDown(SDL_KeyboardEvent * e);

	void addMenuItem(std::string title, ActionListener * listener);

private:
	void __init();
	void __paintItem(Painter * p,std::string item, int index);
	void __move(int dir);


	std::vector<std::string> menuItems_;
	std::vector<ActionListener*> menuListeners_;

	int __selected_item;
	SDL_Rect __selectBound;
	Animation * __selectAnimation;
	Font * __font;
};

#endif /* GAMEMENU_H_ */
