/*
 * Polygon.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: martino
 */
#include "Polygon.h"
#include "../../../support/Geometric.h"
#include <math.h>

Polygon::Polygon() {

}

Polygon::Polygon(SDL_Point *vertex) {
	int n;
	n = sizeof(vertex) / sizeof(SDL_Point);
	for (int i = 0; i < n; i++)
		addVertex(vertex[i]);
}

Polygon::Polygon(SDL_Point * vertex, int n) {
	for (int i = 0; i < n; i++)
		addVertex(vertex[i]);
}

Polygon::Polygon(std::vector<SDL_Point> vertex) {
	for (int i = 0; i < vertex.size(); i++)
		addVertex(vertex[i]);
}

Polygon::~Polygon() {
}

void Polygon::addVertex(SDL_Point vertex) {
	if (vertex_.size() > 0) {
		Line l(vertex_.back(), vertex);
		if (lines_.size() == 0) {
			lines_.push_back(l);
			lines_.push_back(l);
		} else {
			lines_[lines_.size() - 1] = l;
			lines_.push_back(Line(vertex, vertex_[0]));
		}
	}
	vertex_.push_back(vertex);
	computeBox();

}

void Polygon::addVertex(int x, int y) {
	SDL_Point p;
	p.x = x;
	p.y = y;
	addVertex(p);
}

void Polygon::computeBox() {
	if (lines_.size()==0)
		return;
	SDL_Rect bb = lines_[0].getBoundingBox();
	SDL_Rect bbi;
	for (int i = 1; i < lines_.size(); i++) {

		bbi = lines_[i].getBoundingBox();
		if (bb.x > bbi.x) {
			bb.w += bb.x - bbi.x;
			bb.x = bbi.x;
		}
		if (bb.y > bbi.y) {
			bb.h += bb.y - bbi.y;
			bb.y = bbi.y;
		}
		if (bb.w < abs(bbi.x - bb.x) + bbi.w) {
			bb.w = abs(bbi.x - bb.x) + bbi.w;
		}
		if (bb.h < abs(bbi.y - bb.y) + bbi.h) {
			bb.h = abs(bbi.y - bb.y) + bbi.h;
		}

	}
	boundingBox_ = bb;
}
bool Polygon::contains(SDL_Point p) {
	return contains(p.x, p.y);
}

bool Polygon::contains(int x, int y) {
	int nvert = vertex_.size();
	Sint16 * vertx = vx();
	Sint16 * verty = vy();
	int testx=x;
	int testy=y;
	int i, j, c = 0;
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((verty[i] > testy) != (verty[j] > testy))	&& (testx< (vertx[j] - vertx[i]) * (testy - verty[i])/ (verty[j] - verty[i]) + vertx[i]))
			c = !c;
	}
	return c;
}

Shape * Polygon::transform(Transformation t) {
	return transformPolygon(t);
}

Polygon *Polygon::transformPolygon(Transformation t) {
	Polygon *p = new Polygon();
	for (int i = 0; i < vertex_.size(); i++) {
		p->addVertex(t.transform(vertex_[i]));
	}

	return p;
}

std::vector<Line> Polygon::lines() {
	return lines_;
}
std::vector<SDL_Point> Polygon::vertex() {
	return vertex_;
}

Sint16 * Polygon::vx() {
	Sint16 * vx = new Sint16[vertex_.size()];
	for (int i = 0; i < vertex_.size(); i++) {
		vx[i] = vertex_[i].x;
	}
	return vx;
}

Sint16 * Polygon::vy() {
	Sint16 *vy = new Sint16[vertex_.size()];
	for (int i = 0; i < vertex_.size(); i++) {
		vy[i] = vertex_[i].y;
	}
	return vy;

}
