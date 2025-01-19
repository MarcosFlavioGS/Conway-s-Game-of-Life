#include "../include/raylib.h"
#include "../include/game.hpp"
#include "../include/grid.hpp"
#include "../include/title.hpp"
#include "../include/pause.hpp"

int main(int argc, char *argv[]) {

   InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, NAME);
   GameScreen current_screen { TITLE };

   int frame_counter { 0 };
   SetTargetFPS(10);

   bool outline { true };

   Cell grid[ROLLS][COLS];

   init_grid(grid);

   while (!WindowShouldClose()) {

	   switch (current_screen) {
		   case TITLE: {
			   frame_counter++;

			   if (frame_counter > 50) current_screen = GAMEPLAY;
		   } break;

		   case GAMEPLAY: {
			   if (IsKeyReleased(KEY_TAB)) current_screen = PAUSE;
		   } break;

		   case PAUSE: {
			  if (IsKeyReleased(KEY_TAB) || IsKeyReleased(KEY_ENTER)) current_screen = GAMEPLAY; 
		   } break;

		   default: break;
	   }

	   BeginDrawing();

	   switch (current_screen) {
		   case TITLE: {
			   title_screen();
		   } break;

		   case GAMEPLAY: {
			   if (IsKeyReleased(KEY_R)) random_grid(grid);
			   else if (IsKeyReleased(KEY_C)) clear_grid(grid);
			   else if (IsKeyReleased(KEY_O)) outline ^= true;
			   
			   update_grid(grid);

			   ClearBackground(BACKGROUND_COLOR);

			   for (int i {0}; i < ROLLS; i++) {
				   for (int j {}; j < COLS; j++) {
					   if (grid[i][j].is_alive()) DrawRectangleRounded(grid[i][j].cell, 0.3, 4, CELL_COLOR);
					   if (outline) DrawRectangleRoundedLines(grid[i][j].cell, 0.3, 4, LIGHTGRAY);
				   }
			   }
			   
		   } break;

		   case PAUSE: {
			   pause_screen();
		   } break;

		   default: break;
	   }

	   EndDrawing();
   }

   CloseWindow();

   return 0;
}
