/*
 * Entity.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "Entity.h"

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

rapidxml::xml_node<> * Entity::getXMLNode(){
	rapidxml::xml_node<> * node=new rapidxml::xml_node<> (rapidxml::node_element);
	return node;
}
