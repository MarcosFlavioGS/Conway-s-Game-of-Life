#include "../../include/grid.hpp"

/**
 * Clear the grid
 */
void clear_grid(std::vector<std::vector<Cell>>* grid) {
	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {
		 (*grid)[i][j].die_now();
	   } 
	}
}
