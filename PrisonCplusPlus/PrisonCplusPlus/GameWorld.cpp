#include "GameWorld.h"
#include <GLFW\glfw3.h>
#include <al.h>
#include <alc.h>


using namespace std;

//ALCenum error;
//ALuint buffer;
//ALsizei size, freq;
//ALenum format;
//ALvoid *data;
//ALboolean loop = AL_FALSE;


GameWorld::GameWorld(GLFWwindow * windowContext)
{
	window = windowContext;
	gameObject = new GameObject();
	player = new Player();
	grid = new Grid();
	wall = new Wall();
}

//GameWorld::GameWorld(ALCdevice * device)
//{
//	device = alcOpenDevice(NULL);
//	if (!device)
//	{
//		//Error handling
//	}
//	context = alcCreateContext(device, NULL);
//	if (!alcMakeContextCurrent(context))
//	{
//		//Failed to make context current
//		//Test for errors here by using alGetError();
//	}
//}

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

//void GameWorld::audio()
//{
//	//Initialization
//	device = alcOpenDevice(NULL);
//
//	if (!device)
//	{
//		context = alcCreateContext(device, NULL);
//		alcMakeContextCurrent(context);
//	}
//
//	//Generate buffers
//	alGetError(); //Clear code error
//
//	alGenBuffers((ALuint)1, &buffer);
//	if ((error = alGetError()) != AL_NO_ERROR)
//	{
//		//DisplayALError("alGenBuffers :", error);
//		//return;
//	}
//
//	//Load test wav
//	alutLoadWAVFile(TEST_WAVE_FILE, &format, &data, &size, &freq, &loop);
//}


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

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		grid->AddWall(0, 0, new Wall());
	}

	//if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	//{
	//	grid->AddGameObject(0, 0, new GameObject());
	//}
	//if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	//{
	//	grid->AddGameObject(9, 5, new GameObject());
	//}
	//if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	//{
	//	grid->AddGameObject(9, 9, new GameObject());
	//}
	//if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	//{
	//	grid->AddGameObject(0, 9, new GameObject());
	//}
	//if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	//{
	//	grid->AddGameObject(9, 0, new GameObject());
	//}
	//if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
	//{
	//	grid->AddGameObject(5, 9, new GameObject());
	//}
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
