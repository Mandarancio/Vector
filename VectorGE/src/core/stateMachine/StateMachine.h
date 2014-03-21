/*
 * StateMachine.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include "State.h"

class StateMachine: public Entity {
public:
	StateMachine(State * state);
	virtual ~StateMachine();
	rapidxml::xml_node<> * getXMLNode();
	void run();
private:
	State * state_;
	void run(State * state);

};

#endif /* STATEMACHINE_H_ */
