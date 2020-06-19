#include "Grid.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>
Grid::Grid()
{
	DIR = 'd';
	drawGrid();
}

void Grid::drawGrid()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 19)
				cout << "#";
			else if (j == 0 || j == 29)
				cout << "#";
			else if (i == fruit.FruitY && j == fruit.FruitX)
				cout << "o";
			else if (i == snake.snakeY[0] && j == snake.snakeX[0])
				cout << "0";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void Grid::readInput()
{
	bool des = 1;
	if (_kbhit())//new dirtion
	{
		char c = _getch();
		
		switch (c)
		{
		case 'w':
			if (DIR != 's')
			{
				snake.DirW();
				DIR = c;
			}
			else
				moveInSameDir();
			//snake.increseInYDir();
			break;
		case 's':
			if (DIR != 'w')
			{
				snake.DirS();
				DIR = c;
			}
			else
				moveInSameDir();
				//snake.decreseInYDir();
			break;
		case 'd':
			if (DIR != 'a')
			{
				snake.DirD();
				DIR = c;
			}
			else
				moveInSameDir();
				//snake.increseInXDir();
			break;
		case 'a':
			if (DIR != 'd')
			{
				snake.DirA();
				DIR = c;
			}
			else
				moveInSameDir();
				//snake.decreseInXDir();
			break;
		
		}
		
		
		
	}
	else //same dirction
	{
		
		moveInSameDir();
		
	}
	if (snake.snakeX[0] == fruit.FruitX && snake.snakeY[0] == fruit.FruitY)
	{

		fruit.genretePos();
		while (findxysnake(fruit.FruitX, fruit.FruitY))
		{
			fruit.genretePos();
		}
		des = 0;
	}
	if(des)
		snake.popTail();
	else
	{
		player.setScore(player.getScore() + 1);
	}
	if (snake.WorngDir() == 1|| snake.WorngDirHead())//||findxyHeadsnake(snake.snakeX[0], snake.snakeX[0]))
	{
		cout << "\nGame Over \n";
		exit(0);
	}
	

	
}

void Grid::moveInSameDir()
{
	switch (DIR)
	{
	case 'w':
		snake.DirW();
		//snake.increseInYDir();
		break;
	case 's':
		snake.DirS();
		//snake.decreseInYDir();
		break;
	case 'd':
		snake.DirD();
		//snake.increseInXDir();
		break;
	case 'a':
		snake.DirA();
		//snake.decreseInXDir();
		break;
	}
}

void Grid::play()
{
	while (!player.getLose())
	{
		readInput();
		updateGird();
		Sleep(100);
	}
}

bool Grid::findxysnake(int x, int y)
{
	int Y = 0,X=0;
	for(int i=0;i<snake.snakeY.size();i++)
		if (snake.snakeY[i] == y&& snake.snakeX[i] == x)
		{
			return 1;
		}
	
	return 0;
	//return X&&Y?1:0;
}
bool Grid::findxyHeadsnake(int x, int y)
{
	int Y = 0, X = 0;
	for (int i = 1; i < snake.snakeY.size(); i++)
		if (snake.snakeY[i] == y && snake.snakeX[i] == x)
		{
			return 1;
		}

	return 0;
	//return X&&Y?1:0;
}

void Grid::updateGird()
{
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			/*std::vector<int>::iterator itX;
			itX = find(snake.snakeX.begin(),snake.snakeX.end(), i);
			std::vector<int>::iterator itY;
			itY = find(snake.snakeY.begin(), snake.snakeY.end(), j);*/
			if (i == 0 || i == 19)
				cout << "#";
			else if (j == 0 || j == 29)
				cout << "#";
			else if (i == fruit.FruitY && j == fruit.FruitX)
				cout << "o";
			else if (i == snake.snakeY[0] && j == snake.snakeX[0])
				cout << "O";
			else if (findxysnake(j, i))
				cout << 'o';
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "Your Score is "<<player.getScore();
}
