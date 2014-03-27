/*
 * Component.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "../GameEntity.h"
#include "../events/MouseListener.h"
#include "../primitives/Color.h"

class Component: public GameEntity, public MouseListener {
public:
	Component();
	virtual ~Component();
	virtual void render(Painter * p);

	bool hasFocus();
	virtual void getFocus();
	virtual void lostFocus();

	Color getBackground();
	Color getForeground();

	void setBackground(Color c);
	void setForeground(Color c);
protected:
	virtual void paintComponent(Painter * p)=0;

	Color backGround_;
	Color foreGround_;
private:
	bool hasFocus_;

};

#endif /* COMPONENT_H_ */
