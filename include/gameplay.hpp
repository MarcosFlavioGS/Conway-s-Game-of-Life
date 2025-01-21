#pragma once

#include "grid.hpp"
#include "raylib.h"

void game(Cell grid[][COLS], bool* outline, bool* update, int* frame_counter, bool* auto_random, Vector2* mouse_pos);
