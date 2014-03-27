/*
 * Action.h
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#ifndef ACTION_H_
#define ACTION_H_
#include <string>

class Action {
public:
	Action(std::string command="action");
	virtual ~Action();
	std::string getCommand();

private:
	std::string command_;
};

#endif /* ACTION_H_ */
