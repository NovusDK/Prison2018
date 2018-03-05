#include "Player.h"
#include <math.h>



Player::Player() : Player(0, 0, 0)
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
	x += direction * speed;
}

void Player::Render()
{
	glPushMatrix(); //Lægger en matrise på stakken, således kun denne manipuleres
	glBegin(GL_TRIANGLE_FAN);
	glTranslatef(x, y, z);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x, y, z);
	for (int i = 0; i <= 385; i++)
	{
		glVertex3f(x + (0.060f * cos(i * (2.0f * 3.14159) / 385)),
			y + (0.1f * sin(i * (2.0f * 3.14159) / 385)), 0);
	}
	glEnd();
	glPopMatrix(); // Fjerner matrisen på stakken (dvs. nulstiller til udgangspunkt)
}
