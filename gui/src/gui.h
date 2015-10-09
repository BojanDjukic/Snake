#ifndef GUI_H
#define GUI_H
#include "../../SDL/SDL.h"
#include "../../snake/src/snake.h"
#include "SDL/SDL_ttf.h"
#include<time.h>

#define RED_COLOR 0x00ff0000
#define GREEN_COLOR 0x0000ff00
#define BLUE_COLOR 0x000000ff
static int delay = 100;
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 640
#define SNAKE_WIDTH 36
#define SNAKE_HEIGHT 40
static int xx,yy;
static int result=-1;
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void setGameOver(SDL_Surface* gameover, SDL_Surface* screen );
void putFood(SDL_Surface* food, SDL_Surface* screen,int,int);
int getScore();
void srandInitialize();
int getPixelColour(int,int,SDL_Surface*);
void showScore(SDL_Surface*);


#endif
