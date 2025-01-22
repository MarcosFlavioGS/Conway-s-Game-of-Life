#include "../../include/grid.hpp"

/**
 * Randomize the grid values
 */
void random_grid(std::vector<std::vector<Cell>>* grid) {
	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {
		 (*grid)[i][j].alive = GetRandomValue(0, 1);
	   } 
	}
}
