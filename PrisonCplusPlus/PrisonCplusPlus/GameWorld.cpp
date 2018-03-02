#include "GameWorld.h"



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
}

void GameWorld::Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity(); //Null stiller OpenGL matris

	gameObject->Render();

	glfwSwapBuffers(window);
}
