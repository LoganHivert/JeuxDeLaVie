#pragma once
#include "Grid.h"

class Game {
public:
	Game(Grid* g);
	void checkGrid();
	void LawAlive(int x, int y);
	void LawDead(int x, int y);
private:
	Grid* grid;
};