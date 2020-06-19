#pragma once
class Player
{
	int score;
	bool lose;
public:
	Player();
	void setScore(int s);
	void setLose(bool s);
	int getScore();
	bool getLose();
	
};

