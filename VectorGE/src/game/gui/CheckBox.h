/*
 * CheckBox.h
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#ifndef CHECKBOX_H_
#define CHECKBOX_H_

#include "Component.h"
#include <string>

class CheckBox: public Component {
public:
	CheckBox(std::string text="");
	virtual ~CheckBox();

	void setText(std::string text);
	std::string getText();

	bool isChecked();
	void setChecked(bool checked);

protected:
	virtual void paintComponent(Painter * p);
private:
	std::string text_;
	bool isChecked_;
};

#endif /* CHECKBOX_H_ */
