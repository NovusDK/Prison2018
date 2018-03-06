#include "GameObject.h"
#include <GLFW\glfw3.h>



GameObject::GameObject() : GameObject(health, speed, 0,0,0)
{
	health;
	speed = 0.03;
	direction = 1;
}

GameObject::GameObject(int health, float speed, float initX, float initY, float initZ)
{
	health = 10;
	speed;
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
	x += direction * speed; // Her kan vi stille hastighed på piletasterne
}

void GameObject::Render()
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-20.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 20.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)
}
