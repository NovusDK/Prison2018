
#include <GLFW\glfw3.h>
#include <iostream>
#include "GameObject.h"
#include "GameWorld.h"
#include <al.h>
#include <alc.h>

GameWorld * gw;

void size_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{

	glfwInit(); //Initialisering af glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //S�tte �vre OpenGl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //S�tte nedre OpenGl Version



	GLFWwindow* window = glfwCreateWindow(900, 900, "MyGLFWGLAD1", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Kunne ikke oprette OpenGL Vindue" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //S�rger for at OpenGL Bruger vinduet som renderings context

	glViewport(0, 0, 900, 900); //Oprettet en viewport gennem OpenGL kald

	glfwSetFramebufferSizeCallback(window, size_resize_callback); //Sikre at hvis vinduets st�rrelse �ndres �ndres viewport ogs�

	gw = new GameWorld(window);

	while (!glfwWindowShouldClose(window)) // K�re s� l�nge glfw vinduet ikke har f�et besked p� at lukke (f.eks. tryk p� X knappen)
	{ //Her starter gameloop'et

		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT); //Nul stiller baggrunden til baggrundsfarven

		gw->GameLoop();

		//*glBegin(GL_TRIANGLES);
		//glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex3f(-0.5f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.5f, 0.0f);
		//glVertex3f(0.5f, 0.0f, 0.0f);
		//glEnd();*/

		//glfwSwapBuffers(window); //Bruger dobbelt buffer koncept til reducering af flicker - her byttes bufferne
		//glfwPollEvents(); //Kalder evt. callback der skal reagere p� keyboard eller mouse input
	}

	glfwTerminate(); //Lukker evt. �bnede vinduer og frigiver resurse brugt her til
	return 0;
}