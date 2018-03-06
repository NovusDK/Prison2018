#include "Grid.h"
#include <GLFW\glfw3.h>

float xsize = 0; float ysize = 0;

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::Render()
{
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (x = 0; x < 10; x++)
	{
		glVertex3f(-1.0f, 0.0f + x / 10, 0.0f);
		glVertex3f(1.0f, 0.0f + x / 10, 0.0f);
		xsize += 1.0f;
	}
	//for (y = 0; y < 10; y++)
	//{
	//	glVertex3f(0.0f + y / 10, -1.0f, 0.0f);
	//	glVertex3f(0.0f + y / 10, 1.0f, 0.0f);
	//}
	glEnd();
	glPopMatrix();
	////glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//glPushMatrix();
	////glMatrixMode(GL_PROJECTION);
	////glLoadIdentity();
	//glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	//glColor3f(0.0, 0.0, 0.0);
	//int xsize = 0, ysize = 0;
	//for (x = 0; x < 10; x++)
	//{
	//	xsize = 0;
	//	for (y = 0; y < 10; y++)
	//	{
	//		glBegin(GL_LINE);

	//		glVertex3f(-50.0 + xsize, -50.0 + ysize, 0.0);
	//		glVertex3f(-40.0 + xsize, -50.0 + ysize, 0.0);
	//		glVertex3f(-40.0 + xsize, -40.0 + ysize, 0.0);
	//		glVertex3f(-50.0 + xsize, -40.0 + ysize, 0.0);
	//		//glVertex3f(-05.0 + x, -05.0 + y, 0.0);
	//		//glVertex3f(-01.0 + x, -05.0 + y, 0.0);
	//		//glVertex3f(-01.0 + x, -01.0 + y, 0.0);
	//		//glVertex3f(-05.0 + x, -01.0 + y, 0.0);
	//		glEnd();
	//		xsize += 10.0;
	//	}
	//	ysize += 10.0;
	//}
	//glPopMatrix();
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
				glPushMatrix();
				glTranslatef(i*xsize, j*ysize, 0);
				someArray[i][j]->Render();
				glPopMatrix();
			}
		}
	}
}
