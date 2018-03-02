#include "GameObject.h"
#include <GLFW\glfw3.h>

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

int direction = DOWN;

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
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix(); // Fjerner matrisen p� stakken (dvs. nulstiller til udgangspunkt)
}
