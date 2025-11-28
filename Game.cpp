#include "Game.h"

Laws::Laws(Grid* g) : grid(g) {}

void Laws::LawAlive(int x, int y) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive == 3 || nbAlive == 2) {
		return;
	}
	else {
		grid->cells[x][y].alive = false;
		return;
	}
}

void Laws::LawDead(int x, int y) {
	int nbAlive = grid->getVoisinage(x, y);
	if (nbAlive == 3) {
		grid->cells[x][y].alive = true;
		return;
	}
	else {
		return;
	}
}