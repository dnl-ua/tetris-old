all:main.o
	clang++ board.cpp main.cpp -lncurses -o main.o
