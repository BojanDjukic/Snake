CC=gcc

all: snake tests build

.PHONY: snake tests build

snake:
	$(CC) -c src/snake.c -o ../build/snake.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all 
