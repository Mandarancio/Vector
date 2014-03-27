/*
 * GameScene.h
 *
 *  Created on: Mar 21, 2014
 *      Author: martino
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "../core/Entity.h"
#include "GameEntity.h"
#include "Camera.h"
#include "events/MouseListener.h"
#include "events/KeyListener.h"


#include <vector>
#include <string>


#include <Box2D/Box2D.h>

class GameScene: public Entity {
public:
	GameScene(Camera * camera, b2World *world=0);
	GameScene(Camera * camera, float gx,float gy);

	virtual ~GameScene();
	void gameLoop(int dt=0);
	void addEntity(GameEntity *ge);

	b2World * getWorld();

	void addMouseListener(MouseListener * ml);
	void removeMouseListener(MouseListener *ml);
	void removeMouseListener(int ind);

	void addKeyListener(KeyListener *kl);
	void removeKeyListener(KeyListener *kl);
	void removeKeyListener(int ind);
private:
	void triggerMouseListener(SDL_Event e);
	void triggerKeyListener(SDL_Event e);

	std::string sceneName;
	std::vector<GameEntity*> gameEntities;
	std::vector<MouseListener*> mouseListeners;
	std::vector<KeyListener*> keyListeners;

	Camera * camera;
	b2World * world;

	int positionIterations;
	int velocityIterations;
};

#endif /* GAMESCENE_H_ */
