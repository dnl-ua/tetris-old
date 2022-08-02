#include "piece.h"

class Board {
	public:
		int board[20][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		    		     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

		Piece *generate(int);
		void init_piece(Piece, int);
		bool fall(Piece*);
		bool move_left(Piece*);
		bool move_right(Piece*);
		bool rotate(Piece *p);
		void turn_inactive(Piece*);
		bool check_row(int);
};
