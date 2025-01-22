#include "../../include/cell.hpp"
#include "../../include/grid.hpp"

/**
 * Initialize the grid
*/
void init_grid(std::vector<std::vector<Cell>>* grid) {
    for (int i = 0; i < ROLLS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            (*grid)[i][j] = Cell(i, j);
        }
    }
}
