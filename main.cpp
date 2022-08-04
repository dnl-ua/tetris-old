#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <locale.h>
#include "board.h"

void print(Board);
void printn(Board);

int main() 
{
	setlocale(LC_ALL, "");

	initscr();
	curs_set(FALSE);
	clear();
	noecho();
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	refresh();

	int c;

	Board b;
	Piece *p = nullptr;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7); 

	p = b.generate(dist7(rng));

	while (p != nullptr) {
		c = wgetch(stdscr);
		switch (c) {
			case KEY_UP:
				b.rotate(p);
				break;
			case KEY_LEFT:
				b.move_left(p);
				break;
			case KEY_RIGHT:
				b.move_right(p);
				break;
			case KEY_DOWN:
				if (!b.fall(p)) {
					p = b.generate(dist7(rng));
				}
				usleep(20000);
				break;
			case ' ':
				while (b.fall(p)) ;
				p = b.generate(dist7(rng));
				break;
			case 'q':
				endwin();
				return 0;
				break;
			default:
				if (!(b.fall(p))) {
					p = b.generate(dist7(rng));
				}
				usleep(300000);
				break;
		}
		clear();
		printn(b);
		refresh();
	}

	printw("\nthe end\npress something to exit\n");
	getch();
	refresh();
	endwin();

	return 0;
}

void printn(Board b) {
	printw("+====================+\n");
	for (int i = 0; i < 20; i++) {
		printw("|");
		for (int o = 0; o < 10; o++) {
			if (b.board[i][o] == 0) {
				printw("  ");
			} else {
				printw("■ ");
			}
		}
		printw("|\n");
	}
	printw("+====================+\n");
}
