/*
 * StateMachine.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "StateMachine.h"

StateMachine::StateMachine(State * state):state_(state) {

}

StateMachine::~StateMachine() {
	delete state_;
}

rapidxml::xml_node<> * StateMachine::getXMLNode(){
	rapidxml::xml_node<> *node = Entity::getXMLNode();
	node->name("StateMachine");

	return node;
}

void StateMachine::run(){
	run(state_);
}
void StateMachine::run(State * state){
	if (state->transitionStart()!=0)
		state->transitionStart()->run();

	State * next=state->run();

	if (state->transitionEnd()!=0)
		state->transitionEnd()->run();
	if (next!=0)
		run(next);
	else return;
}
