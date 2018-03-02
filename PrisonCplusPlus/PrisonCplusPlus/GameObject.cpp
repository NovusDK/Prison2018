#include "GameObject.h"
#include <GLFW\glfw3.h>



GameObject::GameObject() : GameObject(health, speed, 0,0,0)
{
	health = 10;
	speed = 100;
	direction = 1;
}

GameObject::GameObject(int health, float speed, float initX, float initY, float initZ)
{
	health = 10;
	speed = 100;
	x = initX;
	y = initY;
	z = initZ;

	direction = 1;
}


GameObject::~GameObject()
{
}

void GameObject::Update()
{
	x += speed;
}

void GameObject::Render()
{
	glPushMatrix(); //L�gger en matrise p� stakken, s�ledes kun denne manipuleres
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 20.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix(); // Fjerner matrisen p� stakken (dvs. nulstiller til udgangspunkt)
}
