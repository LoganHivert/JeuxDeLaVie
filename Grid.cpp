#include "grid.h"

Grid::Grid(int cellSize, int rows, int cols) {
	this->cellSize = cellSize;
	this->rows = rows;
	this->cols = cols;
	std::vector<std::vector<Cell>>;
	for (int i = 1; i < (this->rows * this->cols); i++) {

	}

	this->WindowsLength = this->rows * this->cellSize;
	this->WindowsWidth = this->cols * this->cellSize;
}