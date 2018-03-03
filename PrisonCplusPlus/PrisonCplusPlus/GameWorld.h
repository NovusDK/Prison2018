#pragma once
#include <GLFW\glfw3.h>
#include "GameObject.h"
#include "Player.h"

class GameWorld
{
private:
	GLFWwindow * window;
	GameObject * gameObject;
	Player * player;
public:
	GameWorld(GLFWwindow * windowContext);
	~GameWorld();
	void GameLoop();
private:
	void GameLogic();
	void Render();
};

