#include "GameWorld.h"
#include <GLFW\glfw3.h>


GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;
	gameObject = new GameObject();
	player = new Player();
	grid = new Grid();
}

GameWorld::~GameWorld()
{
	delete gameObject;
	delete player;
}

void GameWorld::GameLoop()
{
	GameLogic();
	Render();
	glfwPollEvents();
}

void GameWorld::GameLogic()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op p� at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		player->direction = -1; //G� til venstre
		player->Update();
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		player->direction = 1; //G� til h�jre
		player->Update();
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{

	}
}

void GameWorld::Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matris

	//gameObject->Render();
	grid->Render();
	player->Render();

	glfwSwapBuffers(window);
}
