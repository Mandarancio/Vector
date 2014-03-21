/*
 * State.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "State.h"

State::State(State* parent) :
		Entity(), previous_(parent) {
	// TODO Auto-generated constructor stub
	next_ = 0;
	transitionStart_ = 0;
	transtionEnd_ = 0;
}

State::~State() {
	delete next_;
	delete transtionEnd_;
	delete transitionStart_;
}

State * State::next() {
	return next_;
}
State * State::prevous() {
	return previous_;
}
State * State::transitionStart() {
	return transitionStart_;
}
State * State::transitionEnd() {
	return transtionEnd_;
}
