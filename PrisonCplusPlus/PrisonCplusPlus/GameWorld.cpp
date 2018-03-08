#include "GameWorld.h"
#include <GLFW\glfw3.h>
#include <al.h>
#include <alc.h>




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
	delete grid;
}

void GameWorld::GameLoop()
{
	GameLogic();
	Render();
	glfwPollEvents();
}


void GameWorld::GameLogic()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op på at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		player->direction = -1; //Gå til venstre
		player->Update();
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		player->direction = 1; //Gå til højre
		player->Update();
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		player->direction = 1;
		player->UpdateTwo();
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		player->direction = -1;
		player->UpdateTwo();
	}

	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		grid->AddGameObject(9, 9, new GameObject());
	}
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	{
		grid->AddGameObject(5, 3, new GameObject());
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		grid->AddGameObject(5, 8, new GameObject());
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
