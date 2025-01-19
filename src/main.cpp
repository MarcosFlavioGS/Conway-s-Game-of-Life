#include "../include/raylib.h"
#include "../include/game.hpp"
#include "../include/grid.hpp"

int main(int argc, char *argv[]) {

   InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, NAME);
   SetTargetFPS(10);

   Cell grid[ROLLS][COLS];

   init_grid(grid);

   while (!WindowShouldClose()) {

	   if (IsKeyReleased(KEY_R)) random_grid(grid);
	   else if (IsKeyReleased(KEY_C)) clear_grid(grid);

	   update_grid(grid);

	   BeginDrawing();

	   ClearBackground(BACKGROUND_COLOR);

	   for (int i {}; i < ROLLS; i++) {
		   for (int j {}; j < COLS; j++) {
			   if (grid[i][j].is_alive()) DrawRectangleRec(grid[i][j].cell, CELL_COLOR);
		   }
	   }

	   EndDrawing();
   }

    return 0;
}
