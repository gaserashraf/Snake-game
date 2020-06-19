#include "Fruit.h"

void Fruit::genretePos()
{
	srand((unsigned)time(0));
	FruitX = 1+(rand() % 28);
	FruitY = 1+(rand() % 18);
}

Fruit::Fruit()
{
	genretePos();
}
