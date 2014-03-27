/*
 * Container.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Component.h"
#include "Layout.h"

#include <vector>

class Container: public Component{
public:
	Container();
	virtual ~Container();

	virtual void addComponent(Component * c);
	virtual void removeComponent(Component * c);
	virtual void removeComponent(int ind);

	std::vector<Component *> getComponents();

	Layout* getLayout();
	void setLayout(Layout * l);

	void setSize(int w,int h);
protected:
	virtual void paintComponent(Painter * p);
	virtual void paintSubComponents(Painter *p);
private:
	std::vector<Component*> components_;
	Layout * 				layout_;
};

#endif /* CONTAINER_H_ */
