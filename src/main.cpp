#include "../include/raylib.h"
#include "../include/game.hpp"
#include "../include/grid.hpp"
#include "../include/title.hpp"
#include "../include/pause.hpp"
#include "../include/gameplay.hpp"

int main(int argc, char *argv[]) {

   InitWindow(SCREEN_WIDTH, SCREEN_HEIGTH, NAME);
   GameScreen current_screen { TITLE };

   int frame_counter { 0 };
   SetTargetFPS(10);

   bool outline { false };
   bool update { false };

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
			   game(grid, &outline, &update);
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
