#pragma once
#include <GLFW\glfw3.h>
#include "GameObject.h"
class GameWorld
{
private:
	GLFWwindow * window;
	GameObject * gameObject;
public:
	GameWorld(GLFWwindow * windowContext);
	~GameWorld();
	void GameLoop();
private:
	void GameLogic();
	void Render();
};

