/*
 * Action.cpp
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#include "Action.h"

Action::Action(std::string command):command_(command) {

}

Action::~Action() {
}

std::string Action::getCommand(){
	return command_;
}
