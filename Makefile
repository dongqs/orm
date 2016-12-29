all: bin/main
	bin/main

bin/main: src/main.cpp
	g++ --std=c++1y -o bin/main src/main.cpp
