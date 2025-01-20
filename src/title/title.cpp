#include "../../include/raylib.h"

void title_screen() {
	ClearBackground(DARKBLUE);
			   DrawText("This is the Game of Life !", 200, 200, 80, BLUE);
			   DrawText("In Game:", 200, 350, 40, WHITE);
			   DrawText("Press \"R\" to randomize cells", 220, 400, 40, WHITE);
			   DrawText("Press \"C\" to clear Grid", 220, 440, 40, WHITE);
			   DrawText("Press \"O\" to display outlines", 220, 480, 40, WHITE);
			   DrawText("Press \"SPACE\" play and stop simulation", 220, 520, 40, WHITE);
			   DrawText("Press \"U\" Disable/Enable auto randomize", 220, 540, 40, WHITE);
}
