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

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op p� at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		direction = -1; // G� til venstre
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		direction = 1; // G� til h�jre
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{

	}


}
