#include "Snake.h"

Snake::Snake()
{
	HeadX = 15;
	HeadY = 10;
	snakeX.push_back(15);
	snakeY.push_back(10);
	tail = 1;
}

void Snake::DirW()
{
	snakeX.insert(snakeX.begin(), snakeX[0]);
	snakeY.insert(snakeY.begin(), snakeY[0]-1);
}

void Snake::DirS()
{
	snakeX.insert(snakeX.begin(), snakeX[0]);
	snakeY.insert(snakeY.begin(), snakeY[0] + 1);
}

void Snake::DirD()
{
	snakeX.insert(snakeX.begin(), snakeX[0]+1);
	snakeY.insert(snakeY.begin(), snakeY[0]);
}

void Snake::DirA()
{
	snakeX.insert(snakeX.begin(), snakeX[0]-1);
	snakeY.insert(snakeY.begin(), snakeY[0]);
}

void Snake::popTail()
{
	snakeX.pop_back();
	snakeY.pop_back();
}

bool Snake::WorngDir()
{
	if (snakeY[0] == 19 || snakeY[0] == 0 || snakeX[0] == 0 || snakeX[0] == 29)
		return 1;
	
	return false;
}

bool Snake::WorngDirHead()
{
	int Y = 0, X = 0;
	for (int i = 1; i < snakeY.size(); i++)
		if (snakeY[i] == snakeY[0]&& snakeX[i] == snakeX[0])
		{
			return 1;
		}

	return 0;
	
}
