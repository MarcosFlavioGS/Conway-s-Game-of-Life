#pragma once

#include "cell.hpp"
#include "game.hpp"

# define ROLLS (SCREEN_HEIGTH / CELL_SIZE)
# define COLS (SCREEN_WIDTH / CELL_SIZE)

void init_grid(Cell grid[][COLS]);
void random_grid(Cell grid[][COLS]);
void clear_grid(Cell grid[][COLS]);
void update_grid(Cell grid[][COLS]);
