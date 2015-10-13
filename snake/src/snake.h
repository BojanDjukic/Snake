#ifndef SNAKE_H
#define SNAKE_H
#include "../../SDL/SDL.h"
#include "../../gui/src/gui.h"
int isOnSnake(int xx, int yy);
int isSnakeDead();
typedef struct Body
{
  int x;
  int y;
}BODY;

typedef struct Snake
{
  BODY tijelo[100];
  int snakeLength;
  int delay;
}SNAKE;

SNAKE* zmija;
SNAKE* snakeInit();


#endif
