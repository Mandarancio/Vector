/*
 * SimpleState.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "SimpleState.h"
#include <iostream>
#include <vector>

SimpleState::SimpleState(std::string question,
		std::map<std::string, SimpleState*> answers, State * parent) :
		State(parent), question_(question), answers_(answers) {

}

SimpleState::SimpleState(std::string affirmation,State * parent):State(parent){
	question_=affirmation;
}

SimpleState::~SimpleState() {
	// TODO Auto-generated destructor stub
}

State* SimpleState::run(int dt) {
	std::cout << question_ << "\n";
	if (answers_.size()==0)
		return 0;
	int i = 1;
	std::vector<std::string >keys;
	for (std::map<std::string, SimpleState*>::iterator it = answers_.begin();
			it != answers_.end(); ++it) {
		keys.push_back(it->first);
		std::cout << i << " " << it->first << "\n";
		i++;
	}
	int repl = -1;
	std::cin >> repl;
	if (repl > 0 && repl <= answers_.size()) {
		return answers_[keys[repl-1]];
	} else if (repl == -1 && previous_ != 0)
		return previous_;
	else
		return run();
}

