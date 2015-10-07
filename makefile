all: controller gui main snake build

.PHONY: controller gui main snake build 

build:
	$(MAKE) -C build all
controller:
	$(MAKE) -C controller all
gui:
	$(MAKE) -C gui all
snake:
	$(MAKE) -C snake all	
main:
	$(MAKE) -C main all 



