clean: 
	rm -rf build/

build:
	mkdir build
	gcc -c main.c -Iinc -o build/main.o
	gcc -c src/cclock.c -Iinc -o build/cclock.o
	gcc -c src/clock.c -Iinc -o build/clock.o
	gcc -c src/display.c -Iinc -o build/display.o
	gcc -c src/ledmatrix.c -Iinc -o build/ledmatrix.o
	ar rcs build/libcenclk.a build/cclock.o build/clock.o build/display.o build/ledmatrix.o
	gcc build/main.o build/libcenclk.a lib/libecall.a -o build/centuryclock

run: build
	build/centuryclock

all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"
