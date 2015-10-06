CC=gcc

all: controller tests build

.PHONY: controller tests build

controller:
	$(CC) -c src/controller.c -o ../build/controller.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all 
