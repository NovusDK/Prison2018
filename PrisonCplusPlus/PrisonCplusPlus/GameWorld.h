#pragma once
class GameWorld
{
private:
	GLFWwindow * window;
public:
	GameWorld();
	~GameWorld();

private:
	void GameLogic();
};



