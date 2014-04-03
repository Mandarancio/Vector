/*
 * StateMachine.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include "State.h"

class StateMachine: public Entity, public StateListener {
public:
	StateMachine(State * state=0);
	virtual ~StateMachine();
	rapidxml::xml_node<> * getXMLNode();
	void run();
	State *currentState();
	virtual void  ended(int id);

protected:
	State * state_;
	void run(State * state);

};

#endif /* STATEMACHINE_H_ */
