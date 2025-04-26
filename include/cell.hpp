#pragma once

#include "raylib.h"

# define CELL_COLOR GREEN
# define CELL_SIZE 15

class Cell {
	public:
		Rectangle cell {};
		int alive {};

		float x_min {};
		float x_max {};
		float y_min {};
		float y_max {};
	public:
		Cell(int i, int j) {
			// Set the position and dimensions of the rectangle
			cell.x = j * (CELL_SIZE + 3);
			cell.y = i * (CELL_SIZE + 3);
			cell.width = CELL_SIZE;
			cell.height = CELL_SIZE;

			// Calculate boundaries
			x_min = cell.x;
			y_min = cell.y + CELL_SIZE - 1;
			x_max = cell.x + CELL_SIZE - 1;
			y_max = cell.y;
		}

		Cell() {}

		bool is_alive() {
			return alive;
		}

		void rise_my_child() {
			alive = 1;
		}

		void die_now() {
			alive = 0;
		}

		bool is_inside(Vector2* point) {
			return (x_min <= point->x && point->x <= x_max) && (y_min >= point->y && point->y >= y_max);
		}
};
