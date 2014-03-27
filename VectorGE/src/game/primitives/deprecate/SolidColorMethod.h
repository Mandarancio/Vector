/*
 * SolidColorMethod.h
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */

#ifndef SOLIDCOLORMETHOD_H_
#define SOLIDCOLORMETHOD_H_

#include "../Color.h"
#include  "ColorMethod.h"

class SolidColorMethod : public ColorMethod{
public:
	SolidColorMethod(Color c);
	virtual ~SolidColorMethod();
	virtual Color colorAt(SDL_Point p);
	virtual Color colorAt(int x,int y);
private:
	Color color_;
};

#endif /* SOLIDCOLORMETHOD_H_ */
