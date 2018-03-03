#include "Player.h"
#include <math.h>



Player::Player() : Player(0, 0, 1)
{
}

Player::Player(float initX, float initY, float initZ)
{
	this->health = 3;
	this->speed = 0.001;
	this->direction = 1;
	x = initX;
	y = initY;
	z = initZ;
}


Player::~Player()
{
}

void Player::Update()
{

}

void Player::Render()
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glTranslatef(x, y, z);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 100; i++)
	{
		glVertex3f(cos(2 * 3.14159*i / 100.0), sin(2 * 3.14159*i / 100.0), 0);
	}
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)
}
