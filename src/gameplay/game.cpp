#include "../../include/grid.hpp"

void game(Cell grid[][COLS], bool* outline, bool* update, int* frame_counter, bool* auto_random, Vector2* mouse_pos, bool* mouse) {

	if (IsKeyPressed(KEY_R)) random_grid(grid);
	else if (IsKeyReleased(KEY_C)) clear_grid(grid);
	else if (IsKeyReleased(KEY_O)) *outline ^= true;
	else if (IsKeyReleased(KEY_SPACE)) *update ^= true;
	else if (IsKeyReleased(KEY_U)) *auto_random ^= true;
	else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		*mouse = true;
		*mouse_pos = GetMousePosition();
	}

	*frame_counter += *update ? 1 : 1 + -1; // stalls counter while update is off

	if (*auto_random && *frame_counter > (180 * FRAME_RATE)) { // 3 min
		random_grid(grid);
		*frame_counter = 0;
	}

	switch (*update) {
		case true: {
			if (*mouse) {
				update_grid(grid, mouse_pos);
				*mouse = false;
			}
			else if (!*mouse) update_grid(grid);
		} break;

		case false: {
			if (*mouse) update_grid_point(grid, mouse_pos); *mouse = false;
		} break;

		default: break;
	}

	ClearBackground(BACKGROUND_COLOR);

	for (int i {0}; i < ROLLS; i++) {
		for (int j {}; j < COLS; j++) {
			if (grid[i][j].cell.x <= SCREEN_WIDTH - int(CELL_SIZE / 2) && grid[i][j].cell.y <= SCREEN_HEIGHT - int(CELL_SIZE / 2)) {
				if (grid[i][j].is_alive()) {
					DrawRectangleRounded(grid[i][j].cell, 0.3, 4, CELL_COLOR);
				}
				if (*outline) DrawRectangleRoundedLines(grid[i][j].cell, 0.3, 4, LIGHTGRAY);
			}
		}
	}
}
