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
#include "../primitives/SDLSize.h"

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

	SDL_Rect getBounds();
	SDL_Point getLocation();
	SDL_Size getSize();
	int getX();
	int getY();
	int getWidth();
	int getHeight();

	void setBounds(SDL_Rect r);
	void setBounds(int x, int y, int w, int h);

	void setSize(SDL_Size size);
	void setSize(int w, int h);

	void setLocation(SDL_Point p);
	void setLocation(int x, int y);

	Component * getParent();
	void setParent(Component * parent);
protected:
	virtual void paintComponent(Painter * p)=0;

	Color backGround_;
	Color foreGround_;
	SDL_Rect bounds_;
	Component * parent_;
private:
	bool hasFocus_;

};

#endif /* COMPONENT_H_ */
