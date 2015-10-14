#include <stdio.h>
#include "main.h"
static int x1=0,y=40,x=36,y1=40;
static int flag;
static SDL_Surface* screen=NULL;
static SDL_Surface* score=NULL;
static SDL_Surface* gameover=NULL;
static SDL_Surface* food=NULL;
static SDL_Surface* snake=NULL;
static SDL_Surface* black=NULL;
static void generateAvailablePlace()
{
	do
	{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
	}
	while (isOnSnake(xx, yy) == 1);
}
static void moveSnakeOnce(int direction)
{
	int a = 0;
	if (direction == RIGHT)
	{
		for (a = zmija -> snakeLength - 1; a > 0; a--)
		{
			takeNewCoordinates(a);
		}
		zmija -> tijelo[0].x += SNAKE_WIDTH;
	}
	else if(direction == LEFT)
	{
		for (a = zmija -> snakeLength - 1; a>0; a--)
		{
			takeNewCoordinates(a);
		}
		zmija -> tijelo[0].x -= SNAKE_WIDTH;
	}
	else if (direction == DOWN)
	{
		for (a = zmija -> snakeLength - 1;a > 0; a--)
		{
			takeNewCoordinates(a);
		}
		zmija -> tijelo[0].y += SNAKE_HEIGHT;
	}
	else if (direction == UP)
	{
		for (a = zmija -> snakeLength - 1;a > 0; a--)
		{
			takeNewCoordinates(a);
		}
		zmija -> tijelo[0].y -= SNAKE_HEIGHT;
	}
}
void moveSnake()
{
	if(flag == 1
							&& zmija -> tijelo[0].x <= SCREEN_WIDTH)
	{
			moveSnakeOnce(RIGHT);
			if(xx == zmija -> tijelo[0].x
																	&& yy == zmija -> tijelo[0].y
																															|| xx == zmija->tijelo[1].x
																																												&& yy == zmija->tijelo[1].y)
			{
					generateAvailablePlace();
					takeNewCoordinates(zmija -> snakeLength);
					putFood(food, screen, xx, yy);
			}
	}
	else if (flag == 2
										&& zmija -> tijelo[0].x != 0 - SNAKE_WIDTH)
	{
		moveSnakeOnce(LEFT);
		if(xx == zmija -> tijelo[0].x
															&& yy == zmija -> tijelo[0].y
																											|| xx == zmija -> tijelo[1].x
																																									&& yy == zmija -> tijelo[1].y)
		{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
		}
	}
	else if (flag == 3
										&& zmija -> tijelo[0].y <= SCREEN_HEIGHT)
	{
		moveSnakeOnce(DOWN);
		if(xx == zmija -> tijelo[0].x
																&& yy == zmija -> tijelo[0].y
																														|| xx == zmija->tijelo[1].x
																																											&& yy == zmija->tijelo[1].y)
		{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
		}
	}
	else if (flag == 4
										&& zmija -> tijelo[0].y != 0 - SNAKE_HEIGHT)
	{
		moveSnakeOnce(UP);
		if(xx == zmija -> tijelo[0].x
																&& yy == zmija -> tijelo[0].y
																														|| xx == zmija -> tijelo[1].x
																																												&& yy == zmija -> tijelo[1].y)
		{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
		}
	}
}
int main (int argc, char* args[])
{
	snakeInit();
	srandInitialize();
	SDL_Init(SDL_INIT_EVERYTHING);
	gameover = SDL_LoadBMP("resources/gameOver.bmp");
	screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE );
	snake = SDL_LoadBMP("resources/snake.bmp");
	black = SDL_LoadBMP("resources/black.bmp");
	food = SDL_LoadBMP("resources/food.bmp");
	score = SDL_LoadBMP("resources/score.bmp");
	xx = RandomRow()*36;
	yy = RandomColumn()*40;
	putFood(food, screen, xx, yy);
	zmija -> tijelo[0].x = x;
	zmija -> tijelo[0].y = y;
	zmija -> tijelo[1].x = x1;
	zmija -> tijelo[1].y = y1;
	int brojac = 0;
	for (brojac = 0; brojac < zmija -> snakeLength; brojac++)
	apply_surface(zmija -> tijelo[brojac].x - SNAKE_WIDTH,zmija -> tijelo[brojac].y, snake, screen);
	int keyPressed = NOTHING_PRESSED;
	int quit = 1;
	while ((keyPressed = handleUserCommands()) != EXIT )
	{
		int counter = 0;
		for(counter = 0; counter < zmija -> snakeLength; counter++)
		apply_surface(zmija -> tijelo[counter].x,zmija -> tijelo[counter].y, black, screen );
		if (keyPressed == 0
											&& zmija -> tijelo[0].x <= SCREEN_WIDTH
																														&& flag != 2 ) //desno
		{
			flag = 1;
			moveSnakeOnce(RIGHT);
			if(xx == zmija -> tijelo[0].x
																	&& yy == zmija->tijelo[0].y
																														|| xx == zmija->tijelo[1].x
																																											&& yy == zmija -> tijelo[1].y)
			{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
			}
		}
		else if(keyPressed == 2
													&& zmija -> tijelo[0].x != 0 - SNAKE_WIDTH
																																	&& flag != 1) //lijevo
		{
			flag = 2;
			moveSnakeOnce(LEFT);
			if(xx == zmija -> tijelo[0].x
																	&& yy == zmija -> tijelo[0].y
																															|| xx == zmija -> tijelo[1].x
																																													&& yy == zmija -> tijelo[1].y)
			{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
			}
		}
		else if(keyPressed == 1
													&& zmija -> tijelo[0].y <= SCREEN_HEIGHT
																																	&& flag != 4 ) //dole
		{
			flag = 3;
			moveSnakeOnce(DOWN);
			if(xx == zmija -> tijelo[0].x
																	&& yy == zmija -> tijelo[0].y
																														|| xx == zmija -> tijelo[1].x
																																											&& yy == zmija -> tijelo[1].y)
			{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
			}
		}
		else if(keyPressed == 3
													&& zmija -> tijelo[0].y != 0 - SNAKE_HEIGHT
																																		&& flag != 3) //gore
		{
			flag = 4;
			moveSnakeOnce(UP);
			if(xx == zmija -> tijelo[0].x
																	&& yy == zmija -> tijelo[0].y
																															|| xx == zmija -> tijelo[1].x
																																													&& yy == zmija -> tijelo[1].y)
			{
				generateAvailablePlace();
				takeNewCoordinates(zmija -> snakeLength);
				putFood(food, screen, xx, yy);
			}
		}
		else if(keyPressed == -3)
		{
			moveSnake();
		}
		for (counter = 0; counter < zmija -> snakeLength; counter++)
		apply_surface(zmija -> tijelo[counter].x, zmija -> tijelo[counter].y, snake, screen);
		SDL_Delay(zmija -> delay);
		SDL_Flip(screen);
		checkBoundaries();
		if (isSnakeDead() == 1)
		{
			setGameOver(gameover, screen);
			return EXIT;
		}
	}
	SDL_FreeSurface( snake );
	SDL_Quit();
	return 0;
}
