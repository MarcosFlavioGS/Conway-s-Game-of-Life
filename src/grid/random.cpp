#include "../../include/grid.hpp"

/**
 * Randomize the grid values
 */
void random_grid(Cell grid[][COLS]) {
	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {
		 grid[i][j].alive = GetRandomValue(0, 1);
	   } 
	}
}
