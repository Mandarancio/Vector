/*
 * Container.h
 *
 *  Created on: Mar 27, 2014
 *      Author: martino
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Component.h"

#include <vector>

class Container: public Component{
public:
	Container();
	virtual ~Container();

	void addComponent(Component * c);
	void removeComponent(Component * c);
	void removeComponent(int ind);

	std::vector<Component *> getComponents();

protected:
	virtual void paintComponent(Painter * p);
	virtual void paintSubComponents(Painter *p);
private:
	std::vector<Component*> components_;

};

#endif /* CONTAINER_H_ */