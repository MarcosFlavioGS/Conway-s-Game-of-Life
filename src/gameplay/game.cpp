#include "../../include/grid.hpp"

void game(Cell grid[][COLS], bool* outline) {
	if (IsKeyReleased(KEY_R)) random_grid(grid);
	else if (IsKeyReleased(KEY_C)) clear_grid(grid);
	else if (IsKeyReleased(KEY_O)) *outline ^= true;
	
	update_grid(grid);
	
	ClearBackground(BACKGROUND_COLOR);

	for (int i {0}; i < ROLLS; i++) {
		for (int j {}; j < COLS; j++) {
			if (grid[i][j].is_alive()) DrawRectangleRounded(grid[i][j].cell, 0.3, 4, CELL_COLOR);
			if (*outline) DrawRectangleRoundedLines(grid[i][j].cell, 0.3, 4, LIGHTGRAY);
		}
	}
}
