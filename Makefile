clean: 
	rm -rf build/

build:
	mkdir build
	gcc -c main.c -Iinc -o build/main.o
	gcc -c src/cclock.c -Iinc -o build/cclock.o
	gcc -c src/clock.c -Iinc -o build/clock.o
	gcc -c src/display.c -Iinc -o build/display.o
	gcc -c src/ledmatrix.c -Iinc -o build/ledmatrix.o
	gcc build/*.o -o build/centuryclock-v0.0.0-ubuntu24.04.3-x64-gcc13.3.0 -Llib -lecall 

run: build
	build/centuryclock-v0.0.0-ubuntu24.04.3-x64-gcc13.3.0

all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"
