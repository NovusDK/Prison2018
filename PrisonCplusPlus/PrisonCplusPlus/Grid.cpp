#include "Grid.h"
#include <GLFW\glfw3.h>


Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::Render()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	glColor3f(0.0, 0.0, 0.0);
	
	for (x = 0; x < 10; x++)
	{

			glBegin(GL_LINES);

			glVertex3f(0.0, 0.0, 0.0); // The bottom left corner  
			//glVertex3f(0.0, 9, 0.0); // The top left corner  
			//glVertex3f(9, 9, 0.0); // The top right corner  
			glVertex3f(9, 0.0, 0.0); // The bottom right corne;
		
			glEnd();
			
	}
	glPopMatrix();
	RenderField();

	//for (y = 0; y < 10; y++)
	//{

	//	glBegin(GL_LINE_LOOP);

	//	glVertex3f(0.0, 0.0, 0.0); // The bottom left corner  
	//	glVertex3f(0.0, 9, 0.0); // The top left corner  
	//	glVertex3f(9, 9, 0.0); // The top right corner  
	//	glVertex3f(9, 0.0, 0.0); // The bottom right corne;

	//	glEnd();

	//}
	glPopMatrix();
	RenderField();
}

void Grid::AddGameObject(int x, int y, GameObject * g)
{
	someArray[x][y] = g;
}

void Grid::RenderField()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (someArray[i][j] != nullptr)
			{
				//glTranslatef(i, j, 0.0f);
				someArray[i][j]->Render();
			}
		}
	}
}
