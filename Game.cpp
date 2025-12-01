#include "Game.h"
#include "Grid.h"

Game::Game(Grid* g) : grid(g) {}

void Game::checkGrid() {
	for (int i = 0; i < grid->rows; ++i) {
		for (int j = 0; j < grid->cols; ++j) {
			if (grid->cells[i][j].alive) {
				LawAlive(i, j);
			}
			else {
				LawDead(i, j);
			}
		}
	}
	return;
}

void Game::LawAlive(int x, int y) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive == 3 || nbAlive == 2) {
		return;
	}
	else {
		grid->cells[x][y].alive = 0;
		return;
	}
}

void Game::LawDead(int x, int y) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive == 3) {
		grid->cells[x][y].alive = 1;
		return;
	}
	else {
		return;
	}
}

void Game::launchGame() {
	this-> grid = new Grid(100, 100);
	Console console(this);
	while (1)
	{
		console.menu();
	}
	delete this->grid;
	this->grid = nullptr;
}