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
	int i = 0;
	for (i = 0; i < zmija -> snakeLength; i++)
	{
		if (xx == zmija -> tijelo[i].x
                                  && yy == zmija -> tijelo[i].y)
		{
		    return 1;
        break;
		}
	}
	return 0;
}
int isSnakeDead()
{
	int i = 0;
	for (i = 2; i < zmija -> snakeLength ; i++)
	{
		if (zmija -> tijelo[0].x == zmija -> tijelo[i].x
                                                    && zmija -> tijelo[0].y == zmija -> tijelo[i].y)
		{
			   return 1;
         break;
		}
	}
	return 0;
}
void checkBoundaries()
{
  if (zmija -> tijelo[0].x == SCREEN_WIDTH )
  {
    zmija -> tijelo[0].x = 0;
  }
  else if (zmija -> tijelo[0].y == SCREEN_HEIGHT)
  {
    zmija -> tijelo[0].y = 0;
  }
  else if (zmija -> tijelo[0].x == 0 - SNAKE_WIDTH)
  {
    zmija -> tijelo[0].x = SCREEN_WIDTH;
  }
  else if (zmija -> tijelo[0].y == 0 - SNAKE_HEIGHT)
  {
    zmija -> tijelo[0].y = SCREEN_HEIGHT;
  }
}
void takeNewCoordinates(int a)
{
  zmija -> tijelo[a].x = zmija -> tijelo[a-1].x;
  zmija -> tijelo[a].y = zmija -> tijelo[a-1].y;
}
