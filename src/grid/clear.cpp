#include "../../include/grid.hpp"

/**
 * Clear the grid
 */
void clear_grid(Cell grid[][COLS]) {
	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {
		 grid[i][j].die_now();
	   } 
	}
}
