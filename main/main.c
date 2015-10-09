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

void moveSnakeOnce(int i)
{
	int a;
	if (i == 1)
	{
		for (a=zmija -> snakeLength - 1; a>0; a--)
		{
		zmija->tijelo[a].x=zmija->tijelo[a-1].x;
		zmija->tijelo[a].y = zmija->tijelo[a-1].y;
		}zmija->tijelo[0].x+= SNAKE_WIDTH;
	}
	else if(i == 2)
	{
		for (a=zmija -> snakeLength - 1; a>0; a--)
		{
			zmija->tijelo[a].x=zmija->tijelo[a-1].x;
			zmija->tijelo[a].y = zmija->tijelo[a-1].y;
		}zmija->tijelo[0].x-=SNAKE_WIDTH;
	}
	else if (i == 3)
	{
		for (a=zmija -> snakeLength - 1; a>0; a--)
		{
			zmija->tijelo[a].x=zmija->tijelo[a-1].x;
			zmija->tijelo[a].y = zmija->tijelo[a-1].y;
		}zmija->tijelo[0].y+=SNAKE_HEIGHT;
	}
	else if (i == 4)
	{
		for (a=zmija -> snakeLength - 1; a>0; a--)
		{
			zmija->tijelo[a].x=zmija->tijelo[a-1].x;
			zmija->tijelo[a].y = zmija->tijelo[a-1].y;;
		}zmija->tijelo[0].y-=SNAKE_HEIGHT;
	}
}
void moveSnake()
{
	if(flag == 1 && zmija->tijelo[0].x <= SCREEN_WIDTH)
	{
			moveSnakeOnce(1);
			if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
			{

				zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
				zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
				do
				{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				}
				while (getPixelColour(xx,yy,screen) != 0);
				putFood(food,screen,xx,yy);
			}
	}
	else if (flag == 2 && zmija->tijelo[0].x != 0 - SNAKE_WIDTH)
	{
		moveSnakeOnce(2);
		if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
		{

			zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
			zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
			do
			{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
			}
			while (getPixelColour(xx,yy,screen) != 0);
			putFood(food,screen,xx,yy);
		}
	}
	else if (flag == 3 && zmija->tijelo[0].y <= SCREEN_HEIGHT)
	{
		moveSnakeOnce(3);
		if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
		{

			zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
			zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
			do
			{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
			}
			while (getPixelColour(xx,yy,screen) == 1);
			putFood(food,screen,xx,yy);
		}
	}
	else if (flag == 4 && zmija->tijelo[0].y != 0 - SNAKE_HEIGHT)
	{
		moveSnakeOnce(4);
		if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
		{

			zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
			zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
			do
			{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
			}
			while (getPixelColour(xx,yy,screen) == 1);
			putFood(food,screen,xx,yy);
		}
	}
}
int main (int argc, char* args[])
{
	snakeInit();
	srandInitialize();
	SDL_Init(SDL_INIT_EVERYTHING);
	//Ucitavanje slika
	gameover = SDL_LoadBMP("resources/gameOver.bmp");
	screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE );
	snake = SDL_LoadBMP("resources/snake.bmp");
	black = SDL_LoadBMP("resources/black.bmp");
	food = SDL_LoadBMP("resources/food.bmp");
	score = SDL_LoadBMP("resources/score.bmp");
	xx = RandomRow()*36;
	yy = RandomColumn()*40;
	putFood(food,screen,xx,yy);
	zmija->tijelo[0].x = x;
	zmija->tijelo[0].y = y;
	zmija->tijelo[1].x = x1;
	zmija->tijelo[1].y = y1;
	int brojac;
	for (brojac = 0; brojac < zmija -> snakeLength; brojac++)
	apply_surface(zmija->tijelo[brojac].x-SNAKE_WIDTH,zmija->tijelo[brojac].y,snake,screen);

	int keyPressed = NOTHING_PRESSED;
	int quit = 1;
	while ((keyPressed=handleUserCommands()) != EXIT )
	{
		int counter;
		for(counter = 0; counter < zmija -> snakeLength; counter++)
		apply_surface(zmija->tijelo[counter].x,zmija->tijelo[counter].y,black, screen );
		if (keyPressed == 0 && zmija->tijelo[0].x <= SCREEN_WIDTH && flag != 2 ) //desno
		{
			flag = 1;
			moveSnakeOnce(1);
			if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
			{

				zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
				zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
				do
				{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				}
				while (getPixelColour(xx,yy,screen) == 1);
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == 2 && zmija->tijelo[0].x != 0 - SNAKE_WIDTH && flag != 1) //lijevo
		{
			flag=2;
			moveSnakeOnce(2);
			if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
			{

				zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
				zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
				do
				{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				}
				while (getPixelColour(xx,yy,screen) == 1);
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == 1 && zmija->tijelo[0].y <= SCREEN_HEIGHT && flag != 4 ) //dole
		{
			flag=3;
			moveSnakeOnce(3);
			if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
			{

				zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
				zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
				do
				{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				}
				while (getPixelColour(xx,yy,screen) != 0);
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == 3 && zmija->tijelo[0].y != 0 - SNAKE_HEIGHT && flag!=3) //gore
		{
			flag=4;
			moveSnakeOnce(4);
			if(xx == zmija->tijelo[0].x && yy==zmija->tijelo[0].y || xx == zmija->tijelo[1].x && yy==zmija->tijelo[1].y)
			{

				zmija->tijelo[zmija->snakeLength].x = zmija ->tijelo[zmija->snakeLength-1].x;
				zmija->tijelo[zmija->snakeLength].y = zmija ->tijelo[zmija->snakeLength-1].y;
				do
				{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				}
				while (getPixelColour(xx,yy,screen) == 1);
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == -3)
		{
			moveSnake();
		}

		for (counter = 0; counter < zmija -> snakeLength; counter++)
		apply_surface(zmija->tijelo[counter].x, zmija->tijelo[counter].y,snake, screen );
		SDL_Delay(zmija->delay);
		SDL_Flip(screen);
		if (zmija->tijelo[0].x == SCREEN_WIDTH  || zmija->tijelo[0].x == 0 - SNAKE_WIDTH || zmija->tijelo[0].y == SCREEN_HEIGHT || zmija->tijelo[0].y == 0 - SNAKE_HEIGHT)
		{
			printf("UKUPAN SCORE JE %d\n\n\n",getScore());
			printf("%d\n\n\n",zmija -> snakeLength);
			setGameOver(gameover,screen);
			return EXIT;
		}
	}

	SDL_FreeSurface( snake );
	SDL_Quit();
	return 0;
}
