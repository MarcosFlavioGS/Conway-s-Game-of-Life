#include "../../include/grid.hpp"
#include <iostream>

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

void update_grid(Cell grid[][COLS], Vector2* mouse_pos) {
	Cell new_grid[ROLLS][COLS];

	std::cout << "Hi " << mouse_pos->x << mouse_pos->y << std::endl;

	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {

		   bool clicked {grid[i][j].is_inside(mouse_pos)};
		   if (clicked) {
			   std::cout << "mouse x: " << mouse_pos->x << " - xmin and xmax: " << grid[i][j].x_min << " " << grid[i][j].x_max << std::endl;
			   std::cout << "mouse y: " << mouse_pos->y << " - ymin and ymax: " << grid[i][j].y_min << " " << grid[i][j].y_max << std::endl;
			   std::cout << "Clicked" << std::endl;
		   }

		   int alive {grid[i][j].is_alive()};
		   int score {check_neighbors(grid, i, j)};

		   switch (alive) {
			   case true: {

				   if (score < 2 || score > 3) {
					   if (clicked) new_grid[i][j].rise_my_child();
					   else new_grid[i][j].die_now();
				   } else {
					   new_grid[i][j].rise_my_child();
				   }
			   } break;
			   default: {
				   if (score == 3) {
					   new_grid[i][j].rise_my_child();
				   } else {
					   if (clicked) new_grid[i][j].rise_my_child();
					   else new_grid[i][j].die_now();
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
