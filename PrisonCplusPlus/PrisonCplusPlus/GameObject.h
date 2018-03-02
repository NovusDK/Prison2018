#pragma once
class GameObject
{
private:	
	float x;
	float y;
	float z;

public:
	int health;
	float speed;

	GameObject();
	GameObject(float initX, float initY, float initZ);
	~GameObject();

	void virtual Update();
	void virtual Render();
};

