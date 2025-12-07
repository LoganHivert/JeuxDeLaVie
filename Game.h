#pragma once
#include"Cells.h"
#include "Grid.h"
const int MiniLawAlive = 2; // modifier le nombre mini de voisins pour la survie
const int MaxiLawAlive = 3; // modifier le nombre maxi de voisins pour la survie
const int MiniLawDead = 3; // modifier le nombre de voisins pour la naissance

class Grid;
class Game {
public:
	Game(Grid* g);
	Grid grid;
	std::vector<Cell> tempChange;
	void checkGrid();
	void LawAlive(int x, int y);
	void LawDead(int x, int y);
	void randomizeGrid();
	void play(int a);
};