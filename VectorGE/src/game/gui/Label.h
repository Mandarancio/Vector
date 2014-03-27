/*
 * Label.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "Component.h"
#include "ComponentSupport.h"

#include <string>

class Label: public Component {
public:
	Label(std::string text="");
	virtual ~Label();

	void setText(std::string text);
	std::string getText();

	void setHorizontalAlignment(HorizontalAlignment ha);
	void setVerticalAlignment(VerticalAlignment va);

protected:
	virtual void paintComponent(Painter * p);
private:
	std::string text_;
	HorizontalAlignment horizontalTextAlignment_;
	VerticalAlignment verticalTextAlgnment_;
};

#endif /* LABEL_H_ */
