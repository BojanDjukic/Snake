#include "snake.h"


SNAKE* snakeInit()
{

  zmija = (SNAKE*)malloc(sizeof(SNAKE));
  zmija -> snakeLength = 1;
  zmija -> delay = 120;
  return zmija;
}
