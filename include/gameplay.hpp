#pragma once

#include "grid.hpp"
#include "raylib.h"

void game(std::vector<std::vector<Cell>>* grid,
		  bool* outline,
		  bool* update,
		  int* frame_counter,
		  bool* auto_random,
		  Vector2* mouse_pos,
		  bool* mouse
);
