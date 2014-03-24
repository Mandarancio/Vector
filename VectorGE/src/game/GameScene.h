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

#include <vector>
#include <string>


#include <Box2D/Box2D.h>

class GameScene: public Entity {
public:
	GameScene(Camera * camera, b2World *world=0);
	virtual ~GameScene();
	void gameLoop(int dt=0);
	void addEntity(GameEntity *ge);

private:
	std::string sceneName;
	std::vector<GameEntity*> gameEntities;

	Camera * camera;
	b2World * world;
};

#endif /* GAMESCENE_H_ */
