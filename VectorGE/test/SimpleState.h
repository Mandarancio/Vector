/*
 * SimpleState.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef SIMPLESTATE_H_
#define SIMPLESTATE_H_

#include "../src/core/stateMachine/State.h"
#include <map>
#include <string>

class SimpleState: public State {
public:
	SimpleState(std::string question,std::map<std::string,SimpleState*> answers,State * parent=0);
	SimpleState(std::string affirmation,State * parent=0);
	virtual ~SimpleState();
	virtual State* run();
private:
	std::string question_;
	std::map<std::string,SimpleState*> answers_;

};

#endif /* SIMPLESTATE_H_ */
