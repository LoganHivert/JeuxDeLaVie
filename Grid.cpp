#include "grid.h"
#include "Cells.h"

Grid::Grid(int rows, int cols) {

	this->rows = rows;
	this->cols = cols;

	this->cellGraph.reserve(this->rows * this->cols);
	for (int y = 0; y < rows; ++y) {
		std::vector<Cell> row;
		for (int x = 0; x < cols; ++x) {
			row.emplace_back(x, y);
			sf::RectangleShape shape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
			shape.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
			shape.setFillColor(sf::Color::Black); // cellule morte
			shape.setOutlineThickness(1);
			shape.setOutlineColor(sf::Color(150, 150, 150));
			this->cellGraph.push_back(shape);
		}
		cells.push_back(std::move(row));
	}

	this->WindowsLength = this->rows * CELL_SIZE;
	this->WindowsWidth = this->cols * CELL_SIZE;
}

int Grid::getVoisinage(int x, int y) {
	int nbAlive = 0;
	nbAlive += getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, y + 1) + getCell(x, y - 1) + getCell(x, y + 1) + getCell(x + 1, y - 1) + getCell(x + 1, y) + getCell(x + 1, y + 1);
	return nbAlive;
}

int Grid::getCell(int x, int y) {
	if (x < 0 || y < 0 || x >= rows || y >= cols) return 0;
	return cells[x][y].alive;
}