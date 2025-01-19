#pragma once

#include "raylib.h"
#include <iostream>

# define CELL_COLOR GREEN
# define CELL_SIZE 15

class Cell {
	public:
		Rectangle cell {};
		int alive {};
	public:
		Cell() {
			cell.x = 1;
			cell.y = 1;
			cell.height = CELL_SIZE;
			cell.width = CELL_SIZE;
		}

		Cell(Rectangle rec) {
			cell = rec;
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
};
