#pragma once
#include <GLFW\glfw3.h>
#include "GameObject.h"
#include "Player.h"
#include "Grid.h"
#include "Wall.h"

class GameWorld
{
private:
	GLFWwindow * window;
	GameObject * gameObject;
	Player * player;
	Grid * grid;
	Wall * wall;
	//ALCdevice * device;
	//ALCcontext * context;
public:
	GameWorld(GLFWwindow * windowContext);
	//GameWorld(ALCdevice * device);
	~GameWorld();
	void GameLoop();
	//void audio();
private:
	void GameLogic();
	void Render();
};

