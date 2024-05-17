.PHONY: all
all: main

main: main.cpp game.cpp game.h colors.cpp colors.h
	g++ -std=c++17 main.cpp game.cpp colors.cpp -o wordle -g

.PHONY: clean
clean:
	rm -f wordle test main 