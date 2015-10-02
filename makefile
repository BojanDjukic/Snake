all: controller gui main build

.PHONY: controller gui main build 


controller:
	$(MAKE) -C controller all
gui:
	$(MAKE) -C gui all
main:
	$(MAKE) -C main all 
build:
	$(MAKE) -C build all



