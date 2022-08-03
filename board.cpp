#include "board.h"
#include <iostream>

Piece *Board::generate(int number) 
{
	Piece *p = new Piece;
	p->piece_type = number;

	switch (p->piece_type) {
		// [0].y [0].x are rotation centers for all of these.
		case 1: // O
			p->coords[0].y = 0;
			p->coords[0].x = 0;
			p->coords[1].y = 0;
			p->coords[1].x = 1;
			p->coords[2].y = 1;
			p->coords[2].x = 0;
			p->coords[3].y = 1;
			p->coords[3].x = 1;
			break;
		case 2: // I
			p->coords[0].y = 2;
			p->coords[0].x = 0;
			p->coords[1].y = 0;
			p->coords[1].x = 0;
			p->coords[2].y = 1;
			p->coords[2].x = 0;
			p->coords[3].y = 3;
			p->coords[3].x = 0;
			break;
		case 3: // T
			p->coords[0].y = 1;
			p->coords[0].x = 1;
			p->coords[1].y = 1;
			p->coords[1].x = 0;
			p->coords[2].y = 0;
			p->coords[2].x = 1;
			p->coords[3].y = 1;
			p->coords[3].x = 2;
			break;
		case 4: // Z
			p->coords[0].y = 1;
			p->coords[0].x = 1;
			p->coords[1].y = 0;
			p->coords[1].x = 0;
			p->coords[2].y = 0;
			p->coords[2].x = 1;
			p->coords[3].y = 1;
			p->coords[3].x = 2;
			break;
		case 5: // S
			p->coords[0].y = 1;
			p->coords[0].x = 1;
			p->coords[1].y = 1;
			p->coords[1].x = 0;
			p->coords[2].y = 0;
			p->coords[2].x = 1;
			p->coords[3].y = 0;
			p->coords[3].x = 2;
			break;
		case 6: // L
			p->coords[0].y = 1;
			p->coords[0].x = 0;
			p->coords[1].y = 0;
			p->coords[1].x = 0;
			p->coords[2].y = 2;
			p->coords[2].x = 0;
			p->coords[3].y = 2;
			p->coords[3].x = 1;
			break;
		case 7: // J
			p->coords[0].y = 1; 
			p->coords[0].x = 1;
			p->coords[1].y = 0;
			p->coords[1].x = 1;
			p->coords[2].y = 2;
			p->coords[2].x = 1;
			p->coords[3].y = 2;
			p->coords[3].x = 0;
			break;
		default:
			break;
	}
	for (int i = 0; i < 4; i++) {
		if (board[p->coords[i].y][p->coords[i].x] == -1) {
			return nullptr;
		}
	}
	init_piece(*p, p->piece_type);

	return p;
}	

void Board::init_piece(Piece p, int fill_value) 
{
	board[p.coords[0].y][p.coords[0].x] = fill_value;
	board[p.coords[1].y][p.coords[1].x] = fill_value;
	board[p.coords[2].y][p.coords[2].x] = fill_value;
	board[p.coords[3].y][p.coords[3].x] = fill_value;
}

bool Board::fall(Piece *p) 
{
	if (p == nullptr) {
		return 0;
	}
	if (board[p->coords[0].y+1][p->coords[0].x] != -1 &&
	    board[p->coords[1].y+1][p->coords[1].x] != -1 &&
	    board[p->coords[2].y+1][p->coords[2].x] != -1 &&
	    board[p->coords[3].y+1][p->coords[3].x] != -1) 
	{
		if ((p->coords[0].y + 1 < 20) &&
		    (p->coords[1].y + 1 < 20) &&
		    (p->coords[2].y + 1 < 20) &&
		    (p->coords[3].y + 1 < 20)) 
		{
			init_piece(*p, 0);
			p->coords[0].y += 1;
			p->coords[1].y += 1;
			p->coords[2].y += 1;
			p->coords[3].y += 1;	
			init_piece(*p, p->piece_type);
			return 1;
		} 
		else {
			turn_inactive(p);
			return 0;
		}
	} 
	else {
		turn_inactive(p);
		return 0;
	}
}

bool Board::move_left(Piece* p) 
{
	if (board[p->coords[0].y][p->coords[0].x-1] != -1 &&
	    board[p->coords[1].y][p->coords[1].x-1] != -1 &&
	    board[p->coords[2].y][p->coords[2].x-1] != -1 &&
	    board[p->coords[3].y][p->coords[3].x-1] != -1) 
	{
		if ((p->coords[0].x - 1 >= 0) &&
		    (p->coords[1].x - 1 >= 0) &&
		    (p->coords[2].x - 1 >= 0) &&
		    (p->coords[3].x - 1 >= 0)) 
		{
			init_piece(*p, 0);
			p->coords[0].x -= 1;
			p->coords[1].x -= 1;
			p->coords[2].x -= 1;
			p->coords[3].x -= 1;	
			init_piece(*p, p->piece_type);
			return 1;
		} 
		else {
			return 0;
		}
	} 
	else {
		return 0;
	}
}

bool Board::move_right(Piece* p) 
{
	if (board[p->coords[0].y][p->coords[0].x+1] != -1 &&
	    board[p->coords[1].y][p->coords[1].x+1] != -1 &&
	    board[p->coords[2].y][p->coords[2].x+1] != -1 &&
	    board[p->coords[3].y][p->coords[3].x+1] != -1) 
	{
		if ((p->coords[0].x + 1 < 10) &&
		    (p->coords[1].x + 1 < 10) &&
		    (p->coords[2].x + 1 < 10) &&
		    (p->coords[3].x + 1 < 10)) 
		{
			init_piece(*p, 0);
			p->coords[0].x += 1;
			p->coords[1].x += 1;
			p->coords[2].x += 1;
			p->coords[3].x += 1;	
			init_piece(*p, p->piece_type);
			return 1;
		}
		else {
			return 0;
		}
	} 
	else {
		return 0;
	}
}

bool Board::rotate(Piece *p) 
{
	if (p->piece_type == 1) {
		return 0;
	}
	Coords *temp = new Coords[4];
	int x2, y2, cx, cy;
	cx = p->coords[0].x;
	cy = p->coords[0].y;
	temp[0].x = cx;
	temp[0].y = cy;
	for (int i = 1; i < 4; i++) {
		x2 = (cx+cy - p->coords[i].y);
		y2 = (p->coords[i].x + cy-cx);
		if (board[y2][x2] != -1) {
			if (x2 >= 0 && x2 < 10 &&
			    y2 >= 0 && y2 < 20) {
				temp[i].x = x2;
				temp[i].y = y2;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	}
	init_piece(*p, 0);
	for (int i = 0; i < 4; i++) {
		p->coords[i] = temp[i];
	}
	init_piece(*p, p->piece_type);
	return 1;
}

void Board::turn_inactive(Piece *p)
{
	p->is_active = 0;
	p->piece_type = -1;
	init_piece(*p, p->piece_type);

	check_row(p->coords[3].y);
	check_row(p->coords[2].y);
	check_row(p->coords[1].y);
	check_row(p->coords[0].y);
}

bool Board::check_row(int row)
{
	bool row_to_break;
	for (int k = row; k < 20; k++) {
		row_to_break = 1;
		for (int i = 0; i < 10; i++) {
			if (board[k][i] != -1) {
				row_to_break = 0;
				break;
			}
		}
		if (!row_to_break) continue;

		for (int i = k; i >= 0; i--) {
			for (int o = 0; o < 10; o++) {
				board[i][o] = board[i-1][o];
			}
		}

		for (int i = 0; i < 10; i++) {
			board[0][i] = 0;
		}
	}

	return 1;
}
