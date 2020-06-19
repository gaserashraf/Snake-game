#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Snake
{
public:
	int HeadX, HeadY;
	vector<int>snakeX;
	vector<int>snakeY;
	int tail;

	Snake();
	void DirW();
	void DirS();
	void DirD();
	void DirA();
	void popTail();
	bool WorngDir();
	bool WorngDirHead();
};

