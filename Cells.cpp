#include "Cells.h"

Cell::Cell(int _x, int _y) {
	this->x = _x;
	this->y = _y;
	this->alive = 0;
}

int Cell::getPosX(){
	return (this->x * CELL_SIZE);
}

int Cell::getPosY() {
	return (this->y * CELL_SIZE);
}