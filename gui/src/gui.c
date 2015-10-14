#include "gui.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface( source, NULL, destination, &offset );
}
void srandInitialize()
{
	time_t t;
	srand((unsigned) time(&t));
}
int RandomRow()
{
	int row = rand() % 45;
	return row;
}
int RandomColumn()
{
	int column = rand() % 19;
	return column;
}
void putFood(SDL_Surface* food, SDL_Surface* screen,int xx,int yy)
{
	apply_surface(xx, yy, food, screen);
	result++;
	zmija -> snakeLength++;
	if (zmija -> delay < 90)
	{
		zmija -> delay -= 1;
	}
	else
	zmija -> delay -= 5;
}
int getScore()
{
	return result;
}
static void intToString(int number, char points[])
{
	char sym[2];
	int i = 0, j = 0;
	while (number)
	{
		sym[i] = number % 10 + '0';
		i++;
		number /= 10;
	}
	while(i > 0)
	{
		points[j] = sym[i-1];
		i--;
		j++;
	}
	points[j] = '\0';
}
void setGameOver(SDL_Surface* gameover, SDL_Surface* screen )
{
	char points[3];
	intToString(result, points);
	SDL_Surface* message = NULL;
	SDL_Surface* score = NULL;
	TTF_Font* font = NULL;
	SDL_Color textColor = {255, 255, 255};
	TTF_Init();
	font = TTF_OpenFont("resources/open-sans/OpenSans-ExtraBoldItalic.ttf",30);
	message = TTF_RenderText_Solid(font, "Score:", textColor);
	score = TTF_RenderText_Solid(font, points, textColor);
	SDL_Rect m;
	m.x = 100;
	m.y = 90;
	SDL_Rect s;
	s.x = 222;
	s.y = 90;
	SDL_BlitSurface(message, NULL, gameover, &m);
	SDL_BlitSurface(score, NULL, gameover, &s);
	apply_surface((SCREEN_WIDTH/2) - 222, (SCREEN_HEIGHT/2) - 64, gameover, screen);
	SDL_Flip (screen);
	SDL_Delay(2000);
	SDL_FreeSurface(message);
	SDL_FreeSurface(score);
	TTF_CloseFont(font);
	TTF_Quit();
}
