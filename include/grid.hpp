#pragma once

#include "cell.hpp"
#include "game.hpp"
#include "raylib.h"

# define ROLLS (SCREEN_HEIGHT / CELL_SIZE)
# define COLS (SCREEN_WIDTH / CELL_SIZE)

void init_grid(std::vector<std::vector<Cell>>* grid);
void random_grid(std::vector<std::vector<Cell>>* grid);
void clear_grid(std::vector<std::vector<Cell>>* grid);
void update_grid(std::vector<std::vector<Cell>>* grid);
void update_grid(std::vector<std::vector<Cell>>* grid, Vector2* mouse_pos);
void update_grid_point(std::vector<std::vector<Cell>>* grid, Vector2* mouse);
