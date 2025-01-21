#pragma once

#include "cell.hpp"
#include "game.hpp"
#include "raylib.h"

# define ROLLS (SCREEN_HEIGHT / CELL_SIZE)
# define COLS (SCREEN_WIDTH / CELL_SIZE)

void init_grid(Cell grid[][COLS]);
void random_grid(Cell grid[][COLS]);
void clear_grid(Cell grid[][COLS]);
void update_grid(Cell grid[][COLS]);
void update_grid(Cell grid[][COLS], Vector2* mouse_pos);
void update_grid_point(Cell grid[][COLS], Vector2* mouse);
