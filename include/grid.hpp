#pragma once

#include "cell.hpp"
#include "game.hpp"

# define ROLLS SCREEN_HEIGTH / CELL_SIZE + 3
# define COLS SCREEN_WIDTH / CELL_SIZE + 3

void init_grid(Cell grid[][COLS]);
void random_grid(Cell grid[][COLS]);
void clear_grid(Cell grid[][COLS]);
void update_grid(Cell grid[][COLS]);
