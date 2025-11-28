#pragma once
#include "Grid.h"

class Game {
public:
	Game();
	void playGame();

};

class Laws {
public:
	Laws(Grid* g);
	void LawAlive(int x, int y);
	void LawDead(int x, int y);
private:
	Grid* grid;
};