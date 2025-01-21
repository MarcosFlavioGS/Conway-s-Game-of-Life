#pragma once

#include "raylib.h"

# define CELL_COLOR GREEN
# define CELL_SIZE 10

class Cell {
	public:
		Rectangle cell {};
		int alive {};

		float x_min {};
		float x_max {};
		float y_min {};
		float y_max {};
	public:
		Cell() {
			cell.x = 1;
			cell.y = 1;
			cell.height = CELL_SIZE;
			cell.width = CELL_SIZE;
		}

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
