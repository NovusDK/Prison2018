#pragma once
#include "GameObject.h"
#include "Wall.h"
class Grid
{
private:
	float x;
	float y;
	//float z;
	GameObject * someArray[10][10] = { };
public:
	Grid();
	~Grid();
	void Render();
	void RenderField();
	void AddGameObject(int x, int y, GameObject * g);
	void AddWall(int x, int y, Wall * w);
};

