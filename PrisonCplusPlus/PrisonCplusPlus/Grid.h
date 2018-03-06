#pragma once
class Grid
{
private:
	float x;
	float y;
	float z;
	float someArray[10][10] = { };
public:
	Grid();
	~Grid();
	void Render();
	void RenderField();
};

