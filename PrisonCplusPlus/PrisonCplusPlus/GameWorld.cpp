#include "GameWorld.h"
#include <GLFW\glfw3.h>


GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;
	gameObject = new GameObject();
}

GameWorld::~GameWorld()
{
	delete gameObject;
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
		gameObject->direction = -1; // Gå til venstre
		gameObject->Update();
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		gameObject->direction = 1; // Gå til højre
		gameObject->Update();
	}
	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	//{

	//}
}

void GameWorld::Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matris

	gameObject->Render();

	glfwSwapBuffers(window);
}
