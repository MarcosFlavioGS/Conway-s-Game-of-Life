#include "../../include/cell.hpp"
#include "../../include/grid.hpp"

/**
 * Initialize the grid
*/
void init_grid(Cell grid[][COLS]) {
	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {
		 grid[i][j].cell.x += j * (CELL_SIZE + 3);
		 grid[i][j].cell.y += i * (CELL_SIZE + 3);

		 grid[i][j].x_min = grid[i][j].cell.x;
		 grid[i][j].y_min = grid[i][j].cell.y + CELL_SIZE - 1;

		 grid[i][j].x_max = grid[i][j].cell.x + CELL_SIZE - 1;
		 grid[i][j].y_max = grid[i][j].cell.y;
	   }
	}
}
