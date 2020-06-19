#pragma once
#include"Player.h"
#include"Snake.h"
#include"Fruit.h"
class Grid
{
	Player player;
	Snake snake;
	Fruit fruit;
	char DIR;
public:
	Grid();
	void drawGrid();
	void readInput();
	void moveInSameDir();
	void play();
	bool findxysnake(int x, int y);
	bool findxyHeadsnake(int x, int y);
	void updateGird();
};

