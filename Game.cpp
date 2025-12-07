#include "Game.h"
#include "Grid.h"
#include "Constantes.h"
#include "UI.h"
#include <SFML/Graphics.hpp>


Game::Game(){
}

void Game::checkGrid(Grid* grid) {
	for (int i = 0; i < grid->rows; ++i) {
		for (int j = 0; j < grid->cols; ++j) {
			if (grid->cells[i][j].alive) {
				LawAlive(i, j, grid);
			}
			else {
				LawDead(i, j, grid);
			}
		}
	}
	for (int i = 0; i < tempChange.size(); ++i) {
		int x = tempChange[i].getPosX();
		int y = tempChange[i].getPosY();
		grid->cells[x][y].alive = tempChange[i].alive;
	}
	tempChange.clear();
	return;
}

void Game::LawAlive(int x, int y, Grid* grid) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive >= MiniLawAlive && nbAlive <= MaxiLawAlive) {
		return;
	}
	else {
		tempChange.emplace_back(x, y, 0);
		return;
	}
}

void Game::LawDead(int x, int y, Grid* grid) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive == MiniLawDead) {
		tempChange.emplace_back(x, y, 1);
		return;
	}
	else {
		return;
	}
}

void Game::randomizeGrid(Grid* grid) {
	for (int i = 0; i < grid->rows; ++i) {
		for (int j = 0; j < grid->cols; ++j) {
			grid->cells[i][j].alive=std::rand() % 2;
		}
	}
}

void Game::play(int a, Grid* grid) {
    for (int i = 0; i < a; ++i) {
        this->checkGrid(grid);
    }
}

void Game::setSpeed(float coef) {
	this->speed *= coef;
	return;
}

int Game::getSpeed() {
	return this->speed;
}