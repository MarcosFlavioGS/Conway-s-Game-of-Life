#include "../../include/raylib.h"

void pause_screen() {
	ClearBackground(DARKBLUE);
	DrawText("GAME PAUSED !", 200, 200, 80, BLUE);
	DrawText("Press ENTER to go back to the fun part !", 100, 450, 50, WHITE);
}

