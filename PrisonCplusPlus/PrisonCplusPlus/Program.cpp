
#include <GLFW\glfw3.h>
#include <iostream>
#include "GameObject.h"
#include "GameWorld.h"

GameWorld * gw;

void size_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void drawSquare()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	int xsize = 0, ysize = 0;
	for (int j = 0; j<10; j++)
	{

		xsize = 0;
		for (int i = 0; i<10; i++)
		{


int main()
{
	glfwInit(); //Initialisering af glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //Sætte øvre OpenGl version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //Sætte nedre OpenGl Version



	GLFWwindow* window = glfwCreateWindow(800, 600, "MyGLFWGLAD1", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Kunne ikke oprette OpenGL Vindue" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //Sørger for at OpenGL Bruger vinduet som renderings context



	glViewport(0, 0, 800, 600); //Oprettet en viewport gennem OpenGL kald

	glfwSetFramebufferSizeCallback(window, size_resize_callback); //Sikre at hvis vinduets størrelse ændres ændres viewport også

	gw = new GameWorld(window);

	while (!glfwWindowShouldClose(window)) // Køre så længe glfw vinduet ikke har fået besked på at lukke (f.eks. tryk på X knappen)
	{ //Her starter gameloop'et

		gw->GameLoop();

		//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT); //Nul stiller baggrunden til baggrundsfarven

		//drawSquare();

		//*glBegin(GL_TRIANGLES);
		//glColor3f(1.0f, 0.0f, 0.0f);
		//glVertex3f(-0.5f, 0.0f, 0.0f);
		//glVertex3f(0.0f, 0.5f, 0.0f);
		//glVertex3f(0.5f, 0.0f, 0.0f);
		//glEnd();*/

		//glfwSwapBuffers(window); //Bruger dobbelt buffer koncept til reducering af flicker - her byttes bufferne
		//glfwPollEvents(); //Kalder evt. callback der skal reagere på keyboard eller mouse input
	}

	glfwTerminate(); //Lukker evt. åbnede vinduer og frigiver resurse brugt her til
	return 0;
}