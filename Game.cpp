#include "Game.h"
#include "Grid.h"
#include "UI.h"


Game::Game(Grid* g) : grid(g) {}

void Game::checkGrid() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (grid->cells[i][j].alive) {
				LawAlive(i, j);
			}
			else {
				LawDead(i, j);
			}
		}
	}
	for (int i = 0; i < tempChange.size(); ++i) {
		grid->cells[tempChange[i].getPosX()][tempChange[i].getPosY()].alive = tempChange[i].alive;
	}
	tempChange.clear();
	return;
}

void Game::LawAlive(int x, int y) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive >= MiniLawAlive && nbAlive <= MaxiLawAlive) {
		return;
	}
	else {
		tempChange.emplace_back(x, y, 0);
		return;
	}
}

void Game::LawDead(int x, int y) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive == MiniLawDead) {
		tempChange.emplace_back(x, y, 1);
		return;
	}
	else {
		return;
	}
}

void Game::launchGame() {
	this-> grid = new Grid();
	Console console(this);
	std::cout << "Mode de lancement:" << std::endl;
	std::cout << "1: Console" << std::endl;
	std::cout << "2: UI" << std::endl;
	int choix;
	std::cin >> choix;
	switch (choix) {
	case 1:
		while (1)
		{
			console.menu();
		}
		break;
	case 2:
		UI ui;
		ui.Windows();
	}
	delete this->grid;
	this->grid = nullptr;
}

void Game::randomizeGrid() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			grid->cells[i][j].alive=std::rand() % 2;
		}
	}
}