/*
 * TextField.h
 *
 *  Created on: 28/mar/2014
 *      Author: martino
 */

#ifndef TEXTFIELD_H_
#define TEXTFIELD_H_

#include "Component.h"

class TextField: public Component {
public:
	TextField(std::string text="");
	virtual ~TextField();

private:
	std::string text_;
};

#endif /* TEXTFIELD_H_ */
