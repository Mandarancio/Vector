/*
 * Painter.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: martino
 */

#include "Painter.h"
#include "../support/Logging.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <iostream>

#include <algorithm>

Painter::Painter(SDL_Renderer * rend, SDL_Size size) :
		renderer(rend), displaySize(size) {
	status.transformation = new Transformation();
	status.font = new Font();
	status.fill = (Color(255, 255, 255));
	status.pen = (Color(0, 0, 0));
	displayCenter.x = size.width / 2;
	displayCenter.y = size.height / 2;

	status.clip.x = 0;
	status.clip.y = 0;
	status.clip.w = 0;
	status.clip.h = 0;

}

Painter::~Painter() {
	// TODO Auto-generated destructor stub
}

void Painter::setPen(Color c) {
	status.pen = c;
}

void Painter::setFill(Color c) {
	status.fill = c;
}

void Painter::setFont(Font *f) {
	delete status.font;
	status.font = new Font(f->getName(),
			f->getSize() * status.transformation->getScale());
}

Font * Painter::getFont() {
	return status.font;
}

Color Painter::getFill() {
	return status.fill;
}
Color Painter::getPen() {
	return status.pen;
}

void Painter::paintRect(Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	paintRect(r);
}

void Painter::paintRect(SDL_Rect rect) {

	status.transformation->applyTransformation(rect.x, rect.y);
	status.transformation->applySizeTransformation(rect.w, rect.h);
	Color p = status.fill;
	SDL_SetRenderDrawColor(renderer, p.red(), p.green(), p.blue(), p.alpha());
	SDL_RenderFillRect(renderer, &rect);
	p = status.pen;
	SDL_SetRenderDrawColor(renderer, p.red(), p.green(), p.blue(), p.alpha());
	SDL_RenderDrawRect(renderer, &rect);

}

void Painter::paintRoundedRect(Sint16 x, Sint16 y, Uint16 w, Uint16 h,
		Uint16 r) {
	status.transformation->applyTransformation(x, y);
	status.transformation->applySizeTransformation(w, h);
	r *= status.transformation->getScale();

	roundedRectangleColor(renderer, x, y, x + w, y + h, r,
			status.pen.getRGBA());

}

void Painter::paintRoundedRect(SDL_Rect rect, Uint16 r) {
	paintRoundedRect(rect.x, rect.y, rect.w, rect.h, r);

}

void Painter::paintCircle(int x, int y, Uint16 r) {
	filledCircleColor(renderer, x, y, r, status.fill.getRGBA());
	circleColor(renderer, x, y, r, status.pen.getRGBA());
}

void Painter::paintOval(int x, int y, Uint16 rx, Uint16 ry) {
	filledEllipseColor(renderer, x, y, rx, ry, status.fill.getRGBA());
	ellipseColor(renderer, x, y, rx, ry, status.pen.getRGBA());
}

void Painter::paintLine(int x1, int y1, int x2, int y2) {
	paintLine(Line(x1, y1, x2, y2));
}

void Painter::paintLine(Line l) {
	Line *l1 = l.transformLine(*status.transformation);
	SDL_SetRenderDrawColor(renderer, status.pen.red(), status.pen.green(),
			status.pen.blue(), status.pen.alpha());
	SDL_RenderDrawLine(renderer, l1->p1().x, l1->p1().y, l1->p2().x,
			l1->p2().y);

}

void Painter::paintPoint(int x, int y) {
	status.transformation->applyTransformation(x, y);
	SDL_SetRenderDrawColor(renderer, status.pen.red(), status.pen.green(),
			status.pen.blue(), status.pen.alpha());
	SDL_RenderDrawPoint(renderer, x, y);
}

void Painter::paintText(std::string text, int x, int y) {
	if (text.length() == 0)
		return;

	SDL_Surface * surface = status.font->toSurface(text,
			status.pen.getSDLColor());
	SDL_Rect r = status.font->textBounds(text);
	r.x = x;
	r.y = y;
	status.transformation->applyTransformation(r.x, r.y);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == 0) {
		logSDLError(std::cout, "CreateTexture");
	}
	SDL_RenderCopy(renderer, texture, NULL, &r);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Painter::paintImage(Image img, SDL_Rect bounds, Uint8 alpha) {
	SDL_Texture * t = img.getTexture(renderer);
	paintTexture(t, bounds, alpha);
	SDL_DestroyTexture(t);
}

