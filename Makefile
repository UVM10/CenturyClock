clean:
	echo "Replace this by command(s) to clean all the build files"

build:
	echo "Replace this by command(s) to build the project"

run:
	echo "Replace this by command(s) to run the Century Clock"

all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"