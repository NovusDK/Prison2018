#include "Grid.h"
#include <GLFW\glfw3.h>
#include <al.h>
#include <alc.h>

#define sizeX 10
#define sizeY 10


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
	glTranslatef(-1.0, -1.0, 0.0f);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);

	for (x = 0; x < sizeX; x++)
	{

			glBegin(GL_LINES);
			
			glVertex3f(-1.0, 0.0 + x * (1.0 / sizeX), 0.0); 
			glVertex3f(1.0, 0.0 + x * (1.0 / sizeX), 0.0);

			glEnd();
			
	}	
	for (y = 0; y < sizeY; y++)
	{

		glBegin(GL_LINES);

		glVertex3f(0.0 + y * (1.0 / sizeY), -1.0, 0.0);
		glVertex3f(0.0 + y * (1.0 / sizeY), 1.0, 0.0); 

		glEnd();

	}	
	glPopMatrix();
	RenderField();
}


void Grid::RenderField()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (someArray[i][j] != nullptr)
			{
				glPushMatrix();
				glTranslatef(i * (-1.0 / sizeX ), j * (-1.0 / sizeY), 0.0f);
				someArray[i][j]->Render();
				glPopMatrix();
			}
			
		}
	}
}

void Grid::AddGameObject(int x, int y, GameObject * g)
{
	someArray[x][y] = g;
}

void Grid::AddWall(int x, int y, Wall * w)
{
	someArray[x][y] = w;
}