void Painter::paintImage(Image img, SDL_Point pos, Uint8 alpha) {
	SDL_Rect r;
	r.x = pos.x;
	r.y = pos.y;
	r.w = img.getSize().width;
	r.h = img.getSize().height;
	paintImage(img, r, alpha);
}

void Painter::paintImage(Image img, int x, int y, Uint8 alpha) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = img.getSize().width;
	r.h = img.getSize().height;
	paintImage(img, r, alpha);
}

void Painter::paintTexture(SDL_Texture *texture, SDL_Rect bounds, Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
	status.transformation->applyTransformation(bounds.x, bounds.y);
	status.transformation->applySizeTransformation(bounds.w, bounds.h);
	SDL_RenderCopy(renderer, texture, NULL, &bounds);
}

void Painter::paintBezierCourve(BezierCurve *bezier) {
	for (int i = 0; i < bezier->getLines().size(); i++) {
		paintLine(bezier->getLines()[i]);
	}
}

void Painter::paintBezierPath(BezierPath *s) {
	std::vector<Line> lines = s->getLines();
	SDL_Point p;
	Line l(0, 0, 0, 0);
	bool ready = false;
	bool intersect = false;
	int x0 = s->getBoundingBox().x;
	int y0 = s->getBoundingBox().y;
	int h0 = s->getBoundingBox().h;
	int w0 = s->getBoundingBox().w;
	SDL_SetRenderDrawColor(renderer, status.fill.red(), status.fill.green(),
			status.fill.blue(), status.fill.alpha());
	if (w0 < h0) {
		int x1, x2;
		int x;

		for (int y = y0; y < y0 + h0; y++) {
			ready = false;
			x = x0;
			l = Line(x0, y, x0 + w0, y);
			if (s->contains(x, y)) {
				ready = true;
				x1 = x;
			}
			for (int i = 0; i < lines.size(); i++) {
				if (lines[i].intersectLine(l, p)) {
					if (p.x <= x0 || p.x > x0 + w0) {
						continue;
					} else {
						if (ready) {
							x2 = p.x;
							SDL_RenderDrawLine(renderer, x1, y, x2, y);
							ready = false;
							intersect = true;

						} else {
							x1 = p.x;
							ready = true;
							intersect = false;
						}
					}
				}
			}
			if (ready && !intersect) {
				SDL_RenderDrawLine(renderer, x1, y, x0 + w0, y);
			}
		}
	} else {
		int y1, y2;
		int y;
		for (int x = x0; x < x0 + w0; x++) {
			ready = false;
			y = y0;
			l = Line(x, y, x, y + h0);
			if (s->contains(x, y)) {
				ready = true;
				y1 = y0;
			}
			for (int i = 0; i < lines.size(); i++) {
				if (lines[i].intersectLine(l, p)) {
					if (p.x <= x0 || p.x > x0 + w0) {
						continue;
					} else {
						if (ready) {
							y2 = p.y;
							SDL_RenderDrawLine(renderer, x, y1, x, y2);
							ready = false;
							intersect = true;

						} else {
							y1 = p.y;
							ready = true;
							intersect = false;
						}
					}
				}
			}
			if (ready && !intersect) {
				SDL_RenderDrawLine(renderer, x, y1, x, y0 + h0);
			}
		}
	}

	for (int i = 0; i < s->getCurves().size(); i++) {
		paintBezierCourve(s->getCurves()[i]);
	}
}

void Painter::fillShape(Shape * shape) {
	Shape * s = shape->transform(*status.transformation);

	SDL_SetRenderDrawColor(renderer, status.fill.red(), status.fill.green(),
			status.fill.blue(), status.fill.alpha());
	int sy = s->getBoundingBox().y;
	int fy = sy + s->getBoundingBox().y + s->getBoundingBox().h;
	int sx = s->getBoundingBox().x;
	int fx = sx + s->getBoundingBox().w;
	SDL_Rect r;
	int c = 0;
	for (int y = sy; y <= fy; y += 2) {
		for (int x = sx; x <= fx; x += 2) {
			if (s->contains(x, y)) {
				r = (SDL_Rect ) { x, y, 1, 1 };
				SDL_RenderFillRect(renderer, &r);

				c++;
			}
		}
	}
	std::cout << "painted " << c << " pixels\n";
}

