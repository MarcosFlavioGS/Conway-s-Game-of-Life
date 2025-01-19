#include "../include/raylib.h"
#include "../include/game.hpp"
#include "../include/grid.hpp"

int main(int argc, char *argv[]) {

   InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, NAME);
   SetTargetFPS(10);
   bool outline { true };

   Cell grid[ROLLS][COLS];

   init_grid(grid);

   while (!WindowShouldClose()) {

	   if (IsKeyReleased(KEY_R)) random_grid(grid);
	   else if (IsKeyReleased(KEY_C)) clear_grid(grid);
	   else if (IsKeyReleased(KEY_O)) outline ^= true;

	   update_grid(grid);

	   BeginDrawing();

	   ClearBackground(BACKGROUND_COLOR);

	   for (int i {0}; i < ROLLS; i++) {
		   for (int j {}; j < COLS; j++) {
			   if (grid[i][j].is_alive()) DrawRectangleRounded(grid[i][j].cell, 0.3, 4,CELL_COLOR);
			   if (outline) DrawRectangleRoundedLines(grid[i][j].cell, 0.3, 4, LIGHTGRAY);
		   }
	   }

	   EndDrawing();
   }

    return 0;
}
