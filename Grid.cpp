#include "grid.h"
#include "Cells.h"

Grid::Grid() {

	for (int y = 0; y < ROWS; ++y) {
		std::vector<Cell> row;
		for (int x = 0; x < COLS; ++x) {
			row.emplace_back(x, y, 0);
		}
		cells.push_back(std::move(row));
	}

	this->WindowsLength = ROWS * CELL_SIZE;
	this->WindowsWidth = COLS * CELL_SIZE;
}

int Grid::getVoisinage(int x, int y) {
	int nbAlive = 0;
	nbAlive += getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, y + 1) + getCell(x, y - 1) + getCell(x, y + 1) + getCell(x + 1, y - 1) + getCell(x + 1, y) + getCell(x + 1, y + 1);
	return nbAlive;
}

int Grid::getCell(int x, int y) {
	if (x < 0 || y < 0 || x >= ROWS || y >= COLS) return 0;
	return cells[x][y].alive;
}