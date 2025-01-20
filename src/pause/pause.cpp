#include "../../include/raylib.h"

void pause_screen(bool* auto_random) {
	if (IsKeyPressed(KEY_U)) *auto_random ^= true;

	const char* auto_random_msg {*auto_random ? "Enabled": "Disabled"};
	const Color color {*auto_random ? GREEN : RED};

	ClearBackground(DARKBLUE);
	DrawText("GAME PAUSED !", 200, 200, 80, BLUE);
	DrawText("Press ENTER to go back to the fun part !", 100, 450, 50, WHITE);

	DrawText("Auto random: ", 100, 550, 50, WHITE);
	DrawText(auto_random_msg, 450, 550, 50, color);
	DrawText("(\"U\")", 750, 550, 50, WHITE);
}

