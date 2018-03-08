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
	//glTranslatef(x, y, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);

	for (x = 0; x < sizeX; x++)
	{

			glBegin(GL_LINES);
			//-1.0 + x* (1/ sizeX)
			glVertex3f(-1.0, -0.5 + x * (1.0 / sizeX), 0.0); // The bottom left corner  
			glVertex3f(1.0, -0.5 + x * (1.0 / sizeX), 0.0); // The bottom right corne;

			glEnd();
			
	}


		
	for (y = 0; y < sizeY; y++)
	{

		glBegin(GL_LINES);

		glVertex3f(-0.5 + y * (1.0 / sizeY), -1.0, 0.0); // The bottom left corner   
		glVertex3f(-0.5 + y * (1.0 / sizeY), 1.0, 0.0); // The bottom right corne;

		glEnd();

	}
	
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
				glTranslatef(i * (1.0/sizeX ), j *  (1.0 / sizeY), 0.0f);
				someArray[i][j]->Render();
				glPopMatrix();
			}
			
		}
	}
}
