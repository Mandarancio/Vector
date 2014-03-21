/*
 * Entity.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <rapidxml.hpp>

class Entity {
public:
	Entity();
	virtual ~Entity();
	virtual rapidxml::xml_node<> * getXMLNode();
};

#endif /* ENTITY_H_ */
