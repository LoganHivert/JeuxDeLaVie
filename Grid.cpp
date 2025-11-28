#include "grid.h"

Grid::Grid(int cellSize, int rows, int cols) {
	this->cellSize = cellSize;
	this->rows = rows;
	this->cols = cols;

	this->WindowsLength = this->rows * this->cellSize;
	this->WindowsWidth = this->cols * this->cellSize;
}

int Grid::getVoisinage(int x, int y) {
	int nbAlive = 0;
	nbAlive += getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, y + 1) + getCell(x, y - 1) + getCell(x, y + 1) + getCell(x + 1, y - 1) + getCell(x + 1, y) + getCell(x + 1, y + 1);

}

int Grid::getCell(int x, int y){
	//sortir la cellule correspondant aux coordonnées du tableau
	//si vivante return 1
	//else return 0
}