all:main.o
	clang++ board.cpp main.cpp -lncursesw -o main.o
