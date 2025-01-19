#include "../../include/raylib.h"

void title_screen() {
	ClearBackground(DARKBLUE);
			   DrawText("This is the Game of Life !", 200, 200, 80, BLUE);
			   DrawText("In Game:", 200, 350, 50, WHITE);
			   DrawText("Press \"R\" to randomize cells", 220, 450, 50, WHITE);
			   DrawText("Press \"C\" to clear Grid", 220, 550, 50, WHITE);
			   DrawText("Press \"O\" to display outlines", 220, 650, 50, WHITE);
}
