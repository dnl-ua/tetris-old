#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "board.h"

void print(Board);

int main() 
{
	Board b;
	print(b);

	while (1) {
		Piece *p = new Piece;
		p = b.generate((rand() % 4) + 1);

		while (b.fall(p)) {
			std::cout << p->coords[0].y << " " << p->coords[0].x << "\n";
			std::cout << p->coords[1].y << " " << p->coords[1].x << "\n";
			std::cout << p->coords[2].y << " " << p->coords[2].x << "\n";
			std::cout << p->coords[3].y << " " << p->coords[3].x << "\n";
			print(b);
			usleep(100000);
		}
	}

	return 0;
}

void print(Board b) {
	for (int i = 0; i < 20; i++) {
		for (int o = 0; o < 10; o++) {
			if (b.board[i][o] == 0) {
				std::cout << ". ";
			} else if (b.board[i][o] == -1) {
				std::cout << "+ ";
			} else {
				std::cout << b.board[i][o] << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
