#include "../include/raylib.h"
#include "../include/game.hpp"
#include "../include/grid.hpp"
#include "../include/title.hpp"
#include "../include/pause.hpp"
#include "../include/gameplay.hpp"

using namespace std;

int main(int argc, char *argv[]) {

   InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, NAME);
   GameScreen current_screen { TITLE };

   int frame_counter {};
   SetTargetFPS(FRAME_RATE);

   bool outline {};
   bool update {};
   bool auto_random {};
   bool mouse {};

   auto grid = make_unique<vector<vector<Cell>>>(ROLLS, vector<Cell>(COLS));

   Vector2 mouse_pos {};

   init_grid(grid.get());

   while (!WindowShouldClose()) {

	   switch (current_screen) {
		   case TITLE: {
			   frame_counter++;

			   if (frame_counter > (5 * FRAME_RATE)) { // Wait 5 seconds in title screen
				   current_screen = GAMEPLAY;
				   frame_counter = 0;
			   }
		   } break;

		   case GAMEPLAY: {
			   if (IsKeyPressed(KEY_TAB)) current_screen = PAUSE;
		   } break;

		   case PAUSE: {
			  if (IsKeyPressed(KEY_TAB) || IsKeyReleased(KEY_ENTER)) current_screen = GAMEPLAY; 
		   } break;

		   default: break;
	   }

	   BeginDrawing();

	   switch (current_screen) {
		   case TITLE: {
			   title_screen();
		   } break;

		   case GAMEPLAY: {
			   game(
				   grid.get(),
				   &outline,
				   &update,
				   &frame_counter,
				   &auto_random,
				   &mouse_pos,
				   &mouse);
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
