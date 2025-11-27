#include "grid.h"

Grid::Grid(int cellSize, int rows, int cols) {
	this->cellSize = cellSize;
	this->rows = rows;
	this->cols = cols;

	this->WindowsLength = this->rows * this->cellSize;
	this->WindowsWidth = this->cols * this->cellSize;
}