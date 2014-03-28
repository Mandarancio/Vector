/*
 * GameEntity.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#include "GameEntity.h"

GameEntity::GameEntity() {
	angle_ = 0;
	scale_ = 1.0;
	opacity_ = 1.0;
}

GameEntity::~GameEntity() {
	// TODO Auto-generated destructor stub
}

void GameEntity::step(double dt) {
	//by default nothing to do
	//needed for animation and other stuff..
}

SDL_Rect GameEntity::getBounds() {
	return bounds_;
}

SDL_Point GameEntity::getLocation() {
	SDL_Point p;
	p.x = bounds_.x;
	p.y = bounds_.y;
	return p;
}

SDL_Size GameEntity::getSize() {
	SDL_Size s;
	s.width = bounds_.w;
	s.height = bounds_.h;
	return s;
}

int GameEntity::getX() {
	return bounds_.x;
}

int GameEntity::getY() {
	return bounds_.y;
}

int GameEntity::getWidth() {
	return bounds_.w;
}

int GameEntity::getHeight() {
	return bounds_.h;
}

float GameEntity::getAngle() {
	return angle_;
}

float GameEntity::getScale() {
	return scale_;
}

float GameEntity::getOpacity() {
	return opacity_;
}

void GameEntity::setBounds(SDL_Rect r) {
	setLocation(r.x, r.y);
	setSize(r.w, r.h);
}

void GameEntity::setBounds(int x, int y, int w, int h) {
	setLocation(x, y);
	setSize(w, h);
}

void GameEntity::setSize(SDL_Size size) {
	setSize(size.width, size.height);
}

void GameEntity::setSize(int w, int h) {
	bounds_.w = w;
	bounds_.h = h;
}

void GameEntity::setLocation(SDL_Point p) {
	setLocation(p.x, p.y);
}

void GameEntity::setLocation(int x, int y) {
	bounds_.x = x;
	bounds_.y = y;
}

void GameEntity::setAngle(float angle) {
	angle_ = angle;
}

void GameEntity::setScale(float scale) {
	scale_ = scale;
}

void GameEntity::setOpacity(float opacity) {
	opacity_ = opacity;
}

EntityStatus GameEntity::getCurrentStatus() {
	EntityStatus status;
	status.bounds = bounds_;
	status.angle = angle_;
	status.opacity = opacity_;
	status.scale = scale_;
	return status;
}

void GameEntity::setCurrentStatus(EntityStatus status) {
	setBounds(status.bounds);
	setAngle(status.angle);
	setOpacity(status.opacity);
	setScale(status.scale);
}
