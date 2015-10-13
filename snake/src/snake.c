#include "snake.h"


SNAKE* snakeInit()
{

  zmija = (SNAKE*)malloc(sizeof(SNAKE));
  zmija -> snakeLength = 1;
  zmija -> delay = 120;
  return zmija;
}

int isOnSnake(int xx, int yy)
{
	int i;
	for (i = 0; i < zmija -> snakeLength; i++)
	{
		if (xx == zmija->tijelo[i].x && yy == zmija->tijelo[i].y)
		{
		return 1; break;
		}
	}
	return 0;
}
int isSnakeDead()
{
	int i;
	for (i = 2; i < zmija->snakeLength ; i++)
	{
		if (zmija->tijelo[0].x == zmija->tijelo[i].x && zmija->tijelo[0].y == zmija->tijelo[i].y)
		{
			return 1;break;
		}
	}
	return 0;
}
