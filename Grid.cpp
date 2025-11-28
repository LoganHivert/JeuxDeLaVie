#include "grid.h"

Grid::Grid(int cellSize, int rows, int cols) {
	this->cellSize = cellSize;
	this->rows = rows;
	this->cols = cols;
	for (int i = 0; i < rows; ++i) {
		std::vector<Cell> row;
		for (int j = 0; j < cols; ++j) {
			row.emplace_back(i, j);
		}
		cells.push_back(std::move(row));
	}

	this->WindowsLength = this->rows * this->cellSize;
	this->WindowsWidth = this->cols * this->cellSize;
}

int Grid::getVoisinage(int x, int y) {
	int nbAlive = 0;
	nbAlive += getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, y + 1) + getCell(x, y - 1) + getCell(x, y + 1) + getCell(x + 1, y - 1) + getCell(x + 1, y) + getCell(x + 1, y + 1);
	return 1;
}

int Grid::getCell(int x, int y){
	if (cells[x][y].alive) {
		return 1;
	}
	else {
		return 0;
	}
}