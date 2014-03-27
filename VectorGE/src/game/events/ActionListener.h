/*
 * ActionListener.h
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#ifndef ACTIONLISTENER_H_
#define ACTIONLISTENER_H_

#include "Action.h"

class ActionListener {
public:
	ActionListener();
	virtual ~ActionListener();
	virtual void actionPerfoormed(Action* a);
};

#endif /* ACTIONLISTENER_H_ */
