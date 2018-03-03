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
	gameObject->Update();
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //Tjekker op p� at ESC er trykket ned, hvis ja luk vinduet
	{
		glfwSetWindowShouldClose(window, true);
	}
	//if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	//{
	//	direction = -1; // G� til venstre
	//}
	//if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	//{
	//	direction = 1; // G� til h�jre
	//}
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
