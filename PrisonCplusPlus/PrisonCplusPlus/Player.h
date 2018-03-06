#pragma once
#include "GameObject.h"
class Player :	public GameObject
{
private:
	float x;
	float y;
	float z;
public:
	Player();
	Player(float initX, float initY, float initZ);
	~Player();
	void Update();
	void UpdateTwo();
	void Render();
};

