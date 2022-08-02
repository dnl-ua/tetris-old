#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include "board.h"

void print(Board);

int main() 
{
	Board b;
	print(b);
	Piece *p = nullptr;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7); 
	p = b.generate(dist7(rng));
	while (p != nullptr) {
		p = b.generate(dist7(rng));

		while (b.fall(p)) {
			std::cout << "\n";
			std::cout << p->coords[0].y << " " << p->coords[0].x << "\n";
			std::cout << p->coords[1].y << " " << p->coords[1].x << "\n";
			std::cout << p->coords[2].y << " " << p->coords[2].x << "\n";
			std::cout << p->coords[3].y << " " << p->coords[3].x << "\n\n";
			b.move_right(p);
			b.rotate(p);
			print(b);
			usleep(100000);
		}
	}

	return 0;
}

void print(Board b) {
	std::cout << "+====================+\n";
	for (int i = 0; i < 20; i++) {
		std::cout << "|";
		for (int o = 0; o < 10; o++) {
			if (b.board[i][o] == 0) {
				std::cout << "  ";
			} else if (b.board[i][o] == -1) {
				std::cout << "+ ";
			} else {
				std::cout << b.board[i][o] << " ";
			}
		}
		std::cout << "|\n";
	}
	std::cout << "+====================+\n";
}
