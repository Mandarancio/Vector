/*
 * Label.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "Component.h"
#include <string>

class Label: public Component {
public:
	Label(std::string text="");
	virtual ~Label();
protected:
	virtual void paintComponent(Painter * p);
private:
	std::string text_;
};

#endif /* LABEL_H_ */
