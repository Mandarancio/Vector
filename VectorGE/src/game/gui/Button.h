/*
 * Button.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Component.h"
#include <string>

enum ButtonStatus
{
	NORMAL,PRESSED
};

class Button: public Component {
public:
	Button(std::string text="");
	virtual ~Button();

	void setText(std::string text);
	std::string getText();

	virtual void mouseButtonDown(SDL_MouseButtonEvent * e);
	virtual void mouseButtonUp(SDL_MouseButtonEvent *e);

protected:
	virtual void paintComponent(Painter * p);

private:
	std::string text_;
	ButtonStatus status_;
};

#endif /* BUTTON_H_ */
