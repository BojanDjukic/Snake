#include <stdio.h>
#include "main.h"
static int x1=0,y=40,x=36,y1=40;
static int flag;
static SDL_Surface* screen=NULL;
static SDL_Surface* gameover=NULL;
static SDL_Surface* food=NULL;
static SDL_Surface* snake=NULL;
static SDL_Surface* black=NULL;
void moveSnake()
{
	if(flag == 1 && x <= SCREEN_WIDTH)
	{
			x1=x;
			x+= SNAKE_WIDTH;
			y1 = y;
			if(xx == x1 && yy == y1)
			{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				putFood(food,screen,xx,yy);
			}
	}
	else if (flag == 2 && x != 0 - SNAKE_WIDTH)
	{
		x1=x;
		x-=SNAKE_WIDTH;
		y1 = y;
		if(xx == x1 && yy == y1)
		{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
			putFood(food,screen,xx,yy);
		}
	}
	else if (flag == 3 && y <= SCREEN_HEIGHT)
	{
		y1=y;
		y+=SNAKE_HEIGHT;
		x1 = x;
		if(xx == x1 && yy == y1)
		{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
			putFood(food,screen,xx,yy);
		}
	}
	else if (flag == 4 && y != 0 - SNAKE_HEIGHT)
	{
		y1=y;
		y-=SNAKE_HEIGHT;
		x1 = x;
		if(xx == x1 && yy == y1)
		{
			xx = RandomRow()*36;
			yy = RandomColumn()*40;
			putFood(food,screen,xx,yy);
		}
	}
}

int main (int argc, char* args[])
{


	SDL_Init(SDL_INIT_EVERYTHING);




	//Ucitavanje slika
	gameover = SDL_LoadBMP("resources/gameOver.bmp");
	screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE );
	snake = SDL_LoadBMP("resources/snake.bmp");
	black = SDL_LoadBMP("resources/black.bmp");
	food = SDL_LoadBMP("resources/food.bmp");
	xx = RandomRow()*36;
	yy = RandomColumn()*40;
	putFood(food,screen,xx,yy);
	printf("%d %d",xx,yy);
	apply_surface(x-SNAKE_WIDTH,y,snake,screen);
	apply_surface(x1,y1,snake,screen);
	int keyPressed = NOTHING_PRESSED;
	int quit = 1;
	while ((keyPressed=handleUserCommands()) != EXIT )
	{
		apply_surface(x,y,black, screen );
		apply_surface(x1,y1,black, screen );
		if (keyPressed == 0 && x <= SCREEN_WIDTH && flag != 2 ) //desno
		{
			flag = 1;
			x1=x;
			x+= SNAKE_WIDTH;
			y1 = y;
			if(xx == x1 && yy == y1)
			{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				putFood(food,screen,xx,yy);
			}
		}

		else if(keyPressed == 2 && x != 0 - SNAKE_WIDTH && flag != 1) //lijevo
		{
			flag=2;
			x1=x;
			x-=SNAKE_WIDTH;
			y1 = y;
			if(xx == x1 && yy == y1)
			{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == 1 && y <= SCREEN_HEIGHT && flag != 4 ) //dole
		{
			flag=3;
			y1=y;
			y+=SNAKE_HEIGHT;
			x1 = x;
			if(xx == x1 && yy == y1)
			{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == 3 && y != 0 - SNAKE_HEIGHT && flag!=3) //gore
		{
			flag=4;
			y1=y;
			y-=SNAKE_HEIGHT;
			x1 = x;
			if(xx == x1 && yy == y1)
			{
				xx = RandomRow()*36;
				yy = RandomColumn()*40;
				putFood(food,screen,xx,yy);
			}
		}
		else if(keyPressed == -3)
		{
			moveSnake();
		}

		apply_surface(x, y,snake, screen );
		apply_surface(x1, y1, snake, screen);
		SDL_Delay(75);
		SDL_Flip(screen);

		if (x == SCREEN_WIDTH  || x == 0 - SNAKE_WIDTH || y == SCREEN_HEIGHT || y == 0 - SNAKE_HEIGHT)
		{
			setGameOver(gameover,screen);
			return EXIT;

		}
	}
	SDL_FreeSurface( snake );
	SDL_Quit();
	return 0;
}
