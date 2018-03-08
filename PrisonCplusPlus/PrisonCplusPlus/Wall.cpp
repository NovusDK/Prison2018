#include "Wall.h"
#include <math.h>



Wall::Wall()
{
}

Wall::Wall(float initX, float initY, float initZ)
{
	x = initX;
	y = initY;
	z = initZ;
}


Wall::~Wall()
{
}

void Wall::Render()
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glBegin(GL_POLYGON);
	glTranslatef(x, y, z);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0, 4.0, 0.0);
	glVertex3f(8.0, 4.0, 0.0);
	glVertex3f(8.0, 6.0, 0.0);
	glVertex3f(2.0, 6.0, 0.0);
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)
}
