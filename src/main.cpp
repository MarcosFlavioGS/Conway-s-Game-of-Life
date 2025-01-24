#include "../include/raylib.h"
#include "../include/game.hpp"
#include "../include/grid.hpp"
#include "../include/title.hpp"
#include "../include/pause.hpp"
#include "../include/gameplay.hpp"

int main(int argc, char *argv[]) {

   InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, NAME);
   GameScreen current_screen { TITLE };

   int frame_counter { 0 };
   SetTargetFPS(FRAME_RATE);

   bool outline { false };
   bool update { false };
   bool auto_random { false };
   bool mouse { false };

    auto grid = std::make_unique<std::vector<std::vector<Cell>>>(ROLLS, std::vector<Cell>(COLS));

   Vector2 mouse_pos {};

   init_grid(grid.get());

   while (!WindowShouldClose()) {

	   switch (current_screen) {
		   case TITLE: {
			   frame_counter++;

			   if (frame_counter > (5 * FRAME_RATE)) {
				   current_screen = GAMEPLAY;
				   frame_counter = 0;
			   }
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
			   game(grid.get(), &outline, &update, &frame_counter, &auto_random, &mouse_pos, &mouse);
		   } break;

		   case PAUSE: {
			   pause_screen(&auto_random);
		   } break;

		   default: break;
	   }

	   EndDrawing();
   }

   CloseWindow();

   return 0;
}