void Painter::paintPolygon(Polygon pol) {
	Polygon * s = pol.transformPolygon(*status.transformation);
	std::vector<Line> lines = s->lines();
	SDL_Point p;
	Line l(0, 0, 0, 0);
	bool ready = false;
	bool intersect = false;
	int x0 = s->getBoundingBox().x;
	int y0 = s->getBoundingBox().y;
	int h0 = s->getBoundingBox().h;
	int w0 = s->getBoundingBox().w;
	SDL_SetRenderDrawColor(renderer, status.fill.red(), status.fill.green(),
			status.fill.blue(), status.fill.alpha());
	if (w0 > h0) {
		int x1, x2;
		int x;

		for (int y = y0; y < y0 + h0; y++) {
			ready = false;
			x = x0;
			l = Line(x0, y, x0 + w0, y);
			if (s->contains(x, y)) {
				ready = true;
				x1 = x;
			}
			for (int i = 0; i < lines.size(); i++) {
				if (lines[i].intersectLine(l, p)) {
					if (p.x <= x0 || p.x > x0 + w0) {
						continue;
					} else {
						if (ready) {
							x2 = p.x;
							SDL_RenderDrawLine(renderer, x1, y, x2, y);
							ready = false;
							intersect = true;

						} else {
							x1 = p.x;
							ready = true;
							intersect = false;
						}
					}
				}
			}
			if (ready && !intersect) {
				SDL_RenderDrawLine(renderer, x1, y, x0 + w0, y);
			}
		}
	} else {
		int y1, y2;
		int y;
		for (int x = x0; x < x0 + w0; x++) {
			ready = false;
			y = y0;
			l = Line(x, y, x, y + h0);
			if (s->contains(x, y)) {
				ready = true;
				y1 = y0;
			}
			for (int i = 0; i < lines.size(); i++) {
				if (lines[i].intersectLine(l, p)) {
					if (p.x <= x0 || p.x > x0 + w0) {
						continue;
					} else {
						if (ready) {
							y2 = p.y;
							SDL_RenderDrawLine(renderer, x, y1, x, y2);
							ready = false;
							intersect = true;

						} else {
							y1 = p.y;
							ready = true;
							intersect = false;
						}
					}
				}
			}
			if (ready && !intersect) {
				SDL_RenderDrawLine(renderer, x, y1, x, y0 + h0);
			}
		}
	}

	for (int i = 0; i < pol.lines().size(); i++) {
		paintLine(pol.lines()[i]);
	}
}

void Painter::clearWindow() {
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}
void Painter::renderToScreen() {
	SDL_RenderPresent(renderer);
}

void Painter::translate(int x, int y) {
	status.transformation->translate(x, y);
}

void Painter::scale(double s) {
	status.transformation->scale(s);
	status.font->scale(status.transformation->getScale());
}

Transformation * Painter::getTransformation() {
	return status.transformation;
}

void Painter::save() {
	PainterStatus past;
	past.clip = status.clip;
	past.fill = status.fill;
	past.pen = status.pen;
	past.font = status.font->clone();
	past.transformation = status.transformation->clone();

	history.push_back(past);

}
void Painter::restore() {
	if (history.size() > 0) {
		delete status.font;
		delete status.transformation;
		status = history.back();

		history.pop_back();
		setClip(status.clip);
	}
}

void Painter::clearTransaltion() {
	status.transformation->reset();
}

SDL_Size Painter::getDisplaySize() {
	return displaySize;
}

SDL_Point Painter::getDisplayCenter() {
	return displayCenter;
}

SDL_Rect Painter::getClip() {
	return status.clip;
}
void Painter::setClip(SDL_Rect clip) {
	status.clip = clip;
	if (clip.w > 0 && clip.h > 0) {
		SDL_RenderSetClipRect(renderer, &clip);
	} else {
		SDL_RenderSetClipRect(renderer, NULL);
	}
}
void Painter::setClip(int x, int y, int w, int h) {
	status.clip.x = x;
	status.clip.y = y;
	status.clip.w = w;
	status.clip.h = h;

	SDL_RenderSetClipRect(renderer, &status.clip);
}

void Painter::removeClip() {
	status.clip.w = 0;
	status.clip.x = 0;
	status.clip.y = 0;
	status.clip.h = 0;

	SDL_RenderSetClipRect(renderer, NULL);
}

void Painter::windowResized(SDL_WindowEvent *e) {
	displaySize.width = e->data1;
	displaySize.height = e->data2;
	displayCenter.x = e->data1 / 2;
	displayCenter.y = e->data2 / 2;
}
