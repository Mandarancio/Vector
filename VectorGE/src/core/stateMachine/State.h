/*
 * State.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef STATE_H_
#define STATE_H_

#include "../Entity.h"

class State: public Entity {
public:
	State(State * parent=0);
	virtual ~State();
	virtual State* run(int dt=0)=0;

	State * next();
	State * prevous();
	State * transitionStart();
	State * transitionEnd();
protected:
	State * transitionStart_,*transtionEnd_;
	State * previous_;
	State * next_;
};

#endif /* STATE_H_ */
