/*
 * CheckBox.h
 *
 *  Created on: 27/mar/2014
 *      Author: martino
 */

#ifndef CHECKBOX_H_
#define CHECKBOX_H_

#include "Component.h"
#include "../events/ActionListener.h"

#include <string>
#include <vector>

class CheckBox: public Component {
public:
	CheckBox(std::string text="");
	virtual ~CheckBox();

	void setText(std::string text);
	std::string getText();

	bool isChecked();
	void setChecked(bool checked);

	virtual void mouseOut();
	virtual void mouseMotion(SDL_MouseMotionEvent *e);
	virtual void mouseButtonDown(SDL_MouseButtonEvent * e);
	virtual void mouseButtonUp(SDL_MouseButtonEvent * e);

	void addActionListener(ActionListener * l);
	void removeActionListener(ActionListener * l);
protected:
	virtual void paintComponent(Painter * p);
private:
	void triggerActionListeners();

	std::string text_;
	std::string cmdString_;
	bool isChecked_;

	std::vector<ActionListener*> actionListeners_;

	bool __onCheckArea;
	bool __onClick;
};

#endif /* CHECKBOX_H_ */
