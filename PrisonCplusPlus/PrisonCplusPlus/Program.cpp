
#include <GLFW\glfw3.h>
#include <iostream>
#include "GameObject.h"
#include "GameWorld.h"
#include <Framework.h>
#include <Windows.h>

#define TEST_WAVE_FILE "Furious_Freak.wav"

GameWorld * gw;

void size_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	
	glfwInit(); //Initialisering af glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //Sætte øvre OpenGl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //Sætte nedre OpenGl Version

	ALuint      uiBuffer;
	ALuint      uiSource;
	ALint       iState;

	// Initialize Framework
	ALFWInit();

	ALFWprintf("PlayStatic Test Application\n");

	if (!ALFWInitOpenAL())
	{
		ALFWprintf("Failed to initialize OpenAL\n");
		ALFWShutdown();
		return 0;
	}

	// Generate an AL Buffer
	alGenBuffers(1, &uiBuffer);

	// Load Wave file into OpenAL Buffer
	if (!ALFWLoadWaveToBuffer((char*)ALFWaddMediaPath(TEST_WAVE_FILE), uiBuffer))
	{
		ALFWprintf("Failed to load %s\n", ALFWaddMediaPath(TEST_WAVE_FILE));
	}

	// Generate a Source to playback the Buffer
	alGenSources(1, &uiSource);

	// Attach Source to Buffer
	alSourcei(uiSource, AL_BUFFER, uiBuffer);

	// Play Source
	alSourcePlay(uiSource);
	ALFWprintf("Playing Source ");

	ALFWprintf("\n");

	GLFWwindow* window = glfwCreateWindow(900, 900, "MyGLFWGLAD1", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Kunne ikke oprette OpenGL Vindue" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //Sørger for at OpenGL Bruger vinduet som renderings context

	glViewport(0, 0, 900, 900); //Oprettet en viewport gennem OpenGL kald

	glfwSetFramebufferSizeCallback(window, size_resize_callback); //Sikre at hvis vinduets størrelse ændres ændres viewport også

	gw = new GameWorld(window);

	while (!glfwWindowShouldClose(window)) // Køre så længe glfw vinduet ikke har fået besked på at lukke (f.eks. tryk på X knappen)
	{ //Her starter gameloop'et

		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT); //Nul stiller baggrunden til baggrundsfarven
		FreeConsole();

		gw->GameLoop();

		//*glBegin(GL_TRIANGLES);
		//glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex3f(-0.5f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.5f, 0.0f);
		//glVertex3f(0.5f, 0.0f, 0.0f);
		//glEnd();*/

		//glfwSwapBuffers(window); //Bruger dobbelt buffer koncept til reducering af flicker - her byttes bufferne
		//glfwPollEvents(); //Kalder evt. callback der skal reagere på keyboard eller mouse input
	}

	// Clean up by deleting Source(s) and Buffer(s)
	alSourceStop(uiSource);
	alDeleteSources(1, &uiSource);
	alDeleteBuffers(1, &uiBuffer);

	ALFWShutdownOpenAL();

	ALFWShutdown();

	glfwTerminate(); //Lukker evt. åbnede vinduer og frigiver resurse brugt her til
	return 0;
}