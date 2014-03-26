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
	if (vertex_.size() > 0) {
		int w = 0;
		int h = 0;
		int x = vertex_[0].x;
		int y = vertex_[0].y;
		for (int i = 1; i < vertex_.size(); i++) {
			if (w < abs(vertex_[i].x - x)) {
				w = abs(vertex_[i].x - x);
			}
			if (h < abs(vertex_[i].y - y)) {
				h = abs(vertex_[i].y - y);
			}
			if (x > vertex_[i].x) {
				x = vertex_[i].x;
			}
			if (y > vertex_[i].y) {
				y = vertex_[i].y;
			}
		}
		boundingBox_.x = x;
		boundingBox_.y = y;
		boundingBox_.w = w;
		boundingBox_.h = h;
	}
}
bool Polygon::contains(SDL_Point p) {
	return contains(p.x, p.y);
}

bool Polygon::contains(int x, int y) {
	if (rectContains(boundingBox_, x, y)) {
		Line l1(boundingBox_.x, y, x, y);
		int li = 0;
		for (int i = 0; i < lines_.size(); i++) {
			if (lines_[i].intersectLine(l1))
				li++;
		}
		if (li % 2 == 0)
			return false;

		Line l3(x, boundingBox_.y, x, y);
		int ti = 0;
		for (int i = 0; i < lines_.size(); i++) {
			if (lines_[i].intersectLine(l1))
				ti++;
		}

		if (ti % 2 == 0)
			return false;

		return true;
	}

	return false;
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
