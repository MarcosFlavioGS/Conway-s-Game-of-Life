#include "../../include/grid.hpp"

void game(Cell grid[][COLS], bool* outline, bool* update, int* frame_counter, bool* auto_random) {
	if (IsKeyPressed(KEY_R)) random_grid(grid);
	else if (IsKeyReleased(KEY_C)) clear_grid(grid);
	else if (IsKeyReleased(KEY_O)) *outline ^= true;
	else if (IsKeyReleased(KEY_SPACE)) *update ^= true;
	else if (IsKeyReleased(KEY_U)) *auto_random ^= true;

	*frame_counter += *update ? 1 : 1 + -1; // stalls counter while update is off

	if (*auto_random && *frame_counter > (180 * FRAME_RATE)) { // 3 min
		random_grid(grid);
		*frame_counter = 0;
	}

	if (*update) update_grid(grid);
	
	ClearBackground(BACKGROUND_COLOR);

	for (int i {0}; i < ROLLS; i++) {
		for (int j {}; j < COLS; j++) {
			if (grid[i][j].is_alive()) DrawRectangleRounded(grid[i][j].cell, 0.3, 4, CELL_COLOR);
			if (*outline) DrawRectangleRoundedLines(grid[i][j].cell, 0.3, 4, LIGHTGRAY);
		}
	}
}
