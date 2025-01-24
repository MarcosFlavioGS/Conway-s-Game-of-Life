#include "../../include/grid.hpp"

using namespace std;

static int check_neighbors(const vector<vector<Cell>>* g, int i, int j) {
    int neighbor_sum = 0;

    for (int di = -1; di <= 1; ++di) {        // Loop over rows around the cell
        for (int dj = -1; dj <= 1; ++dj) {    // Loop over columns around the cell
            if (di == 0 && dj == 0) {
                continue; // Skip the cell itself
            }

            int ni = i + di; // Neighbor row index
            int nj = j + dj; // Neighbor column index

            // Check if the neighbor is within bounds
            if (ni >= 0 && ni < ROLLS && nj >= 0 && nj < COLS) {
                neighbor_sum += (*g)[ni][nj].alive; // Add alive status of valid neighbors
            }
        }
    }

    return neighbor_sum;
}

void update_grid(vector<vector<Cell>>* grid) {
    auto new_grid = make_unique<vector<vector<Cell>>>(ROLLS, vector<Cell>(COLS));
	init_grid(new_grid.get());

    for (int i {}; i < ROLLS; i++) {
        for (int j {}; j < COLS; j++) {
            int alive = (*grid)[i][j].is_alive();
            int score = check_neighbors(grid, i, j);

            switch (alive) {
                case true: {
                    if (score < 2 || score > 3) {
                        (*new_grid)[i][j].die_now();
                    } else {
                        (*new_grid)[i][j].rise_my_child();
                    }
                } break;
                default: {
                    if (score == 3) {
                        (*new_grid)[i][j].rise_my_child();
                    } else {
                        (*new_grid)[i][j].die_now();
                    }
                }
            };
        }
    }
	*grid = std::move(*new_grid);
}

void update_grid(vector<vector<Cell>>* grid, Vector2* mouse_pos) {
    auto new_grid = make_unique<vector<vector<Cell>>>(ROLLS, vector<Cell>(COLS));
	init_grid(new_grid.get());


	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {

		   bool clicked {(*grid)[i][j].is_inside(mouse_pos)};

		   int alive {(*grid)[i][j].is_alive()};
		   int score {check_neighbors(grid, i, j)};

		   switch (alive) {
			   case true: {

				   if (score < 2 || score > 3) {
					   if (clicked) (*new_grid)[i][j].rise_my_child();
					   else (*new_grid)[i][j].die_now();
				   } else {
					   (*new_grid)[i][j].rise_my_child();
				   }
			   } break;
			   default: {
				   if (score == 3) {
					   (*new_grid)[i][j].rise_my_child();
				   } else {
					   if (clicked) (*new_grid)[i][j].rise_my_child();
					   else (*new_grid)[i][j].die_now();
				   }
			   }
		   };
	   } 
	}
	*grid = std::move(*new_grid);
}

void update_grid_point(vector<vector<Cell>>* grid, Vector2* mouse) {
    auto new_grid = make_unique<vector<vector<Cell>>>(ROLLS, vector<Cell>(COLS));
	init_grid(new_grid.get());

	for (int i {}; i < ROLLS; i++) {
	   for (int j {}; j < COLS; j++) {

		   if ((*grid)[i][j].is_inside(mouse)) {
			   (*new_grid)[i][j].rise_my_child();
		   } else {
			   (*new_grid)[i][j].alive = (*grid)[i][j].alive;
		   }
	   } 
	}
	*grid = std::move(*new_grid);
}
