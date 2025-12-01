#pragma once
#include "Grid.h"
#include "Console.h"

class Grid;
class Game {
public:
	Game(Grid* g);
	std::vector<Cell> tempChange;
	void checkGrid();
	void LawAlive(int x, int y);
	void LawDead(int x, int y);
	void launchGame();
	Grid* grid;
};