#pragma once
#include <GLFW\glfw3.h>

class GameObject
{
private:	
	float x;
	float y;
	float z;

public:
	int health;
	float speed;
	int direction;
	GameObject();
	GameObject(float initX, float initY, float initZ);
	~GameObject();
	void virtual Update();
	void virtual Render();
};

