#include "GameWorld.h"
#include <GLFW\glfw3.h>
#include <iostream>

GameWorld::GameWorld()
{
}


GameWorld::~GameWorld()
{
}

void GameWorld::GameLogic()
{

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op på at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		direction = -1; // Gå til venstre
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		direction = 1; // Gå til højre
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{

	}


}
