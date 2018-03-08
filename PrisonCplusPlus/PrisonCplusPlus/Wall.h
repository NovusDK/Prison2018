#pragma once
#include "GameObject.h"
class Wall : public GameObject
{
private:
	float x;
	float y;
	float z;
public:
	Wall();
	Wall(float initX, float initY, float initZ);
	~Wall();
	void Render();
};

