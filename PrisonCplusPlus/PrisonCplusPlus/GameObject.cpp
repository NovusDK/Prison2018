#include "GameObject.h"
#include <GLFW\glfw3.h>


GameObject::GameObject() : GameObject(0,0,0)
{
}

GameObject::GameObject(float initX, float initY, float initZ)
{
	health = 10;
	speed = 0.001;
	direction = 1;
	x = initX;
	y = initY;
	z = initZ;
}


GameObject::~GameObject()
{
}

void GameObject::Update()
{
	x += direction * speed;
}

void GameObject::Render()
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)
}
