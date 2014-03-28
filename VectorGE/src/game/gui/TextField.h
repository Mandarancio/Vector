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
	TextField(std::string text = "");
	virtual ~TextField();

	virtual void step(double dt);

	void setText(std::string text);
	std::string getText();

	virtual void getFocus();
	virtual void mouseButtonUp(SDL_MouseButtonEvent * e);
	virtual void mouseButtonDown(SDL_MouseButtonEvent *e);

protected:
	virtual void paintComponent(Painter *p);

private:
	void paintCursor(Painter *p);
	int _convertCursorPosToX(int cp);
	int _convertXtoCursorPos(int x);

	std::string text_;
	int cursorPos_;
	bool __clickFlag;
	bool __cursorAnimVisible;
	float  __cursorTimer;
};

#endif /* TEXTFIELD_H_ */
