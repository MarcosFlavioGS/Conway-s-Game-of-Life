#include "../../include/grid.hpp"

static int check_neighbors(Cell g[][COLS], int i, int j) {
	int up { g[i - 1][j - 1].alive + g[i - 1][j].alive + g[i - 1][j + 1].alive };
	int middle { g[i][j - 1].alive + g[i][j + 1].alive };
	int down { g[i + 1][j - 1].alive + g[i + 1][j].alive + g[i + 1][j + 1].alive };
	
	return up + middle + down;
}

void update_grid(Cell grid[][COLS]) {
	Cell new_grid[ROLLS][COLS];

	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {
		   int alive {grid[i][j].is_alive()};
		   int score {check_neighbors(grid, i, j)};

		   switch (alive) {
			   case true: {
				   if (score < 2 || score > 3) {
					   new_grid[i][j].die_now();
				   } else {
					   new_grid[i][j].rise_my_child();
				   }
			   } break;
			   default: {
				   if (score == 3) {
					   new_grid[i][j].rise_my_child();
				   } else {
					   new_grid[i][j].die_now();
				   }
			   }
		   };
	   } 
	}
	for (int i = 0; i < ROLLS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].alive = new_grid[i][j].alive;
        }
    }
}
