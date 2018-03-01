#pragma once
class GameObject
{
private:
	
	int health;
	float speed;

	float x;
	float y;
	float z;

public:

	GameObject();
	GameObject(int health, float speed, float initX, float initY, float initZ);
	~GameObject();

	void virtual Update();
	void virtual Render();
};

