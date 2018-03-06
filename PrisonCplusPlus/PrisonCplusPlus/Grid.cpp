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
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	int xsize = 0, ysize = 0;
	for (x = 0; x < 10; x++)
	{
		xsize = 0;
		for (y = 0; y < 10; y++)
		{
			glBegin(GL_POLYGON);

			glVertex3f(-50.0 + xsize, -50.0 + ysize, 0.0);
			glVertex3f(-40.0 + xsize, -50.0 + ysize, 0.0);
			glVertex3f(-40.0 + xsize, -40.0 + ysize, 0.0);
			glVertex3f(-50.0 + xsize, -40.0 + ysize, 0.0);
			glEnd();
			xsize += 10.0;
		}
		ysize += 10.0;
	}
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
				//glTranslatef(i, j, 0);
				someArray[i][j]->Render();
			}
		}
	}
}
