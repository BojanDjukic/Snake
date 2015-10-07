#include "gui.h"



void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface( source, NULL, destination, &offset );
}


void setGameOver(SDL_Surface* gameover, SDL_Surface* screen )
{
	apply_surface((SCREEN_WIDTH/2) - 222, (SCREEN_HEIGHT/2) - 64, gameover, screen);
	SDL_Flip (screen);
	SDL_Delay(2000);
}


int RandomRow()
{
	srand(time(NULL));
	int row = rand() %30 ;
	return row;
}

int RandomColumn()
{
	srand(time(NULL));
	int column = rand() % 16  ;
	return column;
}


void putFood(SDL_Surface* food, SDL_Surface* screen,int xx,int yy)
{
	//xx=RandomRow()*36;
	//yy=RandomColumn()*40;
	apply_surface(xx, yy, food, screen);
	//SDL_Flip (screen);
}
