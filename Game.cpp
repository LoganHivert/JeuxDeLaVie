#include "Game.h"
#include "Grid.h"

#include "UI.h"
#include <SFML/Graphics.hpp>


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
		int x = tempChange[i].getPosX();
		int y = tempChange[i].getPosY();
		grid->cells[x][y].alive = tempChange[i].alive;
		if (tempChange[i].alive) {
			grid->cells[x][y].shape.setFillColor(sf::Color::White);
		}
		else {
			grid->cells[x][y].shape.setFillColor(sf::Color::Black);
		}
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

void Game::randomizeGrid() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			grid->cells[i][j].alive=std::rand() % 2;
		}
	}
}

void Game::play(int a) {
    if (!this->grid) {
        std::cerr << "Pas de grille disponible pour jouer !" << std::endl;
        return;
    }
    for (int i = 0; i < a; ++i) {
        this->checkGrid();
    }
}